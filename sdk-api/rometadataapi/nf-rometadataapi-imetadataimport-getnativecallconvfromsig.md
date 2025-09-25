# IMetaDataImport::GetNativeCallConvFromSig

## Description

Gets the native calling convention for the method that is represented by the specified signature pointer.

## Parameters

### `pvSig` [in]

A pointer to the metadata signature of the method to return the calling convention for.

### `cbSig` [in]

The size in bytes of *const*.

### `pCallConv` [out]

A pointer to the native calling convention.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)