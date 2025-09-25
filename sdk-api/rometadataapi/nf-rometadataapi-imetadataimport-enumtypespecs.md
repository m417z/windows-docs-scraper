# IMetaDataImport::EnumTypeSpecs

## Description

Enumerates TypeSpec tokens defined in the current metadata scope.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This value must be NULL for the first call of this method.

### `rgTypeSpecs` [out]

The array used to store the TypeSpec tokens.

### `cMax` [in]

The maximum size of the *rgTypeSpecs* array.

### `pcTypeSpecs` [out]

The number of TypeSpec tokens returned in *rgTypeSpecs*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumTypeSpecs** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTypeSpecs* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)