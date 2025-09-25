# PeerIdentitySetFriendlyName function

## Description

The **PeerIdentitySetFriendlyName** function modifies the friendly name for a specified peer identity. The friendly name is the human-readable name.

## Parameters

### `pwzIdentity` [in]

Specifies a peer identity to modify.

### `pwzFriendlyName` [in]

Specifies a new friendly name. Specify **NULL** or an empty string to reset a friendly name to the default value, which is the Unicode version of the peer name.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |
| **PEER_E_NOT_FOUND** | A peer identity that matches a specified name cannot be found. |

## See also

[PeerIdentityGetFriendlyName](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitygetfriendlyname)