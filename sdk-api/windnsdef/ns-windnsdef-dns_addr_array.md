# DNS_ADDR_ARRAY structure

## Description

The **DNS_ADDR_ARRAY** structure stores an array of IPv4 or IPv6 addresses.

## Members

### `MaxCount`

Indicates, the size, in bytes, of this structure.

### `AddrCount`

Indicates the number of [DNS_ADDR](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_addr) structures contained in the **AddrArray** member.

### `Tag`

Reserved. Do not use.

### `Family`

A value that specifies the IP family. Possible values are:

| Value | Meaning |
| --- | --- |
| **AF_INET6** | IPv6 |
| **AF_INET** | IPv4 |

### `WordReserved`

Reserved. Do not use.

### `Flags`

Reserved. Do not use.

### `MatchFlag`

Reserved. Do not use.

### `Reserved1`

Reserved. Do not use.

### `Reserved2`

Reserved. Do not use.

### `AddrArray`

An array of [DNS_ADDR](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_addr) structures that each contain an IP address.

### `AddrArray.size_is`

### `AddrArray.size_is.AddrCount`

## See also

[DNS_ADDR](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_addr)

[DNS_QUERY_RESULT](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windns-dns_query_result)