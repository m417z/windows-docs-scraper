# SnmpUtilMemReAlloc function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilMemReAlloc** function changes the size of the specified memory object. This function is an element of the SNMP Utility API.

## Parameters

### `pMem` [in]

Pointer to the memory object to resize.

### `nBytes` [in]

Specifies the number of bytes to allocate for the new memory object.

## Return value

If the function succeeds, the return value is a pointer to the newly allocated memory object.

If the function fails, the return value is **NULL**.

## Remarks

Call the
[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree) function to release memory that the
**SnmpUtilMemReAlloc** function allocates.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc)

[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree)