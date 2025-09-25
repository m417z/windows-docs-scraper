# IMetaDataImport::EnumMethodsWithName

## Description

Enumerates methods that have the specified name and that are defined by the type referenced by the specified TypeDef token.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `tkTypeDef` [in]

A TypeDef token representing the type whose methods to enumerate.

### `szName` [in]

The name that limits the scope of the enumeration.

### `rgMethods` [out]

The array used to store the MethodDef tokens.

### `cMax` [in]

The maximum size of the *rgMethods* array.

### `pcTokens` [out]

The number of MethodDef tokens returned in *rgMethods*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumMethodsWithName** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## Remarks

This method enumerates fields and methods, but not properties or events. Unlike [EnumMethods](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadataimport-enummethods), **EnumMethodsWithName** discards all method tokens that do not have the specified name.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)