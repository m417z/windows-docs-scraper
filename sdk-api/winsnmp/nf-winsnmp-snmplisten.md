# SnmpListen function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpListen** function registers a WinSNMP application as an SNMP agent. An agent application calls this function to inform the Microsoft WinSNMP implementation that an entity will be acting in the role of an SNMP agent. An application also calls this function to inform the implementation when an entity will no longer be acting in this role. The
**SnmpListen** function is an element of the WinSNMP API, version 2.0.

## Parameters

### `hEntity` [in]

Handle to the WinSNMP entity to notify when the Microsoft WinSNMP implementation receives an incoming SNMP request message (PDU). This parameter identifies the agent application. For more information, see the following Remarks and Return Values sections.

When you call the
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) function, you can specify whether the implementation should use a window notification message or an
[SNMPAPI_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winsnmp/nc-winsnmp-snmpapi_callback) function to notify the application when an SNMP message or asynchronous event is available.

### `lStatus` [in]

Specifies an unsigned long integer variable that indicates whether the WinSNMP entity identified by the *hEntity* parameter is acting in an SNMP agent role, or if it is no longer acting in this role. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMPAPI_ON** | The specified WinSNMP entity is functioning in an agent role. |
| **SNMPAPI_OFF** | The specified WinSNMP entity is not functioning in an agent role. |

Passing a value of SNMPAPI_OFF releases both the resources allocated to the entity and the port assigned it. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_ENTITY_INVALID** | The *hEntity* parameter is invalid. This parameter must be a handle returned by a previous call to the [SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity) function. |
| **SNMPAPI_MODE_INVALID** | The *lStatus* parameter is invalid. |
| **SNMPAPI_NOOP** | The entity specified by the *hEntity* parameter is already functioning in the role of an SNMP agent. |
| **SNMPAPI_TL_RESOURCE_ERROR** | There is a network transport layer error. A socket could not be created for the entity specified by the *hEntity* parameter. |
| **SNMPAPI_TL_OTHER** | An error occurred in the network transport layer while trying to bind a socket for the entity specified by the *hEntity* parameter. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

When you specify an entity, you explicitly specify the address family, interface address, and port for the entity. This is because WinSNMP assigns these attributes to each WinSNMP entity as a result of a call to the
[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity) function. The implementation uses the address and port settings currently assigned to the entity specified by the *hEntity* parameter when it sends notifications to the agent application. For more information, see
[SnmpSetPort](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetport).

When you call the
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) function for a WinSNMP session and the
[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) function for a WinSNMP application, you must release all ports associated with WinSNMP agent applications.

For more information about SNMP management applications and agent applications, see
[Registering an SNMP Agent Application](https://learn.microsoft.com/windows/desktop/SNMP/registering-an-snmp-agent-application) and
[About SNMP](https://learn.microsoft.com/windows/desktop/SNMP/about-snmp).

## See also

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[SnmpSetPort](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsetport)

[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)