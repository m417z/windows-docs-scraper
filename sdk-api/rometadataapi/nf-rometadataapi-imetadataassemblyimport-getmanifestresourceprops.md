# IMetaDataAssemblyImport::GetManifestResourceProps

## Description

Gets the set of properties of the manifest resource with the specified metadata signature.

## Parameters

### `mdmr` [in]

An **mdManifestResource** token that represents the resource for which to get the properties.

### `szName` [out]

The name of the resource.

### `cchName` [in]

The size, in wide chars, of *szName*.

### `pchName` [out]

A pointer to the number of wide chars actually returned in *szName*.

### `ptkImplementation` [out]

A pointer to an **mdFile** token or an **mdAssemblyRef** token that represents the file or assembly, respectively, that contains the resource.

### `pdwOffset` [out]

A pointer to a value that specifies the offset to the beginning of the resource within the file.

### `pdwResourceFlags` [out]

A pointer to flags that describe the metadata applied to a resource. The flags value is a combination of one or more [CorManifestResourceFlags](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/cormanifestresourceflags-enumeration) values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)