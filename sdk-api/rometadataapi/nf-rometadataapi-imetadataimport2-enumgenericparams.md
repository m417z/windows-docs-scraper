# IMetaDataImport2::EnumGenericParams

## Description

Gets an enumerator for an array of generic parameter tokens associated with the specified TypeDef or MethodDef token.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `tk` [in]

The **TypeDef** or **MethodDef** token whose generic parameters are to be enumerated.

### `rGenericParams` [out]

The array of generic parameters to enumerate.

### `cMax` [in]

The requested maximum number of tokens to place in *rGenericParams*.

### `pcGenericParams` [out]

The returned number of tokens placed in *rGenericParams*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumGenericParams** returned successfully. |
| **S_FALSE** | *phEnum* has no member elements. In this case, *pcGenericParams* is set to 0 (zero). |

## See also

[IMetaDataImport2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport2)