# SnmpExtensionClose function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft SNMP service calls the
**SnmpExtensionClose** function to request that the SNMP extension agent deallocate resources and terminate operations. This function is an element of the SNMP Extension Agent API.

## Return value

This callback function does not return a value.

## Remarks

It is not necessary for the extension agent to call its own
**SnmpExtensionClose** entry point. This is because the SNMP service calls the extension agent's
**SnmpExtensionClose** function when the service unloads the extension agent from the service's address space. The extension agent can clean up allocated resources and terminate services at this time.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit)

[SnmpExtensionInitEx](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninitex)