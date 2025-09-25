# PeerCreatePeerName function

## Description

The **PeerCreatePeerName** function creates a new name based on the existing name of the specified peer identity and classifier. However, a new identity is not created by a call to **PeerCreatePeerName**.

## Parameters

### `pwzIdentity` [in]

Specifies the identity to use as the basis for the new peer name. If *pwzIdentity* is **NULL**, the name created is not based on any peer identity, and is therefore an unsecured name.

This parameter can only be **NULL** if *pwzClassifier* is not **NULL**.

### `pwzClassifier` [in]

Pointer to the Unicode string that contains the new classifier. This classifier is appended to the existing authority portion of the peer name of the specified identity. This string is 150 characters long, including the **NULL** terminator. Specify **NULL** to return the peer name of the identity.

This parameter can only be **NULL** if *pwzIdentity* is not **NULL**.

### `ppwzPeerName` [out]

Pointer that receives a pointer to the new peer name. When this string is not required anymore, free it by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## Remarks

The parameter *ppwzPeername* must be set to null before the **PeerCreatePeerName** function is called.

## See also

[PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata)