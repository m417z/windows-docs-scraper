# AFPROTOCOLS structure

## Description

The
**AFPROTOCOLS** structure supplies a list of protocols to which application programmers can constrain queries. The
**AFPROTOCOLS** structure is used for query purposes only.

## Members

### `iAddressFamily`

Address family to which the query is to be constrained.

### `iProtocol`

Protocol to which the query is to be constrained.

## Remarks

The members of the
**AFPROTOCOLS** structure are a functional pair, and only have meaning when used together, as protocol values have meaning only within the context of an address family.

## See also

[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina)

[WSAQuerySet](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)