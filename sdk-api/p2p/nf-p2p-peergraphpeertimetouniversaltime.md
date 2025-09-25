# PeerGraphPeerTimeToUniversalTime function

## Description

The **PeerGraphPeerTimeToUniversalTime** function converts the peer graph-maintained reference time value to a localized time value appropriate for display on the peer's computer.

## Parameters

### `hGraph` [in]

Handle to the peer graph this peer participates in. This handle is returned by the [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate), or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen) function.

### `pftPeerTime` [in]

Pointer to the peer time (UTC) value, represented as a [FILETIME](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) structure.

### `pftUniversalTime` [out]

Pointer to the returned universal time value, represented as a [FILETIME](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) structure.

## Return value

Returns S_OK if the function succeeds; otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_INVALID_GRAPH** | The handle to the graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

*Universal time* is the UTC time derived from the peer's system clock.

*Peer time* is a common reference time maintained by the peer graph, expressed as Greenwich Mean Time.

Peer time should be converted to universal time whenever it is necessary to display this value on the peer's computer, such as when displaying the creation time of a record. Likewise, time-sensitive actions, such as setting the expiration time for a record or searching for records based on modification time, should use time values converted from the computer-specific universal time to graph-specific peer time.

Universal time can be converted to peer time by calling the converse function [PeerGraphUniversalTimeToPeerTime](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphuniversaltimetopeertime).

## See also

[PeerGraphUniversalTimeToPeerTime](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphuniversaltimetopeertime)