# IMetaDataImport::GetTypeSpecFromToken

## Description

Gets the binary metadata signature of the type specification represented by the specified token.

## Parameters

### `tkTypeSpec` [in]

The TypeSpec token associated with the requested metadata signature.

### `ppvSig` [out]

 A pointer to the binary metadata signature.

### `pcbSig` [out]

The size, in bytes, of the metadata signature.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)