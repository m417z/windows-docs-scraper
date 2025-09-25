# SnmpExtensionInit function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft SNMP service calls the
**SnmpExtensionInit** function to initialize the SNMP extension agent DLL. This function is an element of the SNMP Extension Agent API.

## Parameters

### `dwUptimeReference` [in]

Specifies a time-zero reference for the extension agent.

**Note** Extension agents should ignore this parameter. The SNMP extension agent DLL should use the
[SnmpSvcGetUptime](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcgetuptime) function to retrieve the number of centiseconds the SNMP service has been running. For more information, see the following Remarks section.

### `phSubagentTrapEvent` [out]

Pointer to an event handle the extension agent passes back to the SNMP service. This handle is used to notify the service that the extension agent has one or more traps to send. For additional information about allocating and deallocating the event handle, see the following Remarks section.

### `pFirstSupportedRegion` [out]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to receive the first MIB subtree that the extension agent supports. For additional information about allocating and deallocating resources for this structure, see the following Remarks section.

The extension agent can register additional MIB subtrees by implementing the
[SnmpExtensionInitEx](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninitex) entry point function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

Extension agents should ignore the *dwUptimeReference* parameter. Instead, they should call the
[SnmpSvcGetUptime](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcgetuptime) function to retrieve the number of centiseconds that the Microsoft SNMP service has been running. Because the *dwUptimeReference* parameter stores the elapsed time as a **DWORD** value in milliseconds, the time can wrap to zero and reflect an inaccurate time interval.

The extension agent notifies the SNMP service that it needs to send one or more traps by setting the event handle passed back in the *phSubagentTrapEvent* parameter to the signaled state. After this event has been signaled, the SNMP service repeatedly calls the extension agent's
[SnmpExtensionTrap](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensiontrap) entry point until the function returns a value of **FALSE**. This indicates that the extension agent has no more traps to send. If the extension agent does not generate traps, the *phSubagentTrapEvent* parameter should return a value of **NULL**.

The SNMP extension agent must allocate and deallocate resources for the trap event handle. When the SNMP service calls the
**SnmpExtensionInit** function, the extension agent must call the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to allocate the event handle. The extension agent passes the handle to the SNMP service in the *phSubagentTrapEvent* parameter. When the SNMP service calls the
[SnmpExtensionClose](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionclose) function, the extension agent must deallocate resources for the trap event handle.

The SNMP service makes a copy of the
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure the extension agent returns in the *pFirstSupportedRegion* parameter. The extension agent must allocate and deallocate the resources associated with the original structure. It can do this when the SNMP service calls the
[SnmpExtensionClose](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionclose) function.

## See also

[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier)

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionClose](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionclose)

[SnmpExtensionMonitor](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionmonitor)

[SnmpExtensionTrap](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensiontrap)

[SnmpSvcGetUptime](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcgetuptime)