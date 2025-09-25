# DNS_LOC_DATA structure

## Description

The
**DNS_LOC_DATA** structure represents a DNS location (LOC) resource record (RR) as specified in [RFC 1876](https://www.ietf.org/rfc/rfc1876.txt).

## Members

### `wVersion`

The version number of the representation. Must be zero.

### `wSize`

The diameter of a sphere enclosing the described entity, defined as "SIZE" in section 2 of [RFC 1876](https://www.ietf.org/rfc/rfc1876.txt).

### `wHorPrec`

The horizontal data precision, defined as "HORIZ PRE" in section 2 of [RFC 1876](https://www.ietf.org/rfc/rfc1876.txt).

### `wVerPrec`

The vertical data precision, defined as "VERT PRE" in section 2 of [RFC 1876](https://www.ietf.org/rfc/rfc1876.txt).

### `dwLatitude`

The latitude of the center of the sphere, defined as "LATITUDE" in section 2 of [RFC 1876](https://www.ietf.org/rfc/rfc1876.txt).

### `dwLongitude`

The longitude of the center of the sphere, defined as "LONGITUDE" in section 2 of [RFC 1876](https://www.ietf.org/rfc/rfc1876.txt).

### `dwAltitude`

The altitude of the center of the sphere, defined as "ALTITUDE" in section 2 of [RFC 1876](https://www.ietf.org/rfc/rfc1876.txt).

## Remarks

The
**DNS_LOC_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)