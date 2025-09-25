# IMetaDataImport::GetSigFromToken

## Description

Gets the binary metadata signature associated with the specified token.

## Parameters

### `tkSignature` [in]

The token to return the binary metadata signature for.

### `ppvSig` [out]

A pointer to the returned metadata signature.

### `pcbSig` [out]

The size in bytes of the binary metadata signature.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)