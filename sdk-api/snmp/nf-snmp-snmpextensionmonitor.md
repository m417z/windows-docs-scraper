# SnmpExtensionMonitor function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft SNMP service calls the
**SnmpExtensionMonitor** function to provide the SNMP extension agent with a view to the service's internal counters and parameters. This function is an element of the SNMP Extension Agent API.

The
**SnmpExtensionMonitor** function is optional. Extension agents should implement the function if they are interested in a view of the SNMP service's internal management objects, as defined in RFC 1213, "Management Information Base for Network Management of TCP/IP-based internets: MIB-II."

## Parameters

### `pAgentMgmtData` [in]

Pointer to an array of
[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany) objects (structures). The number of objects, and the type and description of each object, are in accordance with RFC 1213. For more information, see the following Remarks section.

## Return value

Unless an unexpected error occurs while the SNMP extension agent is processing the value of the *pAgentMgmtData* parameter, the extension agent should return **TRUE**. If the extension agent returns **FALSE**, the SNMP service does not load the extension agent, and the service stops directing SNMP requests to the extension agent.

## Remarks

If the extension agent exports the
**SnmpExtensionMonitor** function, the SNMP service calls the function during initialization of the extension agent, immediately after the service calls the
[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit) and the
[SnmpExtensionInitEx](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninitex) functions.

The SNMP service dynamically updates the SNMP counters (for example, the snmpInPkts and the snmpOutNoSuchNames counters) in the array pointed to by the *pAgentMgmtData* parameter. In order to be able to read these values while the SNMP service is running, the extension agent must store the pointer to *pAgentMgmtData*.

Note that an SNMP extension agent should not update the memory pointed to by the *pAgentMgmtData* parameter. This is because the values of the SNMP service's internal counters would no longer be valid, and the behavior of the SNMP service could become unpredictable. As long as the extension agent does not alter it, the memory pointed to by *pAgentMgmtData* is valid while the SNMP service is running.

## See also

[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionClose](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionclose)

[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit)

[SnmpExtensionInitEx](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninitex)