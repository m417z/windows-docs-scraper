# NET_ADDRESS_FORMAT enumeration

## Description

The **NET_ADDRESS_FORMAT** enumeration specifies the format of a network address returned by the [ParseNetworkString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-parsenetworkstring) function.

## Constants

### `NET_ADDRESS_FORMAT_UNSPECIFIED:0`

The format of the network address is unspecified.

### `NET_ADDRESS_DNS_NAME`

The format of the network address is a DNS name.

### `NET_ADDRESS_IPV4`

The format of the network address is a string in Internet standard dotted-decimal notation for IPv4.

### `NET_ADDRESS_IPV6`

The format of the network address is a string in Internet standard hexadecimal encoding for IPv6.

## Remarks

The **NET_ADDRESS_FORMAT** enumeration is defined on Windows Vista and later.

The [NET_ADDRESS_INFO](https://learn.microsoft.com/windows/desktop/api/iphlpapi/ns-iphlpapi-net_address_info) structure returned by the [ParseNetworkString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-parsenetworkstring) function.

## See also

[NET_ADDRESS_INFO](https://learn.microsoft.com/windows/desktop/api/iphlpapi/ns-iphlpapi-net_address_info)

[ParseNetworkString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-parsenetworkstring)