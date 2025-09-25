# SnmpSetVb function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpSetVb** function changes variable binding entries in a variable bindings list. This function also appends new variable binding entries to an existing variable bindings list.

## Parameters

### `vbl` [in]

Handle to the variable bindings list to update.

### `index` [in]

Specifies an unsigned long integer variable that contains the position of the variable binding entry, within the variable bindings list, if this is an update operation. If this is an append operation, this parameter must be equal to zero. For more information, see the following Remarks section.

### `name` [in]

Pointer to an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure that represents the name of the variable to append or change. For more information, see the following Remarks section.

### `value` [in]

Pointer to an
[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue) structure. The structure contains the value associated with the variable specified by the *name* parameter.

## Return value

If the function succeeds, the return value is the position of the updated or appended variable binding entry in the variable bindings list. For additional information, see the following Remarks section.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_VBL_INVALID** | The *vbl* parameter is invalid. |
| **SNMPAPI_INDEX_INVALID** | The *index* parameter is invalid. |
| **SNMPAPI_OID_INVALID** | The *name* parameter is invalid. |
| **SNMPAPI_SYNTAX_INVALID** | The **syntax** member of the structure pointed to by the *value* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

Valid values for the *index* parameter range from zero to n. The value zero indicates an append operation. The value n is the total number of variable binding entries in the variable bindings list. A WinSNMP application should call the
[SnmpCountVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcountvbl) function before it calls
**SnmpSetVb** to obtain the total number of variable binding entries.

If the function successfully performs an update operation, the return value equals the value of the *index* parameter. If the function appends a variable binding entry, the return value is n + 1.

If the *name* parameter is not **NULL**, but the *value* parameter is **NULL**, the Microsoft WinSNMP implementation initializes the new variable binding entry with the **value** member set to **NULL** and with the **syntax** member set to [SNMP_SYNTAX_](https://learn.microsoft.com/windows/desktop/SNMP/snmp-variable-types-and-request-pdu-types).

If the *index* parameter is not equal to zero, and the *name* parameter is **NULL**, the Microsoft WinSNMP implementation updates only the value of the variable pointed to by the *index* parameter.

## See also

[SnmpCountVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcountvbl)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid)

[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue)