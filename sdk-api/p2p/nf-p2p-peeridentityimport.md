# PeerIdentityImport function

## Description

The **PeerIdentityImport** function imports one peer identity. If the peer identity exists on a computer, **PEER_E_ALREADY_EXISTS** is returned.

## Parameters

### `pwzImportXML` [in]

Pointer to the XML format peer identity to import, which is returned by [PeerIdentityExport](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentityexport). This binary data must match the exported data byte-for-byte. The XML must remain valid XML with no extra
characters.

### `pwzPassword` [in]

Specifies the password to use to de-crypt a peer identity. The password must be identical to the password supplied to [PeerIdentityExport](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentityexport). This parameter cannot be **NULL**.

### `ppwzIdentity` [out]

Pointer to a string that represents a peer identity that is imported. If the import operation is successful, the application must free *ppwzIdentity* by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid, or the XML data in *ppwzImportXML* has been tampered with. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_ALREADY_EXISTS** | The peer identity already exists on this computer. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been reset manually. |

## Remarks

The XML fragment used by **PeerIdentityImport** is as follows:

``` syntax
<PEERIDENTITYEXPORT VERSION="1.0">
   <IDENTITY>
     <!-- UTF-8 encoded peer name of the identity -->
   </IDENTITY>
   <IDENTITYDATA xmlns:dt="urn:schemas-microsoft-com:datatypes" dt:dt="bin.base64">
      <!-- base64 encoded / PFX encoded and encrypted IDC with the private key -->
   </IDENTTYDATA>
</PEERIDENTITYEXPORT>

```

## See also

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data)

[PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata)

[PeerIdentityExport](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentityexport)