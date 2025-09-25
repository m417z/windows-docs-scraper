# SnmpUtilOidCpy function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOidCpy** function copies the variable pointed to by the *pOidSrc* parameter to the *pOidDst* parameter, allocating any necessary memory for the destination's copy. This function is an element of the SNMP Utility API.

## Parameters

### `pOidDst` [out]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to receive the copy.

### `pOidSrc` [in]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to copy.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Call the
[SnmpUtilOidFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidfree) function to free memory that the
**SnmpUtilOidCpy** function allocates for the destination structure.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOidFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidfree)