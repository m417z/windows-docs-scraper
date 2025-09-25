# DNS_PTR_DATAW structure

## Description

The
**DNS_PTR_DATA** structure represents a DNS pointer (PTR) record as specified in section 3.3.12 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `pNameHost`

A pointer to a string that represents the pointer (PTR) record data.

## Remarks

The
**DNS_PTR_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_PTR_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)