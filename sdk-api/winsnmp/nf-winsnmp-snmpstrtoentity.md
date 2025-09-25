# SnmpStrToEntity function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpStrToEntity** function returns a handle to information about an SNMP management entity that is specific to the Microsoft WinSNMP implementation.

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `string` [in]

Pointer to a null-terminated string that identifies the SNMP management entity of interest. The current setting of the entity and context translation mode determines the manner in which
**SnmpStrToEntity** interprets the input string as follows.

| Entity/Context Translation Mode | Meaning |
| --- | --- |
| **SNMPAPI_TRANSLATED** | The implementation interprets the *string* parameter as a user-friendly name. The implementation translates the name into its SNMPv1 or SNMPv2C components using the implementation's database. |
| **SNMPAPI_UNTRANSLATED_V1** | The implementation interprets the *string* parameter as a literal SNMP transport address. |
| **SNMPAPI_UNTRANSLATED_V2** | The implementation interprets the *string* parameter as a literal SNMP transport address. |

## Return value

If the function succeeds, the return value is a handle to the SNMP management entity of interest.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The *session* parameter is invalid. |
| **SNMPAPI_ENTITY_UNKNOWN** | The entity string is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The current setting of the entity and context translation mode determines the manner in which
**SnmpStrToEntity** interprets the input string that identifies the management entity of interest. For additional information, see
[Support for IPX Address Strings in WinSNMP](https://learn.microsoft.com/windows/desktop/SNMP/support-for-ipx-address-strings-in-winsnmp) and
[Setting the Entity and Context Translation Mode](https://learn.microsoft.com/windows/desktop/SNMP/setting-the-entity-and-context-translation-mode).

The WinSNMP application should call the
[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity) function to release the entity handle allocated by the
**SnmpStrToEntity** function. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

The
**SnmpStrToEntity** function returns a valid entity handle that a WinSNMP application can use as the *srcEntity* or the *dstEntity* parameter in multiple WinSNMP functions. These functions include the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg),
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg),
[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister),
[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg), and
[SnmpDecodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpdecodemsg) functions.

The implementation returns the current entity and context translation mode in the *nTranslateMode* parameter of the
[SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function. A WinSNMP application can change the setting of the entity and context translation mode with a call to the
[SnmpSetTranslateMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsettranslatemode) function.

## See also

[SnmpDecodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpdecodemsg)

[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg)

[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity)

[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg)

[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[SnmpSetTranslateMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsettranslatemode)

[SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)