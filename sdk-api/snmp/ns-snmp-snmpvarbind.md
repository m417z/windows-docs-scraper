# SnmpVarBind structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpVarBind** structure represents an SNMP variable binding. This structure is used by multiple SNMP functions. This structure is not used by the
[WinSNMP API](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api) functions.

## Members

### `name`

Indicates the variable's name, as an object identifier.

### `value`

Contains the variable's value.

## See also

[SNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/snmp-structures)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)