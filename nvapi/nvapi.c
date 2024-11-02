#include "nvapi.h"
#include "nvapi_decl.h"
#include <windowsesque.h>
#include <cosmo.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <libc/x/x.h>

#define NVAPI_CHECK(OP) \
	do { \
		int status = OP; \
		if (status != 0) { \
			NvAPI_ShortString err_msg = { 0 }; \
			NvAPI_GetErrorMessage(status, err_msg); \
			fprintf(stderr, "%s failed: %s (code %d)", #OP, err_msg, status); \
			goto end; \
		} \
	} while (0)

static const int OGL_THREAD_CONTROL_ID = 0x20C1221E;
static const int OGL_THREAD_CONTROL_DISABLE = 0x00000002;
static const int OGL_THREAD_CONTROL_ENABLE = 0x00000001;

typedef WINAPI int(*NvAPI_Initialize_t)(void);
typedef WINAPI int(*NvAPI_Unload_t)(void);
typedef WINAPI int(*NvAPI_GetErrorMessage_t)(unsigned int, NvAPI_ShortString);
typedef WINAPI int(*NvAPI_DRS_CreateSession_t)(NvDRSSessionHandle *);
typedef WINAPI int(*NvAPI_DRS_DestroySession_t)(NvDRSSessionHandle);
typedef WINAPI int(*NvAPI_DRS_LoadSettings_t)(NvDRSSessionHandle);
typedef WINAPI int(*NvAPI_DRS_CreateProfile_t)(NvDRSSessionHandle, NVDRS_PROFILE *, NvDRSProfileHandle *);
typedef WINAPI int(*NvAPI_DRS_CreateApplication_t)(NvDRSSessionHandle, NvDRSProfileHandle, NVDRS_APPLICATION *);
typedef WINAPI int(*NvAPI_DRS_SaveSettings_t)(NvDRSSessionHandle);
typedef WINAPI int(*NvAPI_DRS_SetSetting_t)(NvDRSSessionHandle, NvDRSProfileHandle, NVDRS_SETTING *);
typedef WINAPI int(*NvAPI_DRS_FindProfileByName_t)(NvDRSSessionHandle, NvAPI_UnicodeString, NvDRSProfileHandle *);
typedef WINAPI int(*NvAPI_DRS_GetApplicationInfo_t)(NvDRSSessionHandle, NvDRSProfileHandle, NvAPI_UnicodeString, NVDRS_APPLICATION *);
typedef WINAPI int(*NvAPI_DRS_DeleteProfile_t)(NvDRSSessionHandle, NvDRSProfileHandle);
typedef WINAPI void*(*NvAPI_QueryInterface_t)(unsigned int);

bool
nvapi_disable_threaded_optimization(const char* profile_name) {
	if (!IsWindows()) { return false; }

	HMODULE nvapi = LoadLibraryA("nvapi64.dll");
	if (nvapi == NULL) { return false; }

	size_t profile_name_utf16_len;
	char16_t* profile_name_utf16 = utf8to16(profile_name, -1, &profile_name_utf16_len);
	char16_t module_path[PATH_MAX];
	bool success = false;
	bool initialized = false;
	NvDRSSessionHandle session_handle = NULL;

	NvAPI_QueryInterface_t NvAPI_QueryInterface = (void *)GetProcAddress(nvapi, "nvapi_QueryInterface");
	NvAPI_Initialize_t NvAPI_Initialize = (NvAPI_Initialize_t)NvAPI_QueryInterface(0x0150E828);
	NvAPI_GetErrorMessage_t NvAPI_GetErrorMessage = (NvAPI_GetErrorMessage_t)NvAPI_QueryInterface(0x6C2D048C);
	NvAPI_DRS_CreateSession_t NvAPI_DRS_CreateSession = (NvAPI_DRS_CreateSession_t)NvAPI_QueryInterface(0x0694D52E);
	NvAPI_DRS_DestroySession_t NvAPI_DRS_DestroySession = (NvAPI_DRS_DestroySession_t)NvAPI_QueryInterface(0xDAD9CFF8);
	NvAPI_Unload_t NvAPI_Unload = (NvAPI_Unload_t)NvAPI_QueryInterface(0xD22BDD7E);
	NvAPI_DRS_LoadSettings_t NvAPI_DRS_LoadSettings = (NvAPI_DRS_LoadSettings_t)NvAPI_QueryInterface(0x375DBD6B);
	NvAPI_DRS_CreateProfile_t NvAPI_DRS_CreateProfile = (NvAPI_DRS_CreateProfile_t)NvAPI_QueryInterface(0xCC176068);
	NvAPI_DRS_CreateApplication_t NvAPI_DRS_CreateApplication = (NvAPI_DRS_CreateApplication_t)NvAPI_QueryInterface(0x4347A9DE);
	NvAPI_DRS_SaveSettings_t NvAPI_DRS_SaveSettings = (NvAPI_DRS_SaveSettings_t)NvAPI_QueryInterface(0xFCBC7E14);
	NvAPI_DRS_SetSetting_t NvAPI_DRS_SetSetting = (NvAPI_DRS_SetSetting_t)NvAPI_QueryInterface(0x577DD202);
	NvAPI_DRS_FindProfileByName_t NvAPI_DRS_FindProfileByName = (NvAPI_DRS_FindProfileByName_t)NvAPI_QueryInterface(0x7E4A9A0B);
	NvAPI_DRS_GetApplicationInfo_t NvAPI_DRS_GetApplicationInfo = (NvAPI_DRS_GetApplicationInfo_t)NvAPI_QueryInterface(0xED1F8C69);
	/*NvAPI_DRS_DeleteProfile_t NvAPI_DRS_DeleteProfile = (NvAPI_DRS_DeleteProfile_t)NvAPI_QueryInterface(0x17093206);*/

	NVAPI_CHECK(NvAPI_Initialize());
	initialized = true;

	NVAPI_CHECK(NvAPI_DRS_CreateSession(&session_handle));
	NVAPI_CHECK(NvAPI_DRS_LoadSettings(session_handle));

	NvDRSProfileHandle profile_handle;
	if (NvAPI_DRS_FindProfileByName(session_handle, profile_name_utf16, &profile_handle) != 0) {
		NVDRS_PROFILE profile_info = {
			.version = NVDRS_PROFILE_VER,
			.isPredefined = 0,
		};
		memcpy(profile_info.profileName, profile_name_utf16, sizeof(char16_t) * profile_name_utf16_len);

		NVAPI_CHECK(NvAPI_DRS_CreateProfile(session_handle, &profile_info, &profile_handle));
	}

	uint32_t module_path_len = GetModuleFileName(NULL, module_path, PATH_MAX);
	NVDRS_APPLICATION_V4 app;
	if (NvAPI_DRS_GetApplicationInfo(session_handle, profile_handle, module_path, &app) != 0) {
		app = (NVDRS_APPLICATION_V4) {
			.version = NVDRS_APPLICATION_VER,
			.isPredefined = 0,
		};
		memcpy(app.appName, module_path, sizeof(char16_t) * module_path_len);
		NVAPI_CHECK(NvAPI_DRS_CreateApplication(session_handle, profile_handle, &app));
	}

	NVDRS_SETTING setting = {
		.version = NVDRS_SETTING_VER,
		.settingId = OGL_THREAD_CONTROL_ID,
		.settingType = NVDRS_DWORD_TYPE,
		.settingLocation = NVDRS_CURRENT_PROFILE_LOCATION,
		.u32CurrentValue = OGL_THREAD_CONTROL_DISABLE,
		.u32PredefinedValue = OGL_THREAD_CONTROL_DISABLE,
	};
	NVAPI_CHECK(NvAPI_DRS_SetSetting(session_handle, profile_handle, &setting));
	NVAPI_CHECK(NvAPI_DRS_SaveSettings(session_handle));

	success = true;

end:
	if (session_handle) { NvAPI_DRS_DestroySession(session_handle); }
	if (initialized) { NvAPI_Unload(); }
	if (profile_name_utf16) { free(profile_name_utf16); }
	if (nvapi) { FreeLibrary(nvapi); }

	return success;
}
