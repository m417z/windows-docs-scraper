# SnmpEntityToStr function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpEntityToStr** function returns a string that identifies an SNMP management entity.

## Parameters

### `entity` [in]

Handle to the SNMP management entity of interest.

### `size` [in]

Specifies the size, in bytes, of the buffer pointed to by the *string* parameter. The WinSNMP application must allocate a buffer that is large enough to contain the output string.

### `string` [out]

Pointer to a buffer to receive the null-terminated string that identifies the SNMP management entity of interest.

## Return value

If the function succeeds, the return value is the number of bytes, including a terminating null byte, that
**SnmpEntityToStr** returns in the *string* buffer. This value can be less than or equal to the value of the *size* parameter, but it cannot be greater.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_ENTITY_INVALID** | The *entity* parameter is invalid. |
| **SNMPAPI_OUTPUT_TRUNCATED** | The output buffer length is insufficient. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The current setting of the entity and context translation mode determines the type of output string
**SnmpEntityToStr** returns. For additional information, see
[Support for IPX Address Strings in WinSNMP](https://learn.microsoft.com/windows/desktop/SNMP/support-for-ipx-address-strings-in-winsnmp) and
[Setting the Entity and Context Translation Mode](https://learn.microsoft.com/windows/desktop/SNMP/setting-the-entity-and-context-translation-mode).

When the entity and context translation mode is SNMPAPI_TRANSLATED, and an entry exists in the implementation's database, the implementation returns the associated user-friendly name of the management entity. If an entry does not exist for the management entity,
**SnmpEntityToStr** returns the literal SNMP transport address of the management entity.

When the entity and context translation mode is SNMPAPI_UNTRANSLATED_V1 or SNMPAPI_UNTRANSLATED_V2, the Microsoft WinSNMP implementation also returns the literal SNMP transport address of the management entity.

## See also

[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)