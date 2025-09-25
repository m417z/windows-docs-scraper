# SnmpFreePdu function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpFreePdu** function releases resources associated with an SNMP protocol data unit (PDU) created by the
[SnmpCreatePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatepdu) or the
[SnmpDuplicatePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpduplicatepdu) function.

## Parameters

### `PDU` [in]

Handle to the SNMP PDU to free.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_PDU_INVALID** | The PDU handle is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

If the application calls the
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) or the
[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) function, the Microsoft WinSNMP implementation frees all resources it allocates for the WinSNMP session. However, it is recommended that the application free individual resources with the WinSNMP function that corresponds to the resource. This reduces the implementation's work load, and should enhance the implementation's service to all applications. The application should use the
[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl) function to deallocate variable bindings list resources. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

Under WinSNMP, a variable binding entry exists only within a variable bindings list, even if the variable bindings list contains just one entry.

## See also

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)