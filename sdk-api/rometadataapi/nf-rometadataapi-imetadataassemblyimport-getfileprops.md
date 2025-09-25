# IMetaDataAssemblyImport::GetFileProps

## Description

Gets the properties of the file with the specified metadata signature.

## Parameters

### `mdf` [in]

The **mdFile** metadata token that represents the file for which to get the properties.

### `szName` [out]

The simple name of the file.

### `cchName` [in]

The size, in wide chars, of *szName*.

### `pchName` [out]

The number of wide chars actually returned in *szName*.

### `ppbHashValue` [out]

A pointer to the hash value. This is the hash, using the SHA-1 algorithm, of the file.

### `pcbHashValue` [out]

The number of wide chars in the returned hash value.

### `pdwFileFlags` [out]

A pointer to the flags that describe the metadata applied to a file. The flags value is a combination of one or more [CorFileFlags](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corfileflags-enumeration) values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)