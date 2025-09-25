# DNS_ADDR structure

## Description

A **DNS_ADDR** structure stores an IPv4 or IPv6 address.

## Members

### `MaxSa`

A value that contains the socket IP address. It is a [sockaddr_in](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure if the address is IPv4 and a sockaddr_in6 structure if the address is IPv6.

### `DnsAddrUserDword`

Reserved. Must be 0.

## See also

[DNS_ADDR_ARRAY](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_addr_array)

[DNS_QUERY_RESULT](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windns-dns_query_result)