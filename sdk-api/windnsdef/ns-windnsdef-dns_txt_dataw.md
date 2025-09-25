# DNS_TXT_DATAW structure

## Description

The
**DNS_TXT_DATA** structure represents a DNS text (TXT) record as specified in section 3.3.14 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `dwStringCount`

The number of strings represented in **pStringArray**.

### `size_is`

### `size_is.dwStringCount`

### `pStringArray`

An array of strings representing the descriptive text of the TXT resource record.

## Remarks

The
**DNS_TXT_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_TXT_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)