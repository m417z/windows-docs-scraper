# SnmpExtensionInitEx function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft SNMP service calls the
**SnmpExtensionInitEx** function to identify any additional management information base (MIB) subtrees the SNMP extension agent supports. This function is an element of the SNMP Extension Agent API.

## Parameters

### `pNextSupportedRegion` [out]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to receive the next MIB subtree that the extension agent supports.

## Return value

If the *pNextSupportedRegion* parameter has been initialized with an additional MIB subtree, the return value is **TRUE**.

If there are no more MIB subtrees to register, the return value is **FALSE**.

## Remarks

The SNMP service repeatedly calls the
**SnmpExtensionInitEx** function entry point so the extension agent can register support for additional MIB subtrees.

The SNMP service makes a copy of the
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure the extension agent returns in the *pNextSupportedRegion* parameter. The extension agent must allocate and deallocate the resources associated with the original structure. It can do this when the SNMP service calls the
[SnmpExtensionClose](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionclose) function.

## See also

[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionClose](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionclose)

[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit)

[SnmpExtensionMonitor](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionmonitor)