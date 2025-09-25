# PeerNameToPeerHostName function

## Description

The **PeerNameToPeerHostName** function encodes the supplied peer name as a format that can be used with a subsequent call to the [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) Windows Sockets function.

## Parameters

### `pwzPeerName` [in]

Pointer to a zero-terminated Unicode string that contains the peer name to encode as a host name.

### `ppwzHostName` [out]

Pointer to the address of the zero-terminated Unicode string that contains the encoded host name. This string can be passed to [getaddrinfo_v2](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) to obtain network information about the peer.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## See also

[PeerHostNameToPeerName](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerhostnametopeername)