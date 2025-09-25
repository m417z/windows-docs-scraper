# PeerIdentityDelete function

## Description

The **PeerIdentityDelete** function permanently deletes a peer identity. This includes removing all certificates, private keys, and all group information associated with a specified peer identity.

## Parameters

### `pwzIdentity` [in]

Specifies a peer identity to delete.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The parameter is not valid. |
| **PEER_E_GROUPS_EXIST** | The peer identity cannot be deleted because it has peer groups associated with it. All peer groups associated with the specified identity must be deleted by using [PeerGroupDelete](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupdelete) before a call to [PeerIdentityDelete](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitydelete) can succeed. |
| **PEER_E_NOT_FOUND** | A peer identity that matches the specified name cannot be found. |