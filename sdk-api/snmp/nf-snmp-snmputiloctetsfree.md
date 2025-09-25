# SnmpUtilOctetsFree function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOctetsFree** function frees the memory allocated for the specified octet string. This function is an element of the SNMP Utility API.

## Parameters

### `pOctets` [in]

Pointer to an
[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring) structure whose memory should be freed.

## Return value

This function does not return a value.

## Remarks

Call the
**SnmpUtilOctetsFree** function to free the memory that the
[SnmpUtilOctetsCpy](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloctetscpy) function allocates.

## See also

[AsnOctetString](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnoctetstring)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilOctetsCpy](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloctetscpy)