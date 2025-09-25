## Description

The **LPMIPTABLE** structure contains IP information, including the SNMP index, IP address, and subnet mask for each interface. The
**LPMIPTABLE** structure is supplied as an argument for the [Lpm_IpAddressTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_ipaddresstable) function.

## Members

### `ulIfIndex`

SNMP index for the interface.

### `MediaType`

Media type of the interface.

### `IfIpAddr`

IP address for the interface.

### `IfNetMask`

IP subnet mask for the interface.

## See also

[Lpm_IpAddressTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_ipaddresstable)