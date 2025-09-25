# SnmpSetPduData function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpSetPduData** function updates selected data fields in the specified SNMP protocol data unit (PDU).

## Parameters

### `PDU` [in]

Handle to an SNMP PDU.

### `PDU_type` [in]

Pointer to a variable with a value to update the **PDU_type** field of the specified PDU. This parameter can also be **NULL**.

### `request_id` [in]

Pointer to a variable with a value to update the **request_id** field of the specified PDU. This parameter can also be **NULL**.

### `non_repeaters` [in]

If the *PDU_type* parameter is equal to [SNMP_PDU_GETBULK](https://learn.microsoft.com/windows/desktop/SNMP/snmp-variable-types-and-request-pdu-types), this parameter points to a variable with a value to update the **non_repeaters** field of the specified PDU. The Microsoft WinSNMP implementation ignores this parameter for other PDU types. This parameter can also be **NULL**.

### `max_repetitions` [in]

If the *PDU_type* parameter is equal to [SNMP_PDU_GETBULK](https://learn.microsoft.com/windows/desktop/SNMP/snmp-variable-types-and-request-pdu-types), this parameter points to a variable with a value to update the **max_repetitions** field of the specified PDU. The implementation ignores this parameter for other PDU types. This parameter can also be **NULL**.

### `varbindlist` [in]

Pointer to a variable with a value that updates the handle to the variable bindings list field of the specified PDU. This parameter can also be **NULL**.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_PDU_INVALID** | The PDU type is invalid. |
| **SNMPAPI_VBL_INVALID** | The variable bindings list is invalid. |
| **SNMPAPI_NOOP** | All input parameters are **NULL**. The SNMP operation was not performed. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

All parameters of the
**SnmpSetPduData** function are required. However, all parameters, except the *PDU* parameter, can be **NULL**. If the WinSNMP application passes **NULL** in a parameter,
**SnmpSetPduData** does not update the corresponding field in the PDU. Because
**SnmpSetPduData** passes parameters as pointers to values, an application can still update a PDU field with **NULL**.

The value of one PDU field can be valid alone, but may be invalidated in combination with values for other fields. The implementation validates the PDU and the other message elements when the application calls the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) or the
[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg) functions. The implementation rejects invalid PDUs.

The only type of trap PDU you can update with a call to the
**SnmpSetPduData** function is an SNMPv2C trap PDU.

## See also

[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)