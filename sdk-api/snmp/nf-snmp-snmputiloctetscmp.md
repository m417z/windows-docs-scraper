# SnmpUtilOctetsCmp function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOctetsCmp** function compares two octet strings. This function is an element of the SNMP Utility API.

## Parameters

### `pOctets1` [in]

Pointer to an
[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring) structure to compare.

### `pOctets2` [in]

Pointer to a second
**AsnOctetString** structure to compare.

## Return value

The function returns a value greater than zero if *pOctets1* is greater than *pOctets2*, zero if *pOctets1* equals *pOctets2*, and less than zero if *pOctets1* is less than *pOctets2*.

## Remarks

The
**SnmpUtilOctetsCmp** function calls the
[SnmpUtilOctetsNCmp](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloctetsncmp) function.

## See also

[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOctetsNCmp](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloctetsncmp)