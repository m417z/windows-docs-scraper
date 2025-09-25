# SOCKADDR_IRDA structure

## Description

The
**SOCKADDR_IRDA** structure is used in conjunction with IrDA socket operations, defined by address family AF_IRDA.

## Members

### `irdaAddressFamily`

Address family. This member is always AF_IRDA.

### `irdaDeviceID`

Device identifier (ID) of the IrDA device to which the client wants to issue the
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function call. Ignored by server applications.

### `irdaServiceName`

Well-known service name associated with a server application. Specified by servers during their
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function call.

## Remarks

Client applications make use of each field in the
**SOCKADDR_IRDA** structure. The **irdaDeviceID** member is obtained by a previous discovery operation performed by making a
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)(IRLMP_ENUMDEVICES) function call. For more information on performing a discovery operation, see the Notes for IrDA Sockets section in the Remarks section of
**getsockopt**.

The **irdaServiceName** member is filled with the well-known value that the server application specified in its
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function call.

## See also

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)