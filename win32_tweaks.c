#include "win32_tweaks.h"
#include <windowsesque.h>

typedef DWORD WINAPI (*lpGetConsoleProcessList)(LPDWORD lpdwProcessList, DWORD dwProcessCount);

void
win32_tweaks_hide_console(void) {
	HMODULE kernel32 = LoadLibraryA("kernel32.dll");
	if (kernel32 == NULL) { return; }

	lpGetConsoleProcessList GetConsoleProcessList = (lpGetConsoleProcessList)GetProcAddress(kernel32, "GetConsoleProcessList");
	if (GetConsoleProcessList == NULL) { return; }

	DWORD pids[2];
	DWORD num_procs = GetConsoleProcessList(pids, 2);
	if (num_procs <= 1) {
		FreeConsole();
	}
}
