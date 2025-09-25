# SnmpUtilVarBindFree function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilVarBindFree** function frees the memory allocated for an
[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) structure. This function is an element of the SNMP Utility API.

## Parameters

### `pVb` [in, out]

Pointer to an
[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) structure whose memory should be freed.

## Return value

This function does not return a value.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilVarBindListFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilvarbindlistfree)

[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind)