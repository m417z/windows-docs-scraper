# SnmpUtilOctetsCpy function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOctetsCpy** function copies the variable pointed to by the *pOctetsSrc* parameter to the variable pointed to by the *pOctetsDst* parameter. The function allocates any necessary memory for the destination's copy. The
**SnmpUtilOctetsCpy** function is an element of the SNMP Utility API.

## Parameters

### `pOctetsDst` [out]

Pointer to an
[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring) structure to receive the copy.

### `pOctetsSrc` [in]

Pointer to an
**AsnOctetString** structure to copy.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Call the
[SnmpUtilOctetsFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloctetsfree) function to free the memory that the
**SnmpUtilOctetsCpy** function allocates for the destination structure.

## See also

[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOctetsFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloctetsfree)