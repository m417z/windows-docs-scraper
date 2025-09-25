# SnmpRegister function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpRegister** function registers or unregisters a WinSNMP application for trap and notification reception. The application can register and receive traps and notifications, or unregister and disable traps and notifications.

A WinSNMP application can register or unregister for one type of trap or notification, or for all traps and notifications, depending on the value of the *notification* parameter.

## Parameters

### `session` [in]

Handle to the WinSNMP session that is registering or unregistering for traps and notifications.

### `srcEntity` [in]

Handle to the management entity that is the source of the registration request. This entity, acting in an SNMP manager role, will receive the trap or notification.

Because the implementation does not use this parameter to filter traps and notifications from reaching the WinSNMP application, a WinSNMP manager application typically passes **NULL** in this parameter.

If this parameter is **NULL**, the Microsoft WinSNMP implementation registers or unregisters all sources of trap and notification requests.

Note that the *srcEntity* parameter to the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function has a different role. In that function, *srcEntity* receives a handle to the entity that sent the trap.

### `dstEntity` [in]

Handle to the management entity that is the recipient of the registration request. This entity, acting in an SNMP agent role, will send the trap or notification.

If this parameter is **NULL**, the implementation registers or unregisters the WinSNMP application for traps and notifications from all management entities.

Note that the *dstEntity* parameter to the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function receives a handle to the management entity that registers for trap notification.

### `context` [in]

Handle to the context, which is a set of managed object resources.

If this parameter is **NULL**, the implementation registers or unregisters the WinSNMP application for traps and notifications for every context.

### `notification` [in]

Pointer to an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure that contains the pattern-matching sequence for one type of trap or notification. The implementation uses this sequence to identify the type of trap or notification for which the WinSNMP application is registering or unregistering. For additional information, see the following Remarks section.

If this parameter is **NULL**, the implementation registers or unregisters the WinSNMP application for all traps and notifications from the management entity or entities specified by the *dstEntity* parameter.

### `state` [in]

Specifies an unsigned long integer variable that indicates whether the WinSNMP application is registering to receive traps and notifications, or if it is unregistering. This parameter should be equal to one of the following values, but if it contains a different value, the implementation registers the application.

| Value | Meaning |
| --- | --- |
| **SNMPAPI_OFF** | Disable traps and notifications. |
| **SNMPAPI_ON** | Register to receive traps and notifications. |

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
| **SNMPAPI_OID_INVALID** | The *notification* parameter is invalid. |
| **SNMPAPI_TL_NOT_INITIALIZED** | The network transport layer was not initialized, or the SNMPTRAP.EXE service could not be started. |
| **SNMPAPI_TL_IN_USE** | The trap port is not available. |
| **SNMPAPI_TL_NOT_AVAILABLE** | The network subsystem failed. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

For additional information, see
[Network Transport Errors](https://learn.microsoft.com/windows/desktop/SNMP/network-transport-errors).

## Remarks

Typically a WinSNMP manager application, rather than an agent application, calls the
**SnmpRegister** function.

It is important to note that for users who are not administrators, the
**SnmpRegister** function succeeds on Windows 2000 and Windows XP only if the SNMP trap service has been started.

If a WinSNMP application passes **NULL** in a call to the
**SnmpRegister** function in the *srcEntity*, *dstEntity*, *context*, or *notification* parameters, the implementation does not use that parameter to filter traps and notifications from reaching the WinSNMP application. If an application passes **NULL** in all of the parameters mentioned previously, the implementation delivers all received notifications to the session.

If a WinSNMP application registers to receive a specific type of trap or notification, it must define an object identifier, that is, an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure, that corresponds to that type of trap. The *notification* parameter must point to this structure. RFC 1907, "Management Information Base for Version 2 of the Simple Network Management Protocol (SNMPv2)," defines trap and notification object identifiers. For additional information, see
[Managing Traps and Notifications](https://learn.microsoft.com/windows/desktop/SNMP/managing-traps-and-notifications) and
[Translating Traps from SNMPv1 to SNMPv2C](https://learn.microsoft.com/windows/desktop/SNMP/translating-traps-from-snmpv1-to-snmpv2c).

The implementation uses the value of the *notification* parameter as a pattern to match against received traps and notifications. For example, if the WinSNMP application passes n number of subidentifiers in the *notification* parameter, and the first n subidentifiers in a received trap match all the passed subidentifiers, then the trap object identifier is a match. If a received trap has fewer subidentifiers than n, the object identifier does not match. If there is a match, the implementation sends the trap or notification to the WinSNMP application.

If any or all of the *dstEntity*, *srcEntity*, or *context* parameters are **NULL**, the implementation may need to allocate resources on a subsequent call to the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function, for that function's corresponding parameters. When the WinSNMP application no longer needs the resources
**SnmpRecvMsg** returns, the application must free the individual resources with the function that corresponds to the resource. For additional information, see
[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity) and
[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext).

For more information, see
[Multiple Trap Registrations](https://learn.microsoft.com/windows/desktop/SNMP/multiple-trap-registrations).

## See also

[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession)

[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext)

[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity)

[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)