# DNS_SRV_DATAA structure

## Description

The
**DNS_SRV_DATA** structure represents a DNS service (SRV) record as specified in [RFC 2782](https://www.ietf.org/rfc/rfc2782.txt).

## Members

### `pNameTarget`

A pointer to a string that represents the target host.

### `wPriority`

The priority of the target host specified in **pNameTarget**. Lower numbers imply higher priority to clients attempting to use this service.

### `wWeight`

The relative weight of the target host in **pNameTarget** to other hosts with the same **wPriority**. The chances of using this host should be proportional to its weight.

### `wPort`

The port used on the target host for this service.

### `Pad`

Reserved for padding. Do not use.

## Remarks

The
**DNS_SRV_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_SRV_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)