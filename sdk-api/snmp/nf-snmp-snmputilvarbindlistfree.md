# SnmpUtilVarBindListFree function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilVarBindListFree** function frees the memory allocated for an
[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist) structure. This function is an element of the SNMP Utility API.

## Parameters

### `pVbl` [in, out]

Pointer to an
[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist) structure whose allocated memory should be freed.

## Return value

This function has no return values.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilVarBindFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilvarbindfree)

[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist)