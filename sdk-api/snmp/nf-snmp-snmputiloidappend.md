# SnmpUtilOidAppend function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilOidAppend** function appends the source object identifier to the destination object identifier. This function is an element of the SNMP Utility API.

## Parameters

### `pOidDst` [in, out]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to receive the source structure.

### `pOidSrc` [in]

Pointer to an
**AsnObjectIdentifier** structure to append.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. This function does not generate Windows Sockets errors. The application should call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. **GetLastError** may return the following error codes.

| Return code | Description |
| --- | --- |
| **SNMP_BERAPI_OVERFLOW** | Indicates an overflow condition |
| **SNMP_MEM_ALLOC_ERROR** | Indicates a memory allocation error |

## Remarks

The
**SnmpUtilOidAppend** function calls the
[SnmpUtilMemReAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemrealloc) function. The
**SnmpUtilMemReAlloc** function expands the buffer for the destination object identifier.

Call the
[SnmpUtilOidFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidfree) function to free memory that the
**SnmpUtilOidAppend** function allocates for the destination.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilMemReAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemrealloc)

[SnmpUtilOidFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidfree)