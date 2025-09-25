# PeerIdentityExport function

## Description

The **PeerIdentityExport** function allows a user to export one peer identity. The user can then transfer the peer identity to a different computer.

## Parameters

### `pwzIdentity` [in]

Specifies the peer identity to export. This parameter is required and does not have a default value.

### `pwzPassword` [in]

Specifies the password to use to encrypt the peer identity. This parameter cannot be **NULL**. This password must also be used to import the peer identity, or the import operation fails.

### `ppwzExportXML` [out]

Receives a pointer to the exported peer identity in XML format. If the export operation is successful, the application must free *ppwzExportXML* by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys was denied. This is typically caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been manually reset. |
| **PEER_E_NOT_FOUND** | The specified peer identity does not exist. |

## Remarks

Peer-to-peer group membership credentials are not exported. Only one peer identity is exported. An exported peer identity can be imported on another computer by using [PeerIdentityImport](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentityimport).

Exporting a peer identity does not remove it from a local ccmputer, it makes a copy of it. The copy can be used to backup and restore a peer identity.

The XML fragment used by **PeerIdentityExport** is as follows:

``` syntax
<PEERIDENTITYEXPORT VERSION="1.0">
   <PEERNAME>
     <!-- UTF-8 encoded peer name of the identity -->
   </PEERNAME>
   <DATA xmlns:dt="urn:schemas-microsoft-com:datatypes" dt:dt="bin.base64">
      <!-- base64 encoded / PFX encoded and encrypted IDC with the private key -->
   </DATA>
</PEERIDENTITYEXPORT>
```

## See also

[PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data)

[PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata)

[PeerIdentityImport](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentityimport)