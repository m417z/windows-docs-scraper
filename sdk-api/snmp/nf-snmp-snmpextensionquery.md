# SnmpExtensionQuery function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft SNMP service calls the
**SnmpExtensionQuery** function to resolve SNMP requests that contain variables within one or more of the SNMP extension agent's registered MIB subtrees. This function is an element of the SNMP Extension Agent API.

**Note** It is recommended that you use the
[SnmpExtensionQueryEx](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionqueryex) function, which supports SNMP version 2C (SNMPv2C) data types and multiphase SNMP SET operations.

## Parameters

### `bPduType` [in]

Specifies the SNMP version 1 (SNMPv1) PDU request type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMP_PDU_GET** | Retrieve the value or values of the specified variables. |
| **SNMP_PDU_GETNEXT** | Retrieve the value or values of the lexicographic successor of the specified variable. |
| **SNMP_PDU_SET** | Write a value within a specific variable. |

Note that PDU request types have been renamed. For additional information, see
[SNMP Variable Types and Request PDU Types](https://learn.microsoft.com/windows/desktop/SNMP/snmp-variable-types-and-request-pdu-types).

### `pVarBindList` [in, out]

Pointer to the variable bindings list.

### `pErrorStatus` [out]

Pointer to a variable in which the error status result will be returned. This parameter can be one of the following values defined by SNMPv1.

| Value | Meaning |
| --- | --- |
| **SNMP_ERRORSTATUS_NOERROR** | The agent reports that no errors occurred during transmission. |
| **SNMP_ERRORSTATUS_TOOBIG** | The agent could not place the results of the requested operation into a single SNMP message. |
| **SNMP_ERRORSTATUS_NOSUCHNAME** | The requested operation identified an unknown variable. |
| **SNMP_ERRORSTATUS_BADVALUE** | The requested operation tried to change a variable but it specified either a syntax or value error. |
| **SNMP_ERRORSTATUS_READONLY** | The requested operation tried to change a variable that was not allowed to change according to the community profile of the variable. |
| **SNMP_ERRORSTATUS_GENERR** | An error other than one of those listed here occurred during the requested operation. |

### `pErrorIndex` [out]

Pointer to a variable in which the error index result will be returned.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

When the SNMP service receives an SNMP PDU request, it calls the
**SnmpExtensionQuery** function to process the request. The extension agent must follow the rules in RFC 1157 to either resolve the variable bindings or generate an error.

If the extension agent cannot resolve the variable bindings on a **Get Next** request, it must change the **name** field of the
[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) structure to the value of the object identifier immediately following that of the currently supported MIB subtree view. For example, if the extension agent supports view ".1.3.6.1.4.1.77.1", a **Get Next** request on ".1.3.6.1.4.1.77.1.5.1" would result in a modified **name** field of ".1.3.6.1.4.1.77.2". This signals the SNMP service to continue the attempt to resolve the variable bindings with other extension agents.

It is important to note that the SNMP service and the extension agent may need to exchange dynamically allocated memory during a call to the
**SnmpExtensionQuery** function. The service dynamically allocates the object identifier in each
[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) structure it passes to the extension agent. However, the extension agent must release this memory in order to replace the object identifier when it processes a **Get Next** request. The extension agent allocates dynamic memory for variable-length object types. The SNMP service releases this memory after the object is placed in the response PDU.

In order to avoid heap corruption and memory leaks, both the SNMP service and the extension agent must use memory allocation routines that resolve to the same heap. The extension agent must use the
[SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc) function to allocate memory that it passes to the SNMP service. It must use the
[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree) function to release the memory the service passes back to the extension agent. These functions are located in the utility dynamic-link library SNMPAPI.DLL.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit)

[SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc)

[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree)

[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind)