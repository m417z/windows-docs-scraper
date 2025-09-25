# SnmpUtilPrintOid function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilPrintOid** function formats the specified object identifier (OID) and prints the result to the standard output device. This function is an element of the SNMP Utility API.

## Parameters

### `Oid` [in]

Pointer to an
[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier) structure to print.

## Return value

This function does not return a value.

## Remarks

The
**SnmpUtilPrintOid** function can assist with the debugging of command-line SNMP applications. The function prints the object identifier as a sequence of numbers separated by periods ('.'); for example, 1.3.6.1.4.1.311.

## See also

[AsnObjectIdentifier](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnobjectidentifier)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilDbgPrint](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputildbgprint)