# DNS_NXT_DATAA structure

## Description

The
**DNS_NXT_DATA** structure represents a DNS next (NXT) resource record (RR) as specified in section 5 of [RFC 2535](https://www.ietf.org/rfc/rfc2535.txt).

## Members

### `pNameNext`

A pointer to a string that represents the name of the next domain.

### `wNumTypes`

The number of elements in the **wTypes** array. **wNumTypes** must be 2 or greater but cannot exceed 8.

### `size_is`

### `size_is.wNumTypes`

### `wTypes`

A **BYTE** array that contains a bitmap which specifies the RR types that are present in the next domain. Each bit in the array corresponds to a [DNS Record Type](https://learn.microsoft.com/windows/win32/DNS/dns-constants) as defined in section 5.2 of [RFC 2535](https://www.ietf.org/rfc/rfc2535.txt).

## Remarks

The
**DNS_NXT_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_NXT_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)