# LoadDWORD function

The **LoadDWORD** function is called by the monitor to set a **DWORD** variable with a value taken from an HTML configuration string variable.

## Parameters

*pConfig* \[in\]

Pointer to the HTML configuration string passed to the monitor by the [IMonitor::DoConfigure](https://learn.microsoft.com/windows/win32/netmon2/imonitor-doconfigure) method.

*pVarName* \[in\]

Pointer to the name of the variable in the configuration string.

*pValue* \[in\]

Pointer to the **DWORD** variable that is set to the value of the configuration string variable.

## Return value

If the function is successful (if the variable name was found and had a non-zero-length string), the **DWORD** is inserted, and the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

