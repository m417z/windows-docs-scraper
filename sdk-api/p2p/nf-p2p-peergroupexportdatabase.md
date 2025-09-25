# PeerGroupExportDatabase function

## Description

The **PeerGroupExportDatabase** function exports a peer group database to a specific file, which can be transported to another computer and imported with the [PeerGroupImportDatabase](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupimportdatabase) function.

## Parameters

### `hGroup` [in]

Handle to the peer group whose database is exported to a local file on the peer. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pwzFilePath` [in]

Pointer to a Unicode string that contains the absolute file system path and file name where the exported database is stored. For example, "C:\backup\p2pdb.db". If this file already exists at the specified location, the older file is overwritten. This parameter is required.

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns one of the following values.

**Note** If an export fails due to a file system error, the appropriate file system error, defined in winerror.h, is returned.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[PeerGroupImportDatabase](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupimportdatabase)