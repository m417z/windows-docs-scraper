# SnmpGetPduData function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpGetPduData** function returns selected data fields from a specified SNMP protocol data unit (PDU).

## Parameters

### `PDU` [in]

Handle to the SNMP PDU.

### `PDU_type` [out]

Pointer to a variable that receives the **PDU_type** field of the specified PDU. This parameter can be **NULL**, or one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMP_PDU_GET** | Search and retrieve a value from a specified SNMP variable. |
| **SNMP_PDU_GETNEXT** | Search and retrieve the value of an SNMP variable without knowing the exact name of the variable. |
| **SNMP_PDU_RESPONSE** | Reply to an **SNMP_PDU_GET** or an **SNMP_PDU_GETNEXT** request. |
| **SNMP_PDU_SET** | Store a value in a specified SNMP variable. |
| **SNMP_PDU_GETBULK** | Search and retrieve multiple values with a single request. |
| **SNMP_PDU_TRAP** | Alerts the management system to an extraordinary event under SNMPv2C. |

### `request_id` [out]

Pointer to a variable that receives the **request_id** field of the specified PDU. This parameter can be **NULL**.

### `error_status` [out]

Pointer to a variable that receives the **error_status** field of the specified PDU. If the *PDU_type* parameter is equal to **SNMP_PDU_GETBULK**, this parameter receives the value of the **non_repeaters** field of the PDU.

This parameter can be **NULL**, or one of the following values. The first six errors are common to the SNMP version 1 (SNMPv1) and SNMP version 2C frameworks (SNMPv2C). The remaining errors are available under SNMPv2C only.

| Error code | Meaning |
| --- | --- |
| **SNMP_ERROR_NOERROR** | The agent reports that no errors occurred during transmission. |
| **SNMP_ERROR_TOOBIG** | The agent could not place the results of the requested SNMP operation into a single SNMP message. |
| **SNMP_ERROR_NOSUCHNAME** | The requested SNMP operation identified an unknown variable. |
| **SNMP_ERROR_BADVALUE** | The requested SNMP operation tried to change a variable but it specified either a syntax or value error. |
| **SNMP_ERROR_READONLY** | The requested SNMP operation tried to change a variable that was not allowed to change, according to the community profile of the variable. |
| **SNMP_ERROR_GENERR** | An error other than one of those listed here occurred during the requested SNMP operation. |
| **SNMP_ERROR_NOACCESS** | The specified SNMP variable is not accessible. |
| **SNMP_ERROR_WRONGTYPE** | The value specifies a type that is inconsistent with the type required for the variable. |
| **SNMP_ERROR_WRONGLENGTH** | The value specifies a length that is inconsistent with the length required for the variable. |
| **SNMP_ERROR_WRONGENCODING** | The value contains an Abstract Syntax Notation One (ASN.1) encoding that is inconsistent with the ASN.1 tag of the field. |
| **SNMP_ERROR_WRONGVALUE** | The value cannot be assigned to the variable. |
| **SNMP_ERROR_NOCREATION** | The variable does not exist, and the agent cannot create it. |
| **SNMP_ERROR_INCONSISTENTVALUE** | The value is inconsistent with values of other managed objects. |
| **SNMP_ERROR_RESOURCEUNAVAILABLE** | Assigning the value to the variable requires allocation of resources that are currently unavailable. |
| **SNMP_ERROR_COMMITFAILED** | No validation errors occurred, but no variables were updated. |
| **SNMP_ERROR_UNDOFAILED** | No validation errors occurred. Some variables were updated because it was not possible to undo their assignment. |
| **SNMP_ERROR_AUTHORIZATIONERROR** | An authorization error occurred. |
| **SNMP_ERROR_NOTWRITABLE** | The variable exists but the agent cannot modify it. |
| **SNMP_ERROR_INCONSISTENTNAME** | The variable does not exist; the agent cannot create it because the named object instance is inconsistent with the values of other managed objects. |

### `error_index` [out]

Pointer to a variable that receives the **error_index** field of the specified PDU.

If the *PDU_type* parameter is equal to **SNMP_PDU_GETBULK**, this parameter receives the value of the **max_repetitions** field of the specified PDU. This parameter can be **NULL**.

### `varbindlist` [out]

Pointer to a variable that receives a handle to the variable bindings list field of the specified PDU. This parameter can be **NULL**. For additional information, see the following Remarks section.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_NOOP** | All output parameters are **NULL**. The SNMP operation was not performed. |
| **SNMPAPI_PDU_INVALID** | The PDU type is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

All parameters of the
**SnmpGetPduData** function are required. However, all parameters, except the *PDU* parameter, can be **NULL**. In parameters that the application passes as **NULL**, the
**SnmpGetPduData** function does not return a value.

The
**SnmpGetPduData** function always returns a handle to a new variable bindings list object if the *varbindlist* parameter is not **NULL**. Additionally, if the *PDU* parameter specifies a new PDU, the function also attaches a handle to the new PDU.

When an application calls
**SnmpGetPduData** with a *varbindlist* parameter that is not **NULL**, but the *PDU* parameter specifies an existing PDU, the function returns a handle to a new duplicate variable bindings list. The function call does not disturb the handle attached to the existing PDU. An existing PDU is one that an application creates with a call to the
[SnmpCreatePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatepdu) function, or one that the application receives and then reads using a call to
**SnmpGetPduData**.

When an application creates a PDU with
[SnmpCreatePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatepdu), or after the application reads a PDU using
**SnmpGetPduData**, the Microsoft WinSNMP implementation expects that the application "knows" the values of the PDU fields. If an application reads a PDU a second time with
**SnmpGetPduData**, the call results in a copy of the variable bindings list of the specified PDU. This type of call to
**SnmpGetPduData** also duplicates the handle to the PDU.

## See also

[SnmpCreatePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatepdu)

[SnmpDuplicateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpduplicatevbl)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)