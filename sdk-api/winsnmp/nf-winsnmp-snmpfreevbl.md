# SnmpFreeVbl function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpFreeVbl** function releases resources associated with a variable bindings list. These are resources allocated previously by a call to the
[SnmpCreateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatevbl) function or the
[SnmpDuplicateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpduplicatevbl) function in a WinSNMP application.

## Parameters

### `vbl` [in]

Handle to the variable bindings list to release.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_VBL_INVALID** | The *vbl* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The WinSNMP application must release the resources associated with each variable bindings list. It should do this by matching each call to the
[SnmpCreateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatevbl) and
[SnmpDuplicateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpduplicatevbl) functions with a corresponding call to the
**SnmpFreeVbl** function. To avoid memory leaks, a WinSNMP application must call
**SnmpFreeVbl** before it reuses the handle to a variable bindings list in a subsequent call to
[SnmpCreateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatevbl) or
[SnmpDuplicateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpduplicatevbl).

If the application calls the
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) or the
[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) function, the Microsoft WinSNMP implementation frees all resources it allocates for the WinSNMP session. However, even if the application does not reuse a variable bindings list handle, it is recommended that the application free individual variable bindings resources with the
**SnmpFreeVbl** function. This reduces the implementation's work load, and should enhance its service to all applications. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpCreateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatevbl)

[SnmpDuplicateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpduplicatevbl)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)