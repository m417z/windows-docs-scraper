# _WWAN_IPADDRESS_ENTRY structure

## Description

The WWAN_IPADDRESS_ENTRY structure represents either the IPV4 or IPV6 address of a PDP context.

## Members

### `IsIpv6`

Set if the IP address of the PDP context is an IPV6 address.

### `IsReported`

Reserved. Do not use.

### `Ipv4`

The IPV4 address of the PDP context, if **IsIpv6** is not set.

### `Ipv6`

The IPV6 address of the PDP context, if **IsIpv6** is set.