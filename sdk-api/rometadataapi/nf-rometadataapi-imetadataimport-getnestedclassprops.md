# IMetaDataImport::GetNestedClassProps

## Description

Gets the TypeDef token for the parent Type of the specified nested type.

## Parameters

### `tdNestedClass` [in]

A TypeDef token representing the Type to return the parent class token for.

### `ptdEnclosingClass` [out]

A pointer to the TypeDef token for the Type that *tdNestedClass* is nested in.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)