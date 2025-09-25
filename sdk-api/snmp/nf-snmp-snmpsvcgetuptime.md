# SnmpSvcGetUptime function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpSvcGetUptime** function retrieves the number of centiseconds that the SNMP service has been running. This function is an element of the SNMP Utility API.

## Return value

The function returns a **DWORD** value that is the number of centiseconds the SNMP service has been running.

## Remarks

An extension agent should call the
**SnmpSvcGetUptime** function only if the extension agent DLL is loaded within the address space of the SNMP service.

The SNMP extension agent DLL is encouraged to use the
**SnmpSvcGetUptime** function to retrieve the number of centiseconds that the SNMP service has been running. Extension agents should use
**SnmpSvcGetUptime** rather than calculate the uptime using the *dwUptimeReference* parameter. The service passes this parameter to the extension agent as the result of a call to the
[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit) function. Because the *dwUptimeReference* parameter stores the elapsed time as a **DWORD** value in milliseconds, the time can wrap to zero and reflect an inaccurate time interval.

An extension agent that sends traps must initialize the *timeStamp* parameter to the
[SnmpExtensionTrap](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensiontrap) function with the value returned by a call to the
**SnmpSvcGetUptime** function.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionInit](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensioninit)

[SnmpExtensionTrap](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensiontrap)