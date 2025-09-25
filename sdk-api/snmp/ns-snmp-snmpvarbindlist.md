# SnmpVarBindList structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpVarBindList** structure represents an SNMP variable bindings list. This structure is used by multiple SNMP functions. This structure is not used by the
[WinSNMP API](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api) functions.

## Members

### `list`

A pointer that references an array to access individual variable bindings.

### `len`

Contains the number of variable bindings in the list.

## See also

[SNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/snmp-structures)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind)