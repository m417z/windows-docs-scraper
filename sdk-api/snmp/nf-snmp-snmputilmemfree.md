# SnmpUtilMemFree function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilMemFree** function frees the specified memory object. This function is an element of the SNMP Utility API.

## Parameters

### `pMem` [in, out]

Pointer to the memory object to release.

## Return value

This function does not return a value.

## Remarks

Call the
[SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc) function to allocate the memory for the object.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc)

[SnmpUtilMemReAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemrealloc)