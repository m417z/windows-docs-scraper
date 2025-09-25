# PeerGroupUniversalTimeToPeerTime function

## Description

The **PeerGroupUniversalTimeToPeerTime** function converts a local time value from a peer's computer to a common peer group time value.

## Parameters

### `hGroup` [in]

Handle to the peer group a peer participates in. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pftUniversalTime` [in]

Pointer to the universal time value, represented as a [FILETIME](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) structure. This parameter is required.

### `pftPeerTime` [out]

Pointer to the returned peer time—Greenwich Mean Time (GMT) value that is represented as a [FILETIME](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) structure. This parameter is **NULL** if an error occurs.

## Return value

Returns **S_OK** if the function succeeds. Otherwise, the function returns either one of the RPC errors or one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_GROUP_NOT_READY** | The peer group is not in a state where peer time can be accurately calculated. For example, [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) has been called, but synchronization with the peer group database has not completed. |
| **PEER_E_NOT_INITIALIZED** | The group must be initialized with a call to [PeerGroupStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupstartup) before using this function. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

*Universal time* is the universal time value maintained on a peer's computer.

*Peer time* is a common reference time maintained by a peer group, expressed as Coordinated Universal Time (UTC). It is often offset from the universal time value, and is used to correct latency issues.

Peer time can be converted to universal time by calling the converse function [PeerGroupPeerTimeToUniversalTime](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergrouppeertimetouniversaltime).

## See also

[PeerGroupPeerTimeToUniversalTime](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergrouppeertimetouniversaltime)