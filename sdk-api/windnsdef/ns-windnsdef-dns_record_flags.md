# DNS_RECORD_FLAGS structure

## Description

The
**DNS_RECORD_FLAGS** structure is used to set flags for use in the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure.

## Members

### `Section`

A [DNS_SECTION](https://learn.microsoft.com/windows/win32/api/windnsdef/ne-windnsdef-dns_section) value that specifies the section of interest returned from the
[DnsQuery](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsquery_a) function call.

### `Delete`

Reserved. Do not use.

### `CharSet`

A [DNS_CHARSET](https://learn.microsoft.com/windows/win32/api/windnsdef/ne-windnsdef-dns_charset) value that specifies the character set used in the associated function call.

### `Unused`

Reserved. Do not use.

### `Reserved`

Reserved. Do not use.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)