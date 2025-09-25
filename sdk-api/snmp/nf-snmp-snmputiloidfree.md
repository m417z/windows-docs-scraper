# SnmpUtilOidFree function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOidFree** function frees the memory allocated for the specified object identifier. This function is an element of the SNMP Utility API.

## Parameters

### `pOid` [in, out]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure whose memory should be freed.

## Return value

This function does not return a value.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOidAppend](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidappend)