# AsnObjectIdentifier structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**AsnObjectIdentifier** structure represents object identifiers. This structure is used by multiple SNMP functions. This structure is not used by the
[WinSNMP API](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api) functions.

## Members

### `idLength`

Specifies the number of integers in the object identifier.

### `ids`

Pointer to an array of integers that represents the object identifier.

## See also

[SNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/snmp-structures)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)