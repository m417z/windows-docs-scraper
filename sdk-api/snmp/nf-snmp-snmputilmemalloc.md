# SnmpUtilMemAlloc function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilMemAlloc** function allocates dynamic memory from the process heap. This function is an element of the SNMP Utility API.

## Parameters

### `nBytes` [in]

Specifies the number of bytes to allocate for the memory object.

## Return value

If the function succeeds, the return value is a pointer to the newly allocated memory object.

If the function fails, the return value is **NULL**.

## Remarks

Use the
[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree) function to release memory that the
**SnmpUtilMemAlloc** function allocates.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree)

[SnmpUtilMemReAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemrealloc)