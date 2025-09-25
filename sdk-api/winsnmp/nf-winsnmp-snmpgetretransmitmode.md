# SnmpGetRetransmitMode function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpGetRetransmitMode** function returns the current setting of the retransmission mode to a WinSNMP application. The Microsoft WinSNMP implementation uses the retransmission mode to govern transmission time-outs and retransmission attempts on calls to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function.

## Parameters

### `nRetransmitMode` [out]

Pointer to an unsigned long integer variable to receive the current retransmission mode in effect for the implementation. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMPAPI_ON** | The implementation is executing the WinSNMP application's retransmission policy. |
| **SNMPAPI_OFF** | The implementation is not executing the WinSNMP application's retransmission policy. |

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. If
**SnmpGetRetransmitMode** fails, the value of the *nRetransmitMode* parameter has no meaning for the application. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

Typically a WinSNMP application, rather than an agent application, calls the
**SnmpGetRetransmitMode** function. For additional information, see
[About Retransmission](https://learn.microsoft.com/windows/desktop/SNMP/about-retransmission) and
[Managing the Retransmission Policy](https://learn.microsoft.com/windows/desktop/SNMP/managing-the-retransmission-policy).

## See also

[SnmpSetRetransmitMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetretransmitmode)

[SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)