# PeerGroupPeerTimeToUniversalTime function

## Description

The **PeerGroupPeerTimeToUniversalTime** function converts the peer group-maintained reference time value to a localized time value appropriate for display on a peer computer.

## Parameters

### `hGroup` [in]

Handle to the peer group that a peer participates in. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pftPeerTime` [in]

Pointer to the peer time value—Coordinated Universal Time (UTC)—that is represented as a [FILETIME](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) structure. This parameter is required.

### `pftUniversalTime` [out]

Pointer to the returned universal time value that is represented as a [FILETIME](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) structure. This parameter is **NULL** if an error occurs.

## Return value

Returns **S_OK** if the function succeeds. Otherwise, the function returns either one of the remote procedure call (RPC) errors or one of the following errors.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_GROUP_NOT_READY** | The peer group is not in a state that peer time can be retrieved accurately, for example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) has been called, but synchronization with the group database has not completed. |
| **PEER_E_NOT_INITIALIZED** | The peer group must be initialized with a call to [PeerGroupStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupstartup) before using this function. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

*Universal time* is the universal time value maintained on a peer computer.

*Peer time* is a common reference time maintained by a peer group, expressed as UTC. It is often offset from the universal time value, and is used to correct latency issues.

Universal time can be converted to peer time by calling the converse function [PeerGroupUniversalTimeToPeerTime](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupuniversaltimetopeertime).

## See also

[PeerGroupUniversalTimeToPeerTime](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupuniversaltimetopeertime)