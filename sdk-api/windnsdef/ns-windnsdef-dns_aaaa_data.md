# DNS_AAAA_DATA structure

## Description

The
**DNS_AAAA_DATA** structure represents a DNS IPv6 (AAAA) record as specified in [RFC 3596](https://www.ietf.org/rfc/rfc3596.txt).

## Members

### `Ip6Address`

An [IP6_ADDRESS](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-ip6_address) data type that contains an IPv6 address.

## Remarks

The
**DNS_AAAA_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)