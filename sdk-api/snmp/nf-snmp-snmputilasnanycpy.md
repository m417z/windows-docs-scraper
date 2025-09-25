# SnmpUtilAsnAnyCpy function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilAsnAnyCpy** function copies the variable pointed to by the *pAnySrc* parameter to the *pAnyDst* parameter. The function allocates any necessary memory for the destination's copy. The
**SnmpUtilAsnAnyCpy** function is an element of the SNMP Utility API.

## Parameters

### `pAnyDst` [out]

Pointer to an
[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany) structure to receive the copy.

### `pAnySrc` [in]

Pointer to an
**AsnAny** structure to copy.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Call the
[SnmpUtilAsnAnyFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilasnanyfree) function to free the memory that the
**SnmpUtilAsnAnyCpy** function allocates for the destination structure.

## See also

[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilAsnAnyFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilasnanyfree)