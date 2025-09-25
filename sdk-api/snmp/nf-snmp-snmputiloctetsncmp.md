# SnmpUtilOctetsNCmp function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOctetsNCmp** function compares two octet strings. The function compares the subidentifiers in the strings until it reaches the number of subidentifiers specified by the *nChars* parameter.
**SnmpUtilOctetsNCmp** is an element of the SNMP Utility API.

## Parameters

### `pOctets1` [in]

Pointer to an
[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring) structure to compare.

### `pOctets2` [in]

Pointer to a second
**AsnOctetString** structure to compare.

### `nChars` [in]

Specifies the number of subidentifiers to compare.

## Return value

The function returns a value greater than zero if *pOctets1* is greater than *pOctets2*, zero if *pOctets1* equals *pOctets2*, and less than zero if *pOctets1* is less than *pOctets2*.

## Remarks

The
[SnmpUtilOctetsCmp](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloctetscmp) function calls the
**SnmpUtilOctetsNCmp** function.

## See also

[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOctetsCmp](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloctetscmp)