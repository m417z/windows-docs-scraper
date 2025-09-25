# SnmpUtilPrintAsnAny function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilPrintAsnAny** function prints the value of the *Any* parameter to the standard output. This function is an element of the SNMP Utility API.

## Parameters

### `pAny` [in]

Pointer to an
[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany) structure for a value to print.

## Return value

This function does not return a value.

## Remarks

Use the
**SnmpUtilPrintAsnAny** function for debugging and development purposes. This function does not generally print the data in a form that a manager application would typically need.

## See also

[AsnAny](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-asnany)

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)