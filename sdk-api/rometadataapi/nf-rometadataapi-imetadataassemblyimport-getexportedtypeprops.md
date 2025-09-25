# IMetaDataAssemblyImport::GetExportedTypeProps

## Description

Gets the set of properties of the exported type with the specified metadata signature.

## Parameters

### `mdct` [in]

An **mdExportedType** metadata token that represents the exported type.

### `szName` [out]

The name of the exported type.

### `cchName` [in]

The size, in wide characters, of *szName*.

### `pchName` [out]

The number of wide characters actually returned in *szName*.

### `ptkImplementation` [out]

 An **mdFile**, **mdAssemblyRef**, or **mdExportedType** metadata token that contains or allows access to the properties of the exported type.

### `ptkTypeDef` [out]

A pointer to an **mdTypeDef** token that represents a type in the file.

### `pdwExportedTypeFlags` [out]

A pointer to the flags that describe the metadata applied to the exported type. The flags value can be one or more [CorTypeAttr](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/cortypeattr-enumeration) values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)