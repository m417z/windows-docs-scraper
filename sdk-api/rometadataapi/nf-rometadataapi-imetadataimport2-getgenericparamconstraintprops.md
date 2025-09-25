# IMetaDataImport2::GetGenericParamConstraintProps

## Description

Gets the metadata associated with the generic parameter constraint represented by the specified constraint token.

## Parameters

### `gpc` [in]

The token to the generic parameter constraint for which to return the metadata.

### `ptGenericParam` [out]

A pointer to the token that represents the generic parameter that is constrained.

### `ptkConstraintType` [out]

A pointer to a **TypeDef**, **TypeRef**, or **TypeSpec** token that represents a constraint on ptGenericParam.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport2)