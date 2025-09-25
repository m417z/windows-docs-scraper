# SnmpDuplicateVbl function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpDuplicateVbl** function copies a variable bindings list for the specified WinSNMP session. This function returns a handle to the copied variable bindings list and allocates any necessary memory for it.

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `vbl` [in]

Handle to the variable bindings list to copy. The source variable bindings list can be empty.

## Return value

If the function succeeds, the return value is a handle to a new variable bindings list.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The session handle is invalid. |
| **SNMPAPI_VBL_INVALID** | The *vbl* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The
**SnmpDuplicateVbl** function creates a new variable bindings list for the specified WinSNMP session. This function initializes the new list with a copy of the data in the source variable bindings list.

The handle the
**SnmpDuplicateVbl** function returns is unique among the variable bindings list handles that are active within the WinSNMP application.

The WinSNMP application must release the resources associated with each variable bindings list. It should do this by matching each call to the
[SnmpCreateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatevbl) and
**SnmpDuplicateVbl** functions with a corresponding call to the
[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl) function. To avoid memory leaks, a WinSNMP application must call
**SnmpFreeVbl** before it reuses the handle to a variable bindings list in a subsequent call to
**SnmpCreateVbl** or
**SnmpDuplicateVbl**. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpCreateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatevbl)

[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)