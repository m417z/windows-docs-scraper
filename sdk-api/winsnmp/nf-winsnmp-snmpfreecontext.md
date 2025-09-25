# SnmpFreeContext function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpFreeContext** function releases resources associated with an SNMP context, which is a set of managed object resources.

## Parameters

### `context` [in]

Handle to the SNMP context that will have its resources released.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_CONTEXT_INVALID** | The *context* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

When the WinSNMP application calls the
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) function or the
[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) function, the Microsoft WinSNMP implementation frees all resources it allocated for the WinSNMP session. However, it is recommended that the WinSNMP application free individual resources with the WinSNMP function that corresponds to the resource. For example, applications should call the
**SnmpFreeContext** function to release resources allocated by a call to the
[SnmpStrToContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtocontext) function. This reduces the implementation's work load, and should enhance the service of the implementation to all applications.

For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpStrToContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtocontext)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)