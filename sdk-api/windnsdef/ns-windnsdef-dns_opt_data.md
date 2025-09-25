# DNS_OPT_DATA structure

## Description

The **DNS_OPT_DATA** structure represents a DNS Option (OPT) resource record (RR) as specified in section 4 of [RFC 2671](https://www.ietf.org/rfc/rfc2671.txt).

## Members

### `wDataLength`

The length, in bytes, of **Data**.

### `wPad`

Reserved. Do not use.

### `size_is`

### `size_is.wDataLength`

### `Data`

A **BYTE** array that contains variable transport level information as specified in section 4 of [RFC 2671](https://www.ietf.org/rfc/rfc2671.txt).

## Remarks

The
**DNS_OPT_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS Structures](https://learn.microsoft.com/windows/win32/DNS/dns-structures)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)