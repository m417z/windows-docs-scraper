# SnmpCancelMsg function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

A WinSNMP application calls the
**SnmpCancelMsg** function to request that the Microsoft WinSNMP implementation cancel retransmission attempts and time-out notifications for an SNMP request message. The
**SnmpCancelMsg** function is an element of the WinSNMP API, version 2.0.

## Parameters

### `session` [in]

Handle to the WinSNMP session that submitted the SNMP request message (PDU) to be canceled.

### `reqId` [in]

Specifies a unique numeric value that identifies the PDU of interest. This parameter must match the request identifier (**request_id**) of the *PDU* parameter specified in the application's initial call to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_SESSION_INVALID** | The *session* parameter is invalid. |
| **SNMPAPI_PDU_INVALID** | The *reqId* parameter does not identify an outstanding message for the specified session. |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

Calling the
**SnmpCancelMsg** function is equivalent to calling the
[SnmpSetRetransmitMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetretransmitmode) function, for a specific SNMP message, with the retransmission mode equal to SNMPAPI_OFF.

For more information, see
[Canceling Retransmission](https://learn.microsoft.com/windows/desktop/SNMP/canceling-retransmission) and
[Managing the Retransmission Policy](https://learn.microsoft.com/windows/desktop/SNMP/managing-the-retransmission-policy).

## See also

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[SnmpSetRetransmitMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetretransmitmode)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)