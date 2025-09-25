# DRT_SCOPE enumeration

## Description

The **DRT_SCOPE** enumeration defines the set of IPv6 scopes in which DRT operates while using the IPv6 UDP transport created by [DrtCreateIpv6UdpTransport](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreateipv6udptransport).

## Constants

### `DRT_GLOBAL_SCOPE:1`

Uses the global scope.

### `DRT_SITE_LOCAL_SCOPE:2`

The **DRT_SITE_LOCAL_SCOPE** has been deprecated and should not be used.

### `DRT_LINK_LOCAL_SCOPE:3`

Uses the link local scope.

## See also

[DrtCreateIpv6UdpTransport](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreateipv6udptransport)

[DrtCreatePnrpBootstrapResolver](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreatepnrpbootstrapresolver)