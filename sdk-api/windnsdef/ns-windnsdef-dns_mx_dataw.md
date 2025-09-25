# DNS_MX_DATAW structure

## Description

The
**DNS_MX_DATA** structure represents a DNS mail exchanger (MX) record as specified in section 3.3.9 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `pNameExchange`

A pointer to a string that represents the fully qualified domain name (FQDN) of the host willing to act as a mail exchange.

### `wPreference`

A preference given to this resource record among others of the same owner. Lower values are preferred.

### `Pad`

Reserved for padding. Do not use.

## Remarks

The
**DNS_MX_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_MX_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)