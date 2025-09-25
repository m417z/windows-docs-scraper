# NC_ADDRESS structure

## Description

Contains information that describes a network address.

## Members

### `pAddrInfo`

Type: **[NET_ADDRESS_INFO](https://learn.microsoft.com/windows/desktop/shell/hkey-type)***

A pointer to a [NET_ADDRESS_INFO](https://learn.microsoft.com/windows/desktop/shell/hkey-type) structure that describes the network address, either a named address or an IP address.

### `PortNumber`

Type: **USHORT**

The network port number, if the address described by **pAddrInfo** is an IP address.

### `PrefixLength`

Type: **BYTE**

The prefix length corresponding to the address, if the address described by **pAddrInfo** is an IP address.

## Remarks

This structure is sent with the [NetAddr_GetAddress](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-netaddr_getaddress) macro.