# LoadTCHAR function

The **LoadTCHAR** function is called by monitors to set a string variable to a string taken from an HTML configuration string.

## Parameters

*pConfig* \[in\]

Pointer to the HTML configuration string passed to the monitor by the [IMonitor::DoConfigure](https://learn.microsoft.com/windows/win32/netmon2/imonitor-doconfigure) method.

*pVarName* \[in\]

Pointer to the name of the variable in the configuration string.

*ppszString* \[out\]

Pointer to a string pointer. If the requested variable name is found, the string is allocated and assigned to this pointer. It is the user's responsibly to free the memory associated with the string.

## Return value

If the function is successful (if the variable name was found and had a non-zero-length string), the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

