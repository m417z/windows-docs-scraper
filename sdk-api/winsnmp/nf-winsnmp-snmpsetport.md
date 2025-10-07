# SnmpSetPort function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

A WinSNMP application calls the
**SnmpSetPort** function to change the port assigned to a destination entity. The
**SnmpSetPort** function is an element of the WinSNMP API, version 2.0.

## Parameters

### `hEntity` [in]

Handle to a WinSNMP destination entity. This parameter can specify the handle to an entity acting in the role of an SNMP agent application as a result of a call to the
[SnmpListen](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmplisten) function. For more information, see the following Remarks section.

### `nPort` [in]

Specifies an unsigned integer that identifies the new port assignment for the destination entity. If you specify a local address that is busy, or if you specify a remote address that is unavailable, a call to the
**SnmpSetPort** function fails.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_OPERATION_INVALID** | The entity specified by the *hEntity* parameter is already functioning in an agent role as the result of a call to the [SnmpListen](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmplisten) function. For more information, see the following Remarks section. |
| **SNMPAPI_ENTITY_INVALID** | The *hEntity* parameter is invalid. This parameter must be a handle returned by a previous call to the [SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity) function. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The Microsoft WinSNMP implementation assigns a port to each management entity as a result of a WinSNMP application's call to the
[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity) function. If the SNMPAPI_UNTRANSLATED mode is in effect when the implementation creates an entity, the implementation typically assigns the standard SNMP request port for the respective protocol family to the entity; for example, UDP 161 or IPX 36879. If the SNMPAPI_TRANSLATED mode is in effect, the implementation assigns the port specified for the entity in the WinSNMP database. To retrieve the current entity and context translation mode in effect for the implementation, an application can call the
[SnmpGetTranslateMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgettranslatemode) function. For more information, see
[Setting the Entity and Context Translation Mode](https://learn.microsoft.com/windows/desktop/SNMP/setting-the-entity-and-context-translation-mode) and
[The WinSNMP Database](https://learn.microsoft.com/windows/desktop/SNMP/the-winsnmp-database).

A call to the
**SnmpSetPort** function fails if the entity specified by the *hEntity* parameter is currently functioning in an agent role. This is because the entity has already been assigned to a port other than the one specified by the *nPort* parameter. To ensure assignment of an agent application to a specific port, a WinSNMP application can perform the following steps.

1. Call [SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity) as follows:

   `hAgent = SnmpStrToEntity (hSession, <addrString>);`
2. Call **SnmpSetPort** as follows:

   `SnmpSetPort (hAgent, <nPort>);`
3. Call [SnmpListen](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmplisten) as follows:

   `SnmpListen (hAgent, SNMPAPI_ON);`

where \<addrString> contains the string representation of an IP address or an IPX address, and \<nPort> contains the new port assignment for the agent application.

Note that an IPX address contains a network number that consists of eight hexadecimal digits (zero-filled if necessary); a separator (either ":", "." or " – "); and a node number that consists of 12 hexadecimal digits (zero-filled if necessary)—for example, 00000001:00081A0D01C2. For more information, see
[Support for IPX Address Strings in WinSNMP](https://learn.microsoft.com/windows/desktop/SNMP/support-for-ipx-address-strings-in-winsnmp).

## See also

[SnmpGetTranslateMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgettranslatemode)

[SnmpListen](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmplisten)

[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)