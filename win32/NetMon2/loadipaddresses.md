# LoadIPAddresses function

The **LoadIPAddresses** function is called by the monitor to fill in an IP address list with addresses taken from an HTML configuration string variable.

## Parameters

*pConfig* \[in\]

Pointer to the HTML configuration string passed to the monitor by the [IMonitor::DoConfigure](https://learn.microsoft.com/windows/win32/netmon2/imonitor-doconfigure) method.

*pVarName* \[in\]

Pointer to the name of the variable in the configuration string.

*ppAddresses* \[out\]

Pointer to a pointer to an array of addresses. If the variable specified in *pVarName* is found and has a non-zero-length, the function allocates sufficient space and stores all the IP addresses as an array.

*pNumAddresses* \[out\]

Pointer to the **DWORD** variable that is set to the number of IP addresses taken from the configuration string.

## Return value

If the function is successful (the variable name was found and had a non-zero-length string that represented IP addresses), the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Remarks

The IP addresses must be in x.x.x.x format (for example, 127.0.0.1).

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

