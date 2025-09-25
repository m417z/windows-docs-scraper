# IMetaDataImport::IsGlobal

## Description

Gets a value indicating whether the field, method, or type represented by the specified metadata token has global scope.

## Parameters

### `tk` [in]

A metadata token that represents a type, field, or method.

### `pbIsGlobal` [out]

1 if the object has global scope; otherwise, 0 (zero).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)