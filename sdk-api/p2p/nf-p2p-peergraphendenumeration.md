# PeerGraphEndEnumeration function

## Description

The **PeerGraphEndEnumeration** function releases an enumeration handle, and frees the resources associated with an enumeration.

## Parameters

### `hPeerEnum` [in]

Handle to an enumeration to release. This handle is returned by one of the following functions: [PeerGraphEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumconnections), [PeerGraphEnumNodes](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumnodes), [PeerGraphEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumrecords), or [PeerGraphSearchRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsearchrecords).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter is not valid. |
| **PEER_E_NOT_INITIALIZED** | A graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## See also

[PeerGraphEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumconnections)

[PeerGraphEnumNodes](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumnodes)

[PeerGraphEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumrecords)

[PeerGraphSearchRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsearchrecords)