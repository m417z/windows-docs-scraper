# SnmpUtilVarBindListCpy function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilVarBindListCpy** function copies the specified
[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist) structure, and allocates any necessary memory for the destination's copy. This function is an element of the SNMP Utility API.

## Parameters

### `pVblDst` [out]

Pointer to an
[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist) structure to receive the copy.

### `pVblSrc` [in]

Pointer to an
[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist) structure to copy.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Call the
[SnmpUtilVarBindListFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilvarbindlistfree) function to free memory that the
**SnmpUtilVarBindListCpy** function allocates for the destination structure.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOidCpy](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidcpy)

[SnmpUtilVarBindListFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilvarbindlistfree)

[SnmpVarBindList](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbindlist)