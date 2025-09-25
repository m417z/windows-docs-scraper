# DNS_MINFO_DATAW structure

## Description

The
**DNS_MINFO_DATA** structure represents a DNS mail information (MINFO) record as specified in section 3.3.7 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `pNameMailbox`

A pointer to a string that represents the [fully qualified domain name](https://learn.microsoft.com/windows/win32/dns/f-gly) (FQDN) of the mailbox responsible for the mailing list or mailbox specified in the record's owner name.

### `pNameErrorsMailbox`

A pointer to a string that represents the FQDN of the mailbox to receive error messages related to the mailing list.

## Remarks

The
**DNS_MINFO_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_MINFO_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)