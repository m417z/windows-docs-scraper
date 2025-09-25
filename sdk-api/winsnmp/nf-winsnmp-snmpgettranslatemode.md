# SnmpGetTranslateMode function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpGetTranslateMode** function returns the current setting of the entity and context translation mode to a WinSNMP application. The entity and context translation mode affects the interpretation and return of WinSNMP input and output string parameters.

## Parameters

### `nTranslateMode` [out]

Pointer to an unsigned long integer variable to receive the entity and context translation mode in effect for the Microsoft WinSNMP implementation. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMPAPI_TRANSLATED** | The implementation uses its database to translate user-friendly names for SNMP entities and managed objects. The implementation translates them into their SNMPv1 or SNMPv2C components. |
| **SNMPAPI_UNTRANSLATED_V1** | The implementation interprets SNMP entity parameters as SNMP transport addresses, and context parameters as SNMP community strings. For SNMPv2 destination entities, the implementation creates outgoing SNMP messages that contain a value of zero in the version field. |
| **SNMPAPI_UNTRANSLATED_V2** | The implementation interprets SNMP entity parameters as SNMP transport addresses, and context parameters as SNMP community strings. For SNMPv2 destination entities, the implementation creates outgoing SNMP messages that contain a value of 1 in the version field. |

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. If
**SnmpGetTranslateMode** fails, the value of the *nTranslateMode* parameter has no meaning for the application. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The entity and context translation mode affects calls to the
[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity),
[SnmpStrToContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtocontext),
[SnmpContextToStr](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcontexttostr) and
[SnmpEntityToStr](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpentitytostr) functions. For additional information, see
[Setting the Entity and Context Translation Mode](https://learn.microsoft.com/windows/desktop/SNMP/setting-the-entity-and-context-translation-mode).

## See also

[SnmpContextToStr](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcontexttostr)

[SnmpEntityToStr](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpentitytostr)

[SnmpSetTranslateMode](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsettranslatemode)

[SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup)

[SnmpStrToContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtocontext)

[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)