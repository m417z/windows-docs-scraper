# DNS_NSEC_DATAA structure

## Description

The **DNS_NSEC_DATA** structure represents an NSEC resource record (RR) as specified in section 4 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

## Members

### `pNextDomainName`

A pointer to a string that represents the authoritative owner name of the next domain in the canonical ordering of the zone as specified in section 4.1.1 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

### `wTypeBitMapsLength`

The length, in bytes, of **TypeBitMaps**.

### `wPad`

Reserved. Do not use.

### `size_is`

### `size_is.wTypeBitMapsLength`

### `TypeBitMaps`

A **BYTE** array that contains a bitmap that specifies which RR types are supported by the NSEC RR owner. Each bit in the array corresponds to a [DNS Record Type](https://learn.microsoft.com/windows/win32/DNS/dns-constants) as defined in section in section 4.1.2 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

## Remarks

The
**DNS_NSEC_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_NSEC_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS Structures](https://learn.microsoft.com/windows/win32/DNS/dns-structures)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)