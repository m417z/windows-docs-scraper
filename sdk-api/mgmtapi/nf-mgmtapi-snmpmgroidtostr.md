# SnmpMgrOidToStr function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpMgrOidToStr** function converts an internal object identifier structure to its string representation. This function is an element of the SNMP Management API.

## Parameters

### `oid` [in]

Pointer to an object identifier variable to convert.

### `string` [out]

Pointer to a null-terminated string to receive the converted value.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If the function succeeds, call the
[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree) function to free the memory allocated for the converted string.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpMgrStrToOid](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrstrtooid)

[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree)