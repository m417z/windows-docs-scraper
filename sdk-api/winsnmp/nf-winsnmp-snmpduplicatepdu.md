# SnmpDuplicatePdu function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpDuplicatePdu** function duplicates the SNMP protocol data unit (PDU) that the *PDU* parameter identifies, allocating any necessary memory for the duplicate PDU.

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `PDU` [in]

Handle to the PDU to duplicate. The
**SnmpDuplicatePdu** function provides a unique handle to each PDU within the calling application.

## Return value

If the function succeeds, the return value is a handle that identifies the new duplicate PDU.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The session handle is invalid. |
| **SNMPAPI_PDU_INVALID** | The PDU handle is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

To release resources allocated by the
**SnmpDuplicatePdu** function for a new PDU, a WinSNMP application must call the
[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu) function.

## See also

[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu)

[SnmpGetPduData](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetpdudata)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)