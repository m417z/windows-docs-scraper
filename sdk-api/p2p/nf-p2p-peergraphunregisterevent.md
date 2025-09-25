# PeerGraphUnregisterEvent function

## Description

The **PeerGraphUnregisterEvent** function requests that the application no longer be notified of changes associated with a peer graph and record type.

## Parameters

### `hPeerEvent` [in]

Peer event handle obtained from call to [PeerGraphRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphregisterevent).

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The parameter is not valid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

The peer event handle passed to [PeerGraphRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphregisterevent) must be closed only after **PeerGraphUnregisterEvent** has been called.

## See also

[PeerRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphregisterevent)