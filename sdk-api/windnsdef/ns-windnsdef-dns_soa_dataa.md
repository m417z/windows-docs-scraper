# DNS_SOA_DATAA structure

## Description

The
**DNS_SOA_DATA** structure represents a DNS start of authority (SOA) record as specified in section 3.3.13 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `pNamePrimaryServer`

A pointer to a string that represents the name of the authoritative DNS server for the zone to which the record belongs.

### `pNameAdministrator`

A pointer to a string that represents the name of the responsible party for the zone to which the record belongs.

### `dwSerialNo`

The serial number of the SOA record.

### `dwRefresh`

The time, in seconds, before the zone containing this record should be refreshed.

### `dwRetry`

The time, in seconds, before retrying a failed refresh of the zone to which this record belongs.

### `dwExpire`

The time, in seconds, before an unresponsive zone is no longer authoritative.

### `dwDefaultTtl`

The lower limit on the time, in seconds, that a DNS server or caching resolver are allowed to cache any resource records (RR) from the zone to which this record belongs.

## Remarks

The
**DNS_SOA_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_SOA_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)