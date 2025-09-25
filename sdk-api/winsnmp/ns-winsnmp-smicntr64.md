# smiCNTR64 structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**smiCNTR64** structure contains a 64-bit unsigned integer value. The structure represents a 64-bit counter.

## Members

### `hipart`

Specifies the high-order 32 bits of the counter.

### `lopart`

Specifies the low-order 32 bits of the counter.

## See also

[SnmpGetVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetvb)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[WinSNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-structures)

[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue)