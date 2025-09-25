# DNS_NAPTR_DATAW structure

## Description

The
**DNS_NAPTR_DATA** structure represents a Naming Authority Pointer (NAPTR) DNS Resource Record (RR) as specified in [RFC 2915](https://www.ietf.org/rfc/rfc2915.txt).

## Members

### `wOrder`

 A value that determines the NAPTR RR processing order as defined in section 2 of [RFC 2915](https://www.ietf.org/rfc/rfc2915.txt).

### `wPreference`

A value that determines the NAPTR RR processing order for records with the same **wOrder** value as defined in section 2 of [RFC 2915](https://www.ietf.org/rfc/rfc2915.txt).

### `pFlags`

A pointer to a string that represents a set of NAPTR RR flags which determine the interpretation and processing of NAPTR record fields as defined in section 2 of [RFC 2915](https://www.ietf.org/rfc/rfc2915.txt).

### `pService`

A pointer to a string that represents the available services in this rewrite path as defined in section 2 of [RFC 2915](https://www.ietf.org/rfc/rfc2915.txt).

### `pRegularExpression`

A pointer to a string that represents a substitution expression as defined in sections 2 and 3 of [RFC 2915](https://www.ietf.org/rfc/rfc2915.txt).

### `pReplacement`

A pointer to a string that represents the next NAPTR query name as defined in section 2 of [RFC 2915](https://www.ietf.org/rfc/rfc2915.txt).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

## Remarks

> [!NOTE]
> The windns.h header defines DNS_NAPTR_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).