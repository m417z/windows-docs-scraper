# IMetaDataImport::FindTypeDefByName

## Description

Gets a pointer to the TypeDef metadata token for the Type with the specified name.

## Parameters

### `szTypeDef` [in]

The name of the type for which to get the TypeDef token.

### `tkEnclosingClass` [in]

A TypeDef or TypeRef token representing the enclosing class. If the type to find is not a nested class, set this value to NULL.

### `ptkTypeDef` [out, retval]

A pointer to the matching TypeDef token.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)