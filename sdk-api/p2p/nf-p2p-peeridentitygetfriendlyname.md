# PeerIdentityGetFriendlyName function

## Description

The **PeerIdentityGetFriendlyName** function returns the friendly name of the peer identity.

## Parameters

### `pwzIdentity` [in]

Specifies the peer identity to obtain a friendly name.

### `ppwzFriendlyName` [out]

Receives a pointer to the friendly name. When *ppwzFriendlyName* is not required anymore, the application is responsible for freeing this string by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |
| **PEER_E_NOT_FOUND** | A peer identity that matches the specified name cannot be found. |

## See also

[PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata)

[PeerIdentitySetFriendlyName](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitysetfriendlyname)