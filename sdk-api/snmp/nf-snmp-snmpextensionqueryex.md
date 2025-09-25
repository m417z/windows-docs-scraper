# SnmpExtensionQueryEx function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft SNMP service calls the
**SnmpExtensionQueryEx** function to process SNMP requests that specify variables in one or more MIB subtrees registered by SNMP extension agents. This function is an element of the SNMP Extension Agent API.

**Note** It is recommended that you use the
**SnmpExtensionQueryEx** function, which supports SNMP version 2C (SNMPv2C) data types and multiphase SNMP SET operations. The SNMP service does not call the
[SnmpExtensionQuery](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionquery) function if the extension agent exports the
**SnmpExtensionQueryEx** function.

## Parameters

### `nRequestType` [in]

Specifies the type of operation that the SNMP service is requesting the extension agent to perform. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMP_EXTENSION_GET** | Retrieve the value or values of the specified variables. |
| **SNMP_EXTENSION_GET_NEXT** | Retrieve the value or values of the lexicographic successor of the specified variables. |
| **SNMP_EXTENSION_SET_TEST** | Validate the values of the specified variables. This operation maximizes the probability of a successful write during the COMMIT request. |
| **SNMP_EXTENSION_SET_COMMIT** | Write the new values to the specified variables. |
| **SNMP_EXTENSION_SET_UNDO** | Reset the values of the specified variables to their values before the COMMIT request. |
| **SNMP_EXTENSION_SET_CLEANUP** | Release the resources allocated in previous requests and operations. |

For additional information about the SET request types, that is, those that begin with SNMP_EXTENSION_SET_, see the following Remarks section.

### `nTransactionId` [in]

Specifies a **DWORD** variable that is the unique identifier of the incoming SNMP request PDU. The extension agent can use this value to correlate multiple calls by the SNMP service that involve the same PDU.

### `pVarBindList` [in, out]

Pointer to the variable binding list containing the variables of interest.

### `pContextInfo` [in, out]

Pointer to an octet string that contains user-defined context information.

The extension agent can use this parameter to store context information used during multiphase SNMP SET operations. The extension agent must release resources associated with this parameter during the
CLEANUP request. The SNMP service does not release any resources associated with this parameter. For additional information, see the following Remarks section.

### `pErrorStatus` [out]

Pointer to a variable to receive the error status result. This parameter can be one of the following values defined by SNMPv2C.

| Error code | Meaning |
| --- | --- |
| **SNMP_ERRORSTATUS_NOERROR** | The agent reports that no errors occurred during transmission. |
| **SNMP_ERRORSTATUS_TOOBIG** | The agent could not place the results of the requested SNMP operation into a single SNMP message. |
| **SNMP_ERRORSTATUS_NOSUCHNAME** | The requested SNMP operation identified an unknown variable. |
| **SNMP_ERRORSTATUS_BADVALUE** | The requested SNMP operation tried to change a variable but it specified either a syntax or value error. |
| **SNMP_ERRORSTATUS_READONLY** | The requested SNMP operation tried to change a variable that was not allowed to change, according to the community profile of the variable. |
| **SNMP_ERRORSTATUS_GENERR** | An error other than one of those listed here occurred during the requested SNMP operation. |
| **SNMP_ERRORSTATUS_NOACCESS** | The specified SNMP variable is not accessible. |
| **SNMP_ERRORSTATUS_WRONGTYPE** | The value specifies a type that is inconsistent with the type required for the variable. |
| **SNMP_ERRORSTATUS_WRONGLENGTH** | The value specifies a length that is inconsistent with the length required for the variable. |
| **SNMP_ERRORSTATUS_WRONGENCODING** | The value contains an Abstract Syntax Notation One (ASN.1) encoding that is inconsistent with the ASN.1 tag of the field. |
| **SNMP_ERRORSTATUS_WRONGVALUE** | The value cannot be assigned to the variable. |
| **SNMP_ERRORSTATUS_NOCREATION** | The variable does not exist, and the agent cannot create it. |
| **SNMP_ERRORSTATUS_INCONSISTENTVALUE** | The value is inconsistent with values of other managed objects. |
| **SNMP_ERRORSTATUS_RESOURCEUNAVAILABLE** | Assigning the value to the variable requires allocation of resources that are currently unavailable. |
| **SNMP_ERRORSTATUS_COMMITFAILED** | No validation errors occurred, but no variables were updated. |
| **SNMP_ERRORSTATUS_UNDOFAILED** | No validation errors occurred. Some variables were updated because it was not possible to undo their assignment. |
| **SNMP_ERRORSTATUS_AUTHORIZATIONERROR** | An authorization error occurred. |
| **SNMP_ERRORSTATUS_NOTWRITABLE** | The variable exists but the agent cannot modify it. |
| **SNMP_ERRORSTATUS_INCONSISTENTNAME** | The variable does not exist; the agent cannot create it because the named object instance is inconsistent with the values of other managed objects. |

### `pErrorIndex` [out]

Pointer to a variable to receive the error index result.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

The SNMP service calls the
**SnmpExtensionQueryEx** function multiple times to process an incoming SNMP SET request. The service can call
**SnmpExtensionQueryEx** during the
TEST request phase, the
COMMIT request phase, the
UNDO request phase, and the
CLEANUP request phase.

### TEST request

The SNMP service processes an SNMP SET request type by first calling the
**SnmpExtensionQueryEx** function with a *dwRequestType* of SNMP_EXTENSION_SET_TEST. The service calls each extension agent responsible for the variable bindings in the request. Each extension agent must validate the variables in the variable binding list. They can optionally store any context information required for the following requests in the variable pointed to by the *pContextInfo* parameter.

If the TEST request fails, the service initiates a CLEANUP request. The service calls each extension agent that previously returned **TRUE** to the TEST request again with the
**SnmpExtensionQueryEx** function. The service calls each extension agent using the SNMP_EXTENSION_SET_CLEANUP *dwRequestType*.

### COMMIT request

If all extension agents return **TRUE** to the TEST request, the SNMP service calls each extension agent with the
**SnmpExtensionQueryEx** function, using the SNMP_EXTENSION_SET_COMMIT *dwRequestType*. The service returns to the extension agent context information that the extension agent passed to the service. This is the context information the extension agent passed in the *pContextInfo* parameter during the TEST request. The extension agent can use the context information to update the values of the specified variables in an instrumentation-specific manner.

If the extension agent supports rollback processing, it can update the context information in the *pContextInfo* parameter at this time. The SNMP service passes the information back to the extension agent during the UNDO request.

If all extension agents return **TRUE** to the COMMIT request, the service calls each extension agent with the
**SnmpExtensionQueryEx** function, using the SNMP_EXTENSION_SET_CLEANUP *dwRequestType*.

If any extension agent fails the COMMIT request, the service also initiates a CLEANUP request. The service calls each extension agent that previously returned **TRUE** to the COMMIT request again with the
**SnmpExtensionQueryEx** function. The service calls each extension agent using the SNMP_EXTENSION_SET_CLEANUP *dwRequestType*.

### CLEANUP request

The service returns to the extension agent the context information passed in the *pContextInfo* parameter during the TEST or COMMIT request. The extension agent must release the resources associated with the parameter at this time.

### UNDO request

If any extension agent returns **FALSE** to the COMMIT request, the SNMP service terminates the COMMIT request. The service calls each extension agent that returned **TRUE** to the COMMIT request with a *dwRequestType* of SNMP_EXTENSION_SET_UNDO. This signals the extension agents that the COMMIT request failed, and they must initiate rollback processing.

The extension agents must attempt to reset the values of the variables of interest, back to the values they were before the COMMIT request failed. To do this, the extension agents use the context information returned in the *pContextInfo* parameter during the COMMIT request.

If any extension agent returns **FALSE** to the UNDO request, the entire SET operation fails with the error code SNMP_ERRORSTATUS_UNDOFAILED. If all extension agents return **TRUE** to the UNDO request, the SNMP SET operation fails with the error code set by the extension agent that failed the COMMIT request.

After the UNDO request the service always calls each extension agent with the
**SnmpExtensionQueryEx** function, using the SNMP_EXTENSION_SET_CLEANUP *dwRequestType*.

## See also

[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionQuery](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionquery)

[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist)