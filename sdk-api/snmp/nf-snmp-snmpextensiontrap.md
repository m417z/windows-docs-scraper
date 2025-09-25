# SnmpExtensionTrap function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft SNMP service calls the
**SnmpExtensionTrap** function to retrieve information the service needs to generate traps for the SNMP extension agent. The service calls this function only after the extension agent sets the trap event handle to the signaled state during a call to the
[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit) function. The
**SnmpExtensionTrap** function is an element of the SNMP Extension Agent API.

## Parameters

### `pEnterpriseOid` [out]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to receive the object identifier of the enterprise that generated the trap. The SNMP service does not free the memory for this variable.

### `pGenericTrapId` [out]

Pointer to a variable to receive an indication of the generic trap. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMP_GENERICTRAP_COLDSTART** | The agent is initializing protocol entities on the managed mode. It may alter objects in its view. |
| **SNMP_GENERICTRAP_WARMSTART** | The agent is reinitializing itself but will not alter objects within its view. |
| **SNMP_GENERICTRAP_LINKDOWN** | An attached interface has changed from the "up" state to the "down" state. The first variable identifies the interface. |
| **SNMP_GENERICTRAP_LINKUP** | An attached interface has changed from the "down" state to the "up" state. The first variable identifies the interface. |
| **SNMP_GENERICTRAP_AUTHFAILURE** | An SNMP entity has sent an SNMP message, but has falsely claimed to belong to a known community. |
| **SNMP_GENERICTRAP_EGPNEIGHLOSS** | An EGP peer has changed to the down state. The first variable identifies the IP address of the EGP peer. |
| **SNMP_GENERICTRAP_ENTERSPECIFIC** | Signals an extraordinary event that is identified in the *pSpecificTrapId* parameter. |

### `pSpecificTrapId` [out]

Pointer to a variable to receive an indication of the specific trap generated.

### `pTimeStamp` [out]

Pointer to a variable to receive the time stamp. It is recommended that you initialize this parameter with the value returned by a call to the
[SnmpSvcGetUptime](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcgetuptime) function.

### `pVarBindList` [out]

Pointer to the variable bindings list. The extension agent must allocate the memory for this parameter. The SNMP service frees the memory with a call to the
[SnmpUtilVarBindListFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilvarbindlistfree) function.

## Return value

If the
**SnmpExtensionTrap** function returns a trap, the return value is **TRUE**. The SNMP service repeatedly calls the function until it returns a value of **FALSE**. For additional information, see the following Remarks section.

## Remarks

The SNMP service repeatedly calls the
**SnmpExtensionTrap** function when the *phSubagentTrapEvent* event handle is set to the signaled state. This handle is passed back during the call to the
[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit) entry point function. The
**SnmpExtensionTrap** function must return **TRUE** to indicate that the parameters contain valid data for a single trap. The function must return **FALSE** to indicate that the parameters do not represent valid trap data, and to stop the service's repeated calls.

Note that after the SNMP service sends a trap, it frees the memory associated with the variable binding list.

It is important to note that earlier documentation stated that the extension agent should dynamically allocate memory for the enterprise object identifier because the SNMP service would attempt to release the memory after sending a trap. The service will not release the memory associated with the enterprise object identifier. It is recommended that you return a pointer to a static
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure instead.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit)

[SnmpSvcGetUptime](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcgetuptime)

[SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc)

[SnmpUtilVarBindListFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilvarbindlistfree)

[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist)