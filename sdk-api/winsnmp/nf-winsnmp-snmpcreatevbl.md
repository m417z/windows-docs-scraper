# SnmpCreateVbl function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpCreateVbl** function creates a new variable bindings list for the calling WinSNMP application. If the *name* and *value* parameters are not **NULL**,
**SnmpCreateVbl** uses their values to create the first variable binding entry for the new variable bindings list. The
**SnmpCreateVbl** function returns a handle to the new variable bindings list and allocates any necessary memory for it.

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `name` [in]

Pointer to an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure that contains the variable name for the first variable binding entry. This parameter can be **NULL**. For additional information, see the following Remarks section.

### `value` [in]

Pointer to an
[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue) structure that contains a value to associate with the variable in the first variable binding entry. This parameter can be **NULL**. For additional information, see the following Remarks section.

## Return value

If the function succeeds, the return value is a handle to a new variable bindings list.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The session handle is invalid. |
| **SNMPAPI_OID_INVALID** | The *name* parameter references an invalid [smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure. |
| **SNMPAPI_SYNTAX_INVALID** | The **syntax** member of the structure pointed to by the *value* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The
**SnmpCreateVbl** function uses the values of the *name* and *value* parameters to create and initialize the first variable binding entry of a new variable bindings list. If the *name* parameter is **NULL**, the Microsoft WinSNMP implementation ignores the *value* parameter and creates an empty variable bindings list.

If the *name* parameter is not **NULL**, but the *value* parameter is **NULL**, the implementation creates and initializes the first variable binding entry in the variable bindings list. It initializes the **syntax** member of the structure pointed to by the *value* parameter with the value SNMP_SYNTAX_NULL.

The WinSNMP application must release the resources associated with each variable bindings list. It should do this by matching each call to the
**SnmpCreateVbl** and
[SnmpDuplicateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpduplicatevbl) functions with a corresponding call to the
[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl) function. To avoid memory leaks, a WinSNMP application must call
**SnmpFreeVbl** before it reuses the handle to a variable bindings list in a subsequent call to
**SnmpCreateVbl** or
**SnmpDuplicateVbl**. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpDuplicateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpduplicatevbl)

[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid)

[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue)