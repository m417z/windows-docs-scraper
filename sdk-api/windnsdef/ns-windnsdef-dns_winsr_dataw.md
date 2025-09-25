# DNS_WINSR_DATAW structure

## Description

The
**DNS_WINSR_DATA** structure represents a DNS Windows Internet Name Service reverse-lookup (WINSR) record.

## Members

### `dwMappingFlag`

The WINS mapping flag that specifies whether the record must be included into the zone replication. **dwMappingFlag** must be one of these mutually exclusive values:

| Value | Meaning |
| --- | --- |
| **DNS_WINS_FLAG_SCOPE** | Record is not local, replicate across zones. |
| **DNS_WINS_FLAG_LOCAL** | Record is local, do not replicate. |

### `dwLookupTimeout`

The time, in seconds, that a DNS Server attempts resolution using WINS lookup.

### `dwCacheTimeout`

The time, in seconds, that a DNS Server using WINS lookup may cache the WINS Server's response.

### `pNameResultDomain`

A pointer to a string that represents the domain name to append to the name returned by a WINS reverse-lookup.

## Remarks

The
**DNS_WINSR_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_WINSR_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)