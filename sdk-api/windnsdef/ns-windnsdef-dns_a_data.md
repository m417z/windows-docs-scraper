# DNS_A_DATA structure

## Description

The
**DNS_A_DATA** structure represents a DNS address (A) record as specified in section 3.4.1 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `IpAddress`

An [IP4_ADDRESS](https://learn.microsoft.com/windows/win32/DNS/dns-data-types) data type that contains an IPv4 address.

## Remarks

The
**DNS_A_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)