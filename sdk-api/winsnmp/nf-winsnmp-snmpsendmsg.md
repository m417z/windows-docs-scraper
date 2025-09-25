# SnmpSendMsg function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

A WinSNMP application calls the
**SnmpSendMsg** function to request that the Microsoft WinSNMP implementation transmit an SNMP protocol data unit (PDU), in the form of an SNMP message. The WinSNMP application specifies a source entity, a destination entity, and a context for the request.

If a WinSNMP application expects a PDU in response to a
**SnmpSendMsg** request, it must retrieve the PDU. To do this, the application must call the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function using the session handle returned by
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession).

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `srcEntity` [in]

Handle to the management entity that initiates the request to send the SNMP message.

### `dstEntity` [in]

Handle to the target entity that will respond to the SNMP request.

### `context` [in]

Handle to the context, (a set of managed object resources), that the target management entity controls.

### `PDU` [in]

Handle to the protocol data unit that contains the SNMP operation request.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function may return one of the following WinSNMP or network transport layer errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The *session* parameter is invalid. |
| **SNMPAPI_ENTITY_INVALID** | One or both of the entity parameters is invalid. |
| **SNMPAPI_CONTEXT_INVALID** | The *context* parameter is invalid. |
| **SNMPAPI_PDU_INVALID** | The *PDU* parameter is invalid. |
| **SNMPAPI_OPERATION_INVALID** | The operation specified in the **PDU_type** field of the PDU is inappropriate for the destination entity. For more information, see the following Remarks section. |
| **SNMPAPI_TL_NOT_INITIALIZED** | The network transport layer was not initialized. |
| **SNMPAPI_TL_NOT_SUPPORTED** | The network transport layer does not support the SNMP protocol. |
| **SNMPAPI_TL_NOT_AVAILABLE** | The network subsystem failed. |
| **SNMPAPI_TL_RESOURCE_ERROR** | A resource error occurred in the network transport layer. |
| **SNMPAPI_TL_SRC_INVALID** | The entity specified by the *srcEntity* parameter was not initialized. |
| **SNMPAPI_TL_INVALID_PARAM** | A network transport layer function call received an invalid input parameter. |
| **SNMPAPI_TL_PDU_TOO_BIG** | The PDU is too large for the network transport layer to send or receive. |
| **SNMPAPI_TL_OTHER** | An undefined network transport layer error occurred. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

For additional information, see
[Network Transport Errors](https://learn.microsoft.com/windows/desktop/SNMP/network-transport-errors).

## Remarks

The
**SnmpSendMsg** function executes asynchronously and therefore returns immediately.

The implementation notifies the WinSNMP application when the asynchronous request is completed. The implementation does this by sending a notification message to the window specified by the *wMsg* and *hWnd* parameters, respectively, in the initial call to
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) for the session. When the application window receives the notification message, the WinSNMP application must retrieve the incoming PDU. The application does this by calling the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function with the session handle returned by
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession).

When a WinSNMP application calls the
**SnmpSendMsg** function, the implementation determines which network transport protocol and SNMP version framework to use to complete the transmission request. The implementation determines this by matching its capabilities with properties associated with the requesting session and with the target management entity. This information is available from values in the implementation's database.

If a WinSNMP application requests functionality that is available under the SNMP version 2C framework (SNMPv2C), but the target entity uses the SNMP version 1 framework (SNMPv1), the implementation attempts to translate the request to SNMPv1. To do this, the implementation uses the procedures defined in RFC1908, "Coexistence between Version 1 and Version 2 of the Internet-standard Network Management Framework." If translation is not possible,
**SnmpSendMsg** fails with the extended error code SNMPAPI_OPERATION_INVALID. This situation occurs, for example, when an application attempts to send a PDU with the **SNMP_PDU_InformRequest** data type to an SNMPv1 destination entity.

For additional information, see
[WinSNMP Programming Tasks](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-programming-tasks) and
[About SNMP Messages](https://learn.microsoft.com/windows/desktop/SNMP/about-snmp-messages).

## See also

[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession)

[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)