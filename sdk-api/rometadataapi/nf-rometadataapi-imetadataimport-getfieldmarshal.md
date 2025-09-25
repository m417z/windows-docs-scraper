# IMetaDataImport::GetFieldMarshal

## Description

Gets a pointer to the native, unmanaged type of the field represented by the specified field metadata token.

## Parameters

### `tk` [in]

The metadata token that represents the field to get interop marshaling information for.

### `ppvNativeType` [out]

A pointer to the metadata signature of the field's native type.

### `pcbNativeType` [out]

The size in bytes of *ppvNativeType*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)