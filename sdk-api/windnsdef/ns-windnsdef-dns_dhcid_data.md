# DNS_DHCID_DATA structure

## Description

The **DNS_DHCID_DATA** structure represents a DNS Dynamic Host Configuration Protocol Information (DHCID) resource record (RR) as specified in section 3 of [RFC 4701](https://www.ietf.org/rfc/rfc4701.txt).

## Members

### `dwByteCount`

The length, in bytes, of **DHCID**.

### `size_is`

### `size_is.dwByteCount`

### `DHCID`

A **BYTE** array that contains the DHCID client, domain, and SHA-256 digest information as specified in section 4 of [RFC 2671](https://www.ietf.org/rfc/rfc2671.txt).

## Remarks

The
**DNS_DHCID_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS Structures](https://learn.microsoft.com/windows/win32/DNS/dns-structures)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)