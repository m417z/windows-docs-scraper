# SnmpMgrGetTrapEx function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpMgrGetTrapEx** function returns outstanding trap data that the caller has not received if trap reception is enabled. In addition to the information that is returned by the
[SnmpMgrGetTrap](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrgettrap) function, this extended function returns the address of the transport source and the community string of the trap. This function is an element of the SNMP Management API.

## Parameters

### `enterprise` [out]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to receive the enterprise that generated the SNMP trap.

### `agentAddress` [out]

Pointer to a variable to receive the address of the agent that generated the SNMP trap; this information is retrieved from the SNMP protocol data unit (PDU).

### `sourceAddress` [out]

Pointer to a variable to receive the address of the agent that generated the SNMP trap; this information is retrieved from the network transport.

### `genericTrap` [out]

Pointer to a variable to receive an indicator of the generic trap. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMP_GENERICTRAP_COLDSTART** | The agent is initializing protocol entities on the managed mode. It may alter objects in its view. |
| **SNMP_GENERICTRAP_WARMSTART** | The agent is reinitializing itself but it will not alter objects in its view. |
| **SNMP_GENERICTRAP_LINKDOWN** | An attached interface has changed from the up state to the down state. The first variable in the variable bindings list identifies the interface. |
| **SNMP_GENERICTRAP_LINKUP** | An attached interface has changed from the down state to the up state. The first variable in the variable bindings list identifies the interface. |
| **SNMP_GENERICTRAP_AUTHFAILURE** | An SNMP entity has sent an SNMP message, but it has falsely claimed to belong to a known community. |
| **SNMP_GENERICTRAP_EGPNEIGHLOSS** | An EGP peer has changed to the down state. The first variable in the variable bindings list identifies the IP address of the EGP peer. |
| **SNMP_GENERICTRAP_ENTERSPECIFIC** | An extraordinary event has occurred. It is identified in the *specificTrap* parameter with an enterprise-specific value. |

### `specificTrap` [out]

Pointer to a variable to receive an indicator of the specific trap generated.

### `community` [out]

Pointer to an
[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring) structure to receive the community string of the generated SNMP trap.

### `timeStamp` [out]

Pointer to a variable to receive the time stamp.

### `variableBindings` [out]

Pointer to an
[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist) structure to receive the variable bindings list.

## Return value

If the function returns a trap, the return value is nonzero.

You should call the
**SnmpMgrGetTrapEx** function repeatedly until it returns zero. The function may also return the following error codes.

| Return code | Description |
| --- | --- |
| **SNMP_MGMTAPI_TRAP_ERRORS** | Indicates that errors were encountered; traps are not accessible. |
| **SNMP_MGMTAPI_NOTRAPS** | Indicates that no traps are available. |
| **SNMP_MEM_ALLOC_ERROR** | Indicates a memory allocation error. |

## Remarks

The application must always call the
[SnmpMgrTrapListen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrtraplisten) function before calling the
**SnmpMgrGetTrapEx** function. This is because the event handle that is pointed to by the *phTrapAvailable* parameter of the
[SnmpMgrTrapListen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrtraplisten) function enables the event-driven acquisition of SNMP traps. The SNMP Management API signals an application event when the SNMP Trap Service delivers a trap.

The application can also poll the
**SnmpMgrGetTrapEx** function for traps at regular intervals. In this case, the application should repeatedly call
**SnmpMgrGetTrapEx** until the function returns zero.

## See also

[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier)

[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpMgrTrapListen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrtraplisten)

[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist)