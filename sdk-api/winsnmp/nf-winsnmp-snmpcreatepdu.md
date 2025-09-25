# SnmpCreatePdu function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpCreatePdu** function creates and initializes an SNMP protocol data unit (PDU).

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `PDU_type` [in]

Specifies a PDU type that identifies the SNMP operation. This parameter can be **NULL**, or it can be one of the following values. If this parameter is **NULL**, the Microsoft WinSNMP implementation supplies the default PDU type SNMP_PDU_GETNEXT. The only type of trap PDU you can create with a call to the
**SnmpCreatePdu** function is an SNMPv2C trap PDU.

| Value | Meaning |
| --- | --- |
| **SNMP_PDU_GET** | Search and retrieve a value from a specified SNMP variable. |
| **SNMP_PDU_GETNEXT** | Search and retrieve the value of an SNMP variable without knowing the exact name of the variable. |
| **SNMP_PDU_RESPONSE** | Reply to an SNMP_PDU_GET or an SNMP_PDU_GETNEXT request. |
| **SNMP_PDU_SET** | Store a value in a specified SNMP variable. |
| **SNMP_PDU_GETBULK** | Search and retrieve multiple values with a single request. |
| **SNMP_PDU_TRAP** | Alerts the management system to an event under SNMPv2C. |

### `request_id` [in]

Specifies a unique numeric value that the WinSNMP application supplies to identify the PDU. If this parameter is **NULL**, the implementation assigns a value.

### `error_status` [in]

If the *PDU_type* parameter is equal to **SNMP_PDU_GETBULK**, this parameter specifies a value for the **non_repeaters** field of the PDU. For other PDU types, this parameter specifies a value for the **error_status** field of the PDU. This parameter can be **NULL**.

### `error_index` [in]

If the *PDU_type* parameter is equal to **SNMP_PDU_GETBULK**, this parameter specifies a value for the **max_repetitions** field of the PDU. For other PDU types, this parameter specifies a value for the **error_index** field of the PDU. This parameter can be **NULL**.

### `varbindlist` [in]

Handle to a structure that represents an SNMP variable bindings list. This parameter can be **NULL**.

## Return value

If the function succeeds, the return value is the handle to a new SNMP PDU.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The session handle is invalid. |
| **SNMPAPI_PDU_INVALID** | The PDU type is invalid. |
| **SNMPAPI_VBL_INVALID** | The variable bindings list is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

A WinSNMP application must create a PDU before it calls the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) or the
[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg) functions.

All of the parameters of the
**SnmpCreatePdu** function are required. However, all parameters, except the *session* parameter, can be **NULL**. In this instance, the new PDU has the following default values.

| Field | Contents |
| --- | --- |
| **PDU_type** | **SNMP_PDU_GETNEXT** |
| **request_id** | The implementation generates a numeric value. |
| **error_status** | SNMP_ERROR_NOERROR |
| **error_index** | 0 |
| **varbindlist** | **NULL** |

The application must call the
[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu) function to release the resources that the
**SnmpCreatePdu** function allocates for the new PDU.

## See also

[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg)

[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)