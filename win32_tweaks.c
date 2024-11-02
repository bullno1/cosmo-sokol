#include "win32_tweaks.h"
#include <windowsesque.h>

void
win32_tweaks_hide_console(void) {
	HMODULE kernel32 = LoadLibraryA("kernel32.dll");
	if (kernel32 == NULL) { return; }

	DWORD WINAPI (*GetConsoleProcessList)(LPDWORD lpdwProcessList,  DWORD   dwProcessCount) = GetProcAddress(kernel32, "GetConsoleProcessList");
	if (GetConsoleProcessList == NULL) { return; }

	DWORD pids[2];
	DWORD num_procs = GetConsoleProcessList(pids, 2);
	if (num_procs <= 1) {
		FreeConsole();
	}
}
