# WINTRUST_CATALOG_INFO structure

## Description

The **WINTRUST_CATALOG_INFO** structure is used when calling
[WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) to verify a member of a Microsoft catalog.

## Members

### `cbStruct`

Size, in bytes, of this structure.

### `dwCatalogVersion`

Optional. Catalog version number.

### `pcwszCatalogFilePath`

The full path and file name of the catalog file that contains the member to be verified.

### `pcwszMemberTag`

Tag of a member file to be verified.

### `pcwszMemberFilePath`

The full path and file name of the catalog member file to be verified.

### `hMemberFile`

Optional. Handle of the open catalog member file to be verified. The handle must be to a file with at least read permissions.

### `pbCalculatedFileHash`

Optional. The calculated hash of the file that contains the file to be verified.

### `cbCalculatedFileHash`

The size, in bytes, of the value passed in the **pbCalculatedFileHash** member. **cbCalculatedFileHash** is used only if the calculated hash is being passed.

### `pcCatalogContext`

A pointer to a [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure that represents a catalog context to be used instead of a catalog file.

### `hCatAdmin`

Handle to the catalog administrator context that was used when calculating the hash of the file. This value can be zero only for a SHA1 file hash.**Windows 8 and Windows Server 2012:** Support for this member begins.