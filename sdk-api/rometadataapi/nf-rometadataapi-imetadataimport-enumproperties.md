# IMetaDataImport::EnumProperties

## Description

Enumerates PropertyDef tokens representing the properties of the type referenced by the specified TypeDef token.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `tkTypDef` [in]

A TypeDef token representing the type with properties to enumerate.

### `rgProperties` [out]

The array used to store the PropertyDef tokens.

### `cMax` [in]

The maximum size of the *rgProperties* array.

### `pcProperties` [out]

The number of PropertyDef tokens returned in *rgProperties*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumProperties** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcProperties* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)