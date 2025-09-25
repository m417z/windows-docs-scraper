# SnmpUtilOidToA function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOidToA** function converts an object identifier (OID) to a null-terminated string. This function is an element of the SNMP Utility API.

## Parameters

### `Oid` [in]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to convert.

## Return value

The function returns a null-terminated string of characters that contains the string representation of the object identifier pointed to by the *Oid* parameter.

## Remarks

The
**SnmpUtilOidToA** function can assist with the debugging of SNMP applications.

For more information, see the
[SnmpUtilIdsToA](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilidstoa) function.
**SnmpUtilOidToA** calls
**SnmpUtilIdsToA** internally to format the string.

## See also

[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilIdsToA](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilidstoa)