# SnmpSetTimeout function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpSetTimeout** function enables a WinSNMP application to change the time-out value for the transmission of SNMP message requests. The time-out value applies to calls that a WinSNMP application makes to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function for a specified management entity. The Microsoft WinSNMP implementation stores the value in a database.

## Parameters

### `hEntity` [in]

Handle to the destination management entity of interest.

### `nPolicyTimeout` [in]

Specifies a new time-out value, in hundredths of a second, for the management entity. This value replaces the value currently stored in the implementation's database.

If this parameter is equal to zero, and the current retransmission mode is equal to SNMPAPI_ON, the implementation selects a time-out value. The implementation uses this time-out value when it executes the WinSNMP application's retransmission policy.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_ENTITY_INVALID** | The *hEntity* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

Typically a WinSNMP manager application, rather than an agent application, calls the
**SnmpSetTimeout** function.

For additional information, see
[About Retransmission](https://learn.microsoft.com/windows/desktop/SNMP/about-retransmission) and
[Managing the Retransmission Policy](https://learn.microsoft.com/windows/desktop/SNMP/managing-the-retransmission-policy).

## See also

[SnmpGetRetransmitMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetretransmitmode)

[SnmpGetTimeout](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgettimeout)

[SnmpSetRetransmitMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetretransmitmode)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)