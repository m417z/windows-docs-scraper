# SnmpUtilAsnAnyFree function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilAsnAnyFree** function frees the memory allocated for the specified
[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany) structure. This function is an element of the SNMP Utility API.

## Parameters

### `pAny` [in]

Pointer to an
[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany) structure whose memory should be freed.

## Return value

This function does not return a value.

## Remarks

Call the
**SnmpUtilAsnAnyFree** function to free the memory that the
[SnmpUtilAsnAnyCpy](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilasnanycpy) function allocates.

## See also

[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilAsnAnyCpy](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilasnanycpy)