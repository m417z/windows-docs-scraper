# PeerHostNameToPeerName function

## Description

The **PeerHostNameToPeerName** function decodes a host name returned by [PeerNameToPeerHostName](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peernametopeerhostname) into the peer name string it represents.

## Parameters

### `pwzHostName` [in]

Pointer to a zero-terminated Unicode string that contains the host name to decode.

### `ppwzPeerName` [out]

Pointer to the address of the zero-terminated Unicode string that contains the decoded peer name. The returned string must be released with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## See also

[PeerNameToPeerHostName](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peernametopeerhostname)