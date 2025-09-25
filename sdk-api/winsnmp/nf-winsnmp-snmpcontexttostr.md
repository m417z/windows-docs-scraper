# SnmpContextToStr function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpContextToStr** function returns a string that identifies an SNMP context, which is a set of managed object resources. The function returns the string in an
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure.

## Parameters

### `context` [in]

Handle to the SNMP context of interest.

### `string` [out]

Pointer to an
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure to receive the string that identifies the context of interest. The string can have a null-terminating byte.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_CONTEXT_INVALID** | The *context* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The current setting of the entity and context translation mode determines the type of output string
**SnmpContextToStr** returns. For additional information, see
[Setting the Entity and Context Translation Mode](https://learn.microsoft.com/windows/desktop/SNMP/setting-the-entity-and-context-translation-mode).

The WinSNMP application must provide the address of a valid
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure for the *string* parameter. If the
**SnmpContextToStr** function completes successfully, the Microsoft WinSNMP implementation initializes the **len** and **ptr** members of the structure. The WinSNMP application must call the
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) function to enable the implementation to free the resources for these members.

When the entity and context translation mode is SNMPAPI_TRANSLATED, and the entry exists in the implementation's database, the implementation returns the associated user-friendly name of the context. If an entry does not exist for the context name,
**SnmpContextToStr** returns the SNMP community string.

When the entity and context translation mode is SNMPAPI_UNTRANSLATED_V1 or SNMPAPI_UNTRANSLATED_V2, the implementation also returns the SNMP community string.

## See also

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets)