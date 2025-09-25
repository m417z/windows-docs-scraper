# IMetaDataImport::EnumMethods

## Description

Enumerates MethodDef tokens representing methods of the specified type.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `tkTypeDef` [in]

A TypeDef token representing the type with the methods to enumerate.

### `rgMethods` [out]

The array to store the MethodDef tokens.

### `cMax` [in]

The maximum size of the MethodDef *rgMethods* array.

### `pcTokens` [out]

The number of MethodDef tokens returned in *rgMethods*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumMethods** returned successfully. |
| **S_FALSE** | There are no MethodDef tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)