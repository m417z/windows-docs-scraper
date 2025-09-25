# SnmpUtilVarBindCpy function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilVarBindCpy** function copies the specified
[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) structure, and allocates any memory necessary for the destination structure. The
**SnmpUtilVarBindCpy** function is an element of the SNMP Utility API.

## Parameters

### `pVbDst` [out]

Pointer to an
[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) structure to receive the copy.

### `pVbSrc` [in]

Pointer to an
[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) structure to copy.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Call the
[SnmpUtilVarBindFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilvarbindfree) function to free memory that the
**SnmpUtilVarBindCpy** function allocates for the destination structure.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilVarBindFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilvarbindfree)

[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind)