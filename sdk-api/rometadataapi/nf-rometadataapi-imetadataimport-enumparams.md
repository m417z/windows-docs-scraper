# IMetaDataImport::EnumParams

## Description

Enumerates ParamDef tokens representing the parameters of the method referenced by the specified MethodDef token.

## Parameters

### `phEnum` [in, out]

 A pointer to the enumerator. This must be NULL for the first call of this method.

### `tkMethodDef` [in]

A MethodDef token representing the method with the parameters to enumerate.

### `rParams` [out]

The array used to store the ParamDef tokens.

### `cMax` [in]

The maximum size of the *rParams array*.

### `pcTokens` [out]

The number of ParamDef tokens returned in *rParams*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumParams** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)