# SnmpUtilOidNCmp function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOidNCmp** function compares two object identifiers. The function compares the subidentifiers in the variables until it reaches the number of subidentifiers specified by the *nSubIds* parameter.
**SnmpUtilOidNCmp** is an element of the SNMP Utility API.

## Parameters

### `pOid1` [in]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to compare.

### `pOid2` [in]

Pointer to a second
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to compare.

### `nSubIds` [in]

Specifies the number of subidentifiers to compare.

## Return value

The function returns a value greater than zero if *pOid1* is greater than *pOid2*, zero if *pOid1* equals *pOid2*, and less than zero if *pOid1* is less than *pOid2*.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOidCmp](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidcmp)