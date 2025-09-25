# SnmpRecvMsg function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpRecvMsg** function retrieves the results of a completed asynchronous request submitted by a call to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function, in the form of an SNMP message. The
**SnmpRecvMsg** function also returns outstanding trap data and notifications registered for a WinSNMP session.

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `srcEntity` [out]

Pointer to a variable that receives a handle to the entity that sends the message. Note that the *srcEntity* parameter to the
[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister) function specifies a handle to the management entity that registers for trap notification.

### `dstEntity` [out]

Pointer to a variable that receives a handle to the entity that receives the message. Note that the *dstEntity* parameter to the
[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister) function specifies a handle to the management entity that sends traps.

### `context` [out]

Pointer to a variable that receives a handle to the context, which is a set of managed object resources. The entity specified by the *srcEntity* parameter issues the message from this context.

### `PDU` [out]

Pointer to a variable that receives a handle to the protocol data unit (PDU) component of the message.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS, and the output parameters contain the values indicated in the preceding parameter descriptions.

If the function fails, the return value is SNMPAPI_FAILURE. If the function fails with an extended error code that indicates a network transport layer error, that is, one that begins with SNMPAPI_TL_, the output parameters also contain the values indicated preceding to enable the WinSNMP application to recover gracefully.

To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function may return one of the following WinSNMP or network transport layer errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The *session* parameter is invalid. |
| **SNMPAPI_NOOP** | The specified session has no messages in its queue at this time. |
| **SNMPAPI_TL_NOT_INITIALIZED** | The network transport layer was not initialized. |
| **SNMPAPI_TL_NOT_SUPPORTED** | The network transport layer does not support the SNMP protocol. |
| **SNMPAPI_TL_NOT_AVAILABLE** | The network subsystem failed. |
| **SNMPAPI_TL_RESOURCE_ERROR** | A resource error occurred in the network transport layer. |
| **SNMPAPI_TL_UNDELIVERABLE** | The entity specified by the *dstEntity* parameter is unavailable. |
| **SNMPAPI_TL_SRC_INVALID** | The entity specified by the *srcEntity* parameter was not initialized. |
| **SNMPAPI_TL_INVALID_PARAM** | A network transport layer function call received an invalid input parameter. |
| **SNMPAPI_TL_PDU_TOO_BIG** | The PDU is too large for the network transport layer to send or receive. |
| **SNMPAPI_TL_OTHER** | An undefined network transport layer error occurred. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

For additional information, see
[Network Transport Errors](https://learn.microsoft.com/windows/desktop/SNMP/network-transport-errors).

## Remarks

The
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) function passes an application window handle and notification message identifier to the Microsoft WinSNMP implementation. When the application window receives the notification message specified by the *wMsg* parameter, the WinSNMP application must call the
**SnmpRecvMsg** function with the session handle returned by
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) to retrieve an incoming protocol data unit (PDU). For additional information, see
[About SNMP Messages](https://learn.microsoft.com/windows/desktop/SNMP/about-snmp-messages).

The
**SnmpRecvMsg** function instantiates four objects and allocates their resources: two entity handles, a context handle, and a PDU handle. The handle to the variable bindings list component of the returned PDU is not instantiated until the WinSNMP application calls the
[SnmpGetPduData](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetpdudata) function. When it no longer needs the resources
**SnmpRecvMsg** returns, the WinSNMP application must free the individual resources using the WinSNMP function that corresponds to the resource. For additional information, see
[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu),
[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity), and
[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext).

When the implementation receives traps from an entity operating under the SNMP version 1 framework (SNMPv1), it translates the traps to the SNMP version 2C (SNMPv2C) format. Therefore, when
**SnmpRecvMsg** delivers a trap it is always in the SNMPv2C format. For additional information, see
[Translating Traps from SNMPv1 to SNMPv2C](https://learn.microsoft.com/windows/desktop/SNMP/translating-traps-from-snmpv1-to-snmpv2c) and
[WinSNMP Programming Tasks](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-programming-tasks).

## See also

[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext)

[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity)

[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu)

[SnmpGetPduData](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetpdudata)

[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)