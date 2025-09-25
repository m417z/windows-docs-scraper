# DNS_WINS_DATA structure

## Description

The
**DNS_WINS_DATA** structure represents a DNS Windows Internet Name Service (WINS) record.

## Members

### `dwMappingFlag`

The WINS mapping flag that specifies whether the record must be included in zone replication. **dwMappingFlag** must be one of these mutually exclusive values:

| Value | Meaning |
| --- | --- |
| **DNS_WINS_FLAG_SCOPE** | Record is not local, replicate across zones. |
| **DNS_WINS_FLAG_LOCAL** | Record is local, do not replicate. |

### `dwLookupTimeout`

The time, in seconds, that a DNS Server attempts resolution using WINS lookup.

### `dwCacheTimeout`

The time, in seconds, that a DNS Server using WINS lookup may cache the WINS Server's response.

### `cWinsServerCount`

The number of WINS Servers listed in **WinsServers**.

### `WinsServers`

An array of [IP4_ARRAY](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windns-ip4_array) structures that contain the IPv4 address of the WINS lookup Servers.

## Remarks

The
**DNS_WINS_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)