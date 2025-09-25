# IMetaDataImport2::EnumGenericParamConstraints

## Description

Gets an enumerator for an array of generic parameter constraints associated with the generic parameter represented by the specified token.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `tk` [in]

A token that represents the generic parameter whose constraints are to be enumerated.

### `rGenericParamConstraints` [out]

The array of generic parameter constraints to enumerate.

### `cMax` [in]

The requested maximum number of tokens to place in *rGenericParamConstraints*.

### `pcGenericParamConstraints` [out]

A pointer to the number of tokens placed in *rGenericParamConstraints*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumGenericParamConstraints** returned successfully. |
| **S_FALSE** | *phEnum* has no member elements. In this case, *pcGenericParameterConstraints* is set to 0 (zero). |

## See also

[IMetaDataImport2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport2)