# DNS_NULL_DATA structure

## Description

The
**DNS_NULL_DATA** structure represents NULL data for a DNS resource record as specified in section 3.3.10 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `dwByteCount`

The number of bytes represented in **Data**.

### `size_is`

### `size_is.dwByteCount`

### `Data`

Null data.

## Remarks

The
**DNS_NULL_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)