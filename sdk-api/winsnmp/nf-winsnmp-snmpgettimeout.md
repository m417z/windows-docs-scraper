# SnmpGetTimeout function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpGetTimeout** function returns the time-out value, in hundredths of a second, for the transmission of SNMP message requests. The time-out value applies to calls that a WinSNMP application makes to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function for a specified management entity.

## Parameters

### `hEntity` [in]

Handle to the destination management entity of interest.

### `nPolicyTimeout` [out]

Pointer to an integer variable to receive the time-out value, in hundredths of a second, for the specified management entity. This is a value that the Microsoft WinSNMP implementation stores in a database. If you do not need the information returned in this parameter, *nPolicyRetry* must be a **NULL** pointer.

### `nActualTimeout` [out]

Pointer to an integer variable to receive the last actual or estimated response interval for the destination entity, as reported by the implementation. If you do not need the information returned in this parameter, *nActualRetry* must be a **NULL** pointer. If this parameter is a valid pointer, the function returns 0. For additional information, see the following Remarks section.

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
| **SNMPAPI_NOOP** | The *nPolicyRetry* and *nActualRetry* parameters are both **NULL**. The operation was not performed. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

Typically a WinSNMP application, rather than an agent application, calls the
**SnmpGetTimeout** function.

The time-out period is the interval between the application's call to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function and its call to the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function.

A WinSNMP application can modify the time-out value with a call to the
[SnmpSetTimeout](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsettimeout) function.

The WinSNMP application can monitor the value of the *nActualRetry* parameter and compare it to the value of the *nPolicyRetry* parameter to optimize transmission performance. For additional information, see
[About Retransmission](https://learn.microsoft.com/windows/desktop/SNMP/about-retransmission) and
[Managing the Retransmission Policy](https://learn.microsoft.com/windows/desktop/SNMP/managing-the-retransmission-policy).

## See also

[SnmpGetRetransmitMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetretransmitmode)

[SnmpSetRetransmitMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetretransmitmode)

[SnmpSetTimeout](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsettimeout)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)