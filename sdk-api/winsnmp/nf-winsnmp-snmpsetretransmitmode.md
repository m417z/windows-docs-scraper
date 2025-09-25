# SnmpSetRetransmitMode function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpSetRetransmitMode** function enables a WinSNMP application to set the retransmission mode. The Microsoft WinSNMP implementation uses the new retransmission mode to govern transmission time-outs and retransmission attempts on subsequent calls to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function.

## Parameters

### `nRetransmitMode` [in]

Specifies a value for the new retransmission mode. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMPAPI_ON** | The implementation executes the WinSNMP application's retransmission policy. |
| **SNMPAPI_OFF** | The implementation does not execute the WinSNMP application's retransmission policy. |

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_MODE_INVALID** | The implementation does not support the requested retransmission mode. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

Typically a WinSNMP manager application, rather than an agent application, calls the
**SnmpSetRetransmitMode** function.

If a WinSNMP application sets the retransmission mode to SNMPAPI_OFF, the implementation does not initiate retransmission attempts for new SNMP communications operations. The new setting affects all subsequent calls to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function, until the WinSNMP application sets the retransmission mode back to SNMPAPI_ON.

Calling the
[SnmpCancelMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcancelmsg) function is equivalent to calling the
**SnmpSetRetransmitMode** function, for a specific SNMP message, with the retransmission mode equal to SNMPAPI_OFF.

**Note** If the implementation returns the error SNMPAPI_MODE_INVALID to a call to
**SnmpSetRetransmitMode**, the WinSNMP application must execute the retransmission policy.

For additional information, see
[About Retransmission](https://learn.microsoft.com/windows/desktop/SNMP/about-retransmission) and
[Managing the Retransmission Policy](https://learn.microsoft.com/windows/desktop/SNMP/managing-the-retransmission-policy).

## See also

[SnmpCancelMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcancelmsg)

[SnmpGetRetransmitMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetretransmitmode)

[SnmpGetRetry](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetretry)

[SnmpGetTimeout](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgettimeout)

[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)