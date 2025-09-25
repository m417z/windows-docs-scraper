# SnmpDeleteVb function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpDeleteVb** function removes a variable binding entry from a variable bindings list.

## Parameters

### `vbl` [in]

Handle to the variable bindings list to update.

### `index` [in]

Specifies an unsigned long integer variable that identifies the variable binding entry to remove. This variable contains the position of the variable binding entry, within the variable bindings list.

Valid values for this parameter are in the range from 1 to n, where 1 indicates the first variable binding entry in the variable bindings list, and n is the total number of entries in the variable bindings list. For additional information, see the following Remarks section.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_INDEX_INVALID** | The *index* parameter is invalid. |
| **SNMPAPI_VBL_INVALID** | The *vbl* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

A WinSNMP application can use the
**SnmpDeleteVb** function to delete invalid variable binding entries. When an [SNMP_PDU_RESPONSE](https://learn.microsoft.com/windows/desktop/SNMP/snmp-variable-types-and-request-pdu-types) protocol data unit (PDU) includes an error that indicates an invalid variable binding entry, the application can call
**SnmpDeleteVb** to delete the entry. Then the application can resubmit the request PDU with a call to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) function, without the invalid variable binding entry in the variable bindings list. Request PDUs include the SNMP_PDU_GET, SNMP_PDU_GETNEXT, and SNMP_PDU_GETBULK PDU data types.

After the
**SnmpDeleteVb** function deletes a variable binding entry, the index value of all entries after the deleted entry will decrement by one. A call to the
[SnmpCountVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcountvbl) function returns the new total number of entries in the variable bindings list. The new total is one less than the count returned by a call to
**SnmpCountVbl** before the current call to
**SnmpDeleteVb**.

If a WinSNMP application calls the
**SnmpDeleteVb** function and deletes the last variable binding entry in a variable bindings list, the result is an empty variable bindings list. The variable bindings list still has a valid handle and the WinSNMP application must release the handle with a call to the
[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl) function.

The following are valid values to use for the *index* parameter:

* The return value from a call to the
  [SnmpCountVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcountvbl) function
* The error index field of an [SNMP_PDU_RESPONSE](https://learn.microsoft.com/windows/desktop/SNMP/snmp-variable-types-and-request-pdu-types) PDU returned by a call to the
  [SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function

## See also

[SnmpCountVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcountvbl)

[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl)

[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)