# IMetaDataImport::FindTypeRef

## Description

Gets a pointer to the TypeRef token for the Type reference that is in the specified scope and that has the specified name.

## Parameters

### `tkResolutionScope` [in]

A ModuleRef, AssemblyRef, or TypeRef token that specifies the module, assembly, or type, respectively, in which the type reference is defined.

### `szName` [in]

The name of the type reference to search for.

### `tkTypeRef` [out]

A pointer to the matching TypeRef token.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)