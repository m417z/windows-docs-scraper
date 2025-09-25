# PeerIdentityGetXML function

## Description

The **PeerIdentityGetXML** function returns a description of the peer identity, which can then be passed to third parties and used to invite a peer identity into a peer group. This information is returned as an XML fragment.

## Parameters

### `pwzIdentity` [in]

Specifies the peer identity to retrieve peer identity information for. When this parameter is passed as **NULL**, a "default" identity will be generated for the user by the peer infrastructure.

### `ppwzIdentityXML` [out]

Pointer to a pointer to a Unicode string that contains the XML fragment. When *ppwzIdentityXML* is no longer required, the application is responsible for freeing this string by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The handle to the identity is invalid. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## Remarks

The XML fragment returned has the following structure:

``` syntax
<PEERIDENTITYINFO VERSION="1.0">
     <IDC xmlns:dt="urn:schemas-microsoft-com:datatypes" dt:dt="bin.base64">
          Base 64 encoded certificate.
     </IDC>
</PEERIDENTITYINFO>
```

This XML fragment is used when creating an invitation to join a group.

Applications are not allowed to add tags within the **PEERIDENTITYINFO** tag or modify this XML fragment in any way. Applications are allowed to incorporate this XML fragment into other XML documents, but must strip out all application-specific XML before passing this fragment to the [PeerGroupCreateInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreateinvitation).

## See also

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata)

[PeerGroupCreateInvitation](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreateinvitation)