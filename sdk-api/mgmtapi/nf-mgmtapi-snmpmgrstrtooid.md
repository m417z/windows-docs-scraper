# SnmpMgrStrToOid function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpMgrStrToOid** function converts the string format of an object identifier to its internal object identifier structure. This function is an element of the SNMP Management API.

## Parameters

### `string` [in]

Pointer to a null-terminated string to convert.

### `oid` [out]

Pointer to an object identifier variable to receive the converted value.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If the function succeeds, call the
[SnmpUtilOidFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidfree) function to free the memory allocated for the converted object identifier.

If an application passes a valid object identifier to
**SnmpMgrStrToOid**, yet is unable to obtain the requested variable, then the syntax of the system group and object identifier is incorrect. This occurs because
**SnmpMgrStrToOid** assumes that the object identifier is under the Internet MIB of the management subtree.

You must always precede the object identifier with a period (.) to obtain the correct system group (for example, ".1.3.6.1.2.1.1"). If an application passes the variable "1.3.6.1.2.1.1",
**SnmpMgrStrToOid** cannot interpret the object identifier correctly.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpMgrOidToStr](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgroidtostr)

[SnmpUtilOidFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputiloidfree)