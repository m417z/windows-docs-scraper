# SnmpMgrRequest function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpMgrRequest** function requests the specified operation be performed with the specified agent. This function is an element of the SNMP Management API.

## Parameters

### `session` [in]

Pointer to an internal structure that specifies the session that will perform the request.

Applications should not specify the **LPSNMP_MGR_SESSION** pointer returned by this function in a different thread. You can specify a pointer returned by
[SnmpMgrOpen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgropen), but only if the calls to
**SnmpMgrOpen** and
**SnmpMgrRequest** originate in the context of the same thread.

### `requestType` [in]

Specifies the SNMP request type. This parameter can be one of the following values defined by SNMPv1.

| Value | Meaning |
| --- | --- |
| **SNMP_PDU_GET** | Retrieve the value or values of the specified variables. |
| **SNMP_PDU_GETNEXT** | Retrieve the value or values of the lexicographic successor of the specified variable. |
| **SNMP_PDU_SET** | Write a value within a specific variable. |

Note that PDU request types have been renamed. For additional information, see
[SNMP Variable Types and Request PDU Types](https://learn.microsoft.com/windows/desktop/SNMP/snmp-variable-types-and-request-pdu-types).

### `variableBindings` [in, out]

Pointer to the variable bindings list.

**Note** The [SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) array pointed to by the [SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist) structure must be allocated using the [SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc) function.

### `errorStatus` [out]

Pointer to a variable in which the error status result will be returned. This parameter can be one of the following values defined by SNMPv1.

| Value | Meaning |
| --- | --- |
| **SNMP_ERRORSTATUS_NOERROR** | The agent reports that no errors occurred during transmission. |
| **SNMP_ERRORSTATUS_TOOBIG** | The agent could not place the results of the requested operation into a single SNMP message. |
| **SNMP_ERRORSTATUS_NOSUCHNAME** | The requested operation identified an unknown variable. |
| **SNMP_ERRORSTATUS_BADVALUE** | The requested operation tried to change a variable but it specified either a syntax or value error. |
| **SNMP_ERRORSTATUS_READONLY** | The requested operation tried to change a variable that was not allowed to change according to the community profile of the variable. |
| **SNMP_ERRORSTATUS_GENERR** | An error other than one of those listed here occurred during the requested operation. |

### `errorIndex` [out]

Pointer to a variable in which the error index result will be returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which may return one of the following error codes.

| Return code | Description |
| --- | --- |
| **SNMP_MGMTAPI_TIMEOUT** | The request timed-out. |
| **SNMP_MGMTAPI_SELECT_FDERRORS** | Unexpected error file descriptors indicated by the Windows Sockets [select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) function. |

## Remarks

Retries and time-outs are supplied to the
[SnmpMgrOpen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgropen) function. Each variable in the variable bindings list must be initialized to type ASN_NULL for Get and Get Next requests.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpMgrClose](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrclose)

[SnmpMgrOpen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgropen)