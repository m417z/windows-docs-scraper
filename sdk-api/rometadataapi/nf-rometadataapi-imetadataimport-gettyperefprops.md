# IMetaDataImport::GetTypeRefProps

## Description

Gets the metadata associated with the Type referenced by the specified TypeRef token.

## Parameters

### `tkTypeRef` [in]

The TypeRef token that represents the type to return metadata for.

### `ptkResolutionScope` [out]

A pointer to the scope in which the reference is made. This value is an AssemblyRef or ModuleRef token.

### `szName` [out]

A buffer containing the type name.

### `cchName` [in]

The requested size in wide characters of *szName*.

### `pchName` [out]

The returned size in wide characters of *szName*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)