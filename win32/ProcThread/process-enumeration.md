# Process Enumeration

All users have read access to the list of processes in the system and there are a number of different functions that enumerate the active processes. The function you should use will depend on factors such as desired platform support.

The following functions are used to enumerate processes.

| Function | Description |
|-------------------------------------------------------------|------------------------------------------------------------------------------------|
| [**EnumProcesses**](https://learn.microsoft.com/windows/win32/api/psapi/nf-psapi-enumprocesses) | Retrieves the process identifier for each process object in the system. |
| [**Process32First**](https://learn.microsoft.com/windows/win32/api/tlhelp32/nf-tlhelp32-process32first) | Retrieves information about the first process encountered in a system snapshot. |
| [**Process32Next**](https://learn.microsoft.com/windows/win32/api/tlhelp32/nf-tlhelp32-process32next) | Retrieves information about the next process recorded in a system snapshot. |
| [**WTSEnumerateProcesses**](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesa) | Retrieves information about the active processes on the specified terminal server. |

The toolhelp functions and [**EnumProcesses**](https://learn.microsoft.com/windows/win32/api/psapi/nf-psapi-enumprocesses) enumerate all process. To list the processes that are running in a specific user account, use [**WTSEnumerateProcesses**](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesa) and filter on the user SID. You can filter on the session ID to hide processes running in other terminal server sessions.

You can also filter processes by user account, regardless of the enumeration function, by calling [**OpenProcess**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess), [**OpenProcessToken**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), and [**GetTokenInformation**](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) with **TokenUser**. However, you cannot open a process that is protected by a security descriptor unless you have been granted access.

