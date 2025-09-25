# SnmpCountVbl function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

A WinSNMP application calls the WinSNMP
**SnmpCountVbl** function to enumerate the variable binding entries in the specified variable bindings list.

## Parameters

### `vbl` [in]

Handle to the variable bindings list to enumerate.

## Return value

If the function succeeds, the return value is the count of variable binding entries in the variable bindings list.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_NOOP** | The variable bindings list does not contain any variable binding entries at this time. |
| **SNMPAPI_VBL_INVALID** | The *vbl* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The
**SnmpCountVbl** function returns an unsigned integer value that is the maximum value the WinSNMP application can specify for the *index* parameter in the
[SnmpGetVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetvb),
[SnmpSetVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetvb), and
[SnmpDeleteVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpdeletevb) functions.

## See also

[SnmpDeleteVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpdeletevb)

[SnmpGetVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetvb)

[SnmpSetVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetvb)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)