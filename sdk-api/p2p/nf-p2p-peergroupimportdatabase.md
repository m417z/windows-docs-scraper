# PeerGroupImportDatabase function

## Description

The **PeerGroupImportDatabase** function imports a peer group database from a local file.

## Parameters

### `hGroup` [in]

Handle to a peer group whose database is imported from a local file. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pwzFilePath` [in]

Pointer to a Unicode string that contains the absolute file system path and file name where the data is stored, for example, "C:\backup\p2pdb.db". If the file does not exist at this location, an appropriate error from the file system is returned. This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

**Note** If an import fails due to a file system error, the appropriate file system error is returned.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_GROUP_IN_USE** | The operation cannot be completed because the peer group database is currently in use. For example, [PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect) has been called by a peer, but has not yet completed any database transactions. |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

This function must be called before [PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect), and after [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen) or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin).

## See also

[PeerGroupConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupconnect)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PerrGroupExportDatabase](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupexportdatabase)