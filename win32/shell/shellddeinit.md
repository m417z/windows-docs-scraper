# ShellDDEInit function

Registers the Shell Dynamic Data Exchange (DDE) services in the current process, notifying the system that the current process wishes to host DDE objects.

## Parameters

*init* \[in\]

Type: **BOOL**

**TRUE** to register the current process as DDE host; **FALSE** to unregister it.

## Return value

This function does not return a value.

## Remarks

The process that calls this function acts as the Shell and is used to view the content of folders opened with the [**ShellExecute**](https://learn.microsoft.com/windows/desktop/api/Shellapi/nf-shellapi-shellexecutea) 'open' verb.

This function does not have an associated header or library file so it must be called by ordinal value. Call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (Shdocvw.dll) to obtain a module handle. Then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with that module handle and the function ordinal number 118 to get the address of the function.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP, Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Shdocvw.dll (version 6.0 or later) |

