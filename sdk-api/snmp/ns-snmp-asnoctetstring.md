# AsnOctetString structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**AsnOctetString** structure contains octet quantities, usually bytes. This structure is used by multiple SNMP functions. This structure is not used by the
[WinSNMP API](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api) functions.

## Members

### `stream`

Pointer to the octet stream.

### `length`

The number of octets in the data stream.

### `dynamic`

Flag that specifies whether the data stream has been dynamically allocated with the
[SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc) function.

## Remarks

Use the
**AsnOctetString** structure to transfer string values. For example, use it to transfer the string that represents a computer name as a MIB object value.

You must check the flag specified in the **dynamic** member before you release the data stream of an octet string. Call the
[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree) function only if the **dynamic** member is set to **TRUE**.

## See also

[SNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/snmp-structures)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpUtilMemAlloc](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemalloc)

[SnmpUtilMemFree](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputilmemfree)