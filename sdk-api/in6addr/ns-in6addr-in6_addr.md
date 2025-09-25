# IN6_ADDR structure

## Description

The IN6_ADDR structure specifies an IPv6 transport address.

## Members

### `u`

A union that contains the following different representations of the IPv6 transport
address:

### `u.Byte`

An array that contains 16 UCHAR-typed values.

### `u.Word`

An array that contains eight USHORT-typed values.

## Remarks

All members of the IN6_ADDR structure must be specified in network-byte-order (big-endian).

## See also

[SOCKADDR_IN6](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-sockaddr_in6_lh)