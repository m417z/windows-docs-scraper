# IMetaDataImport::EnumTypeRefs

## Description

Enumerates TypeRef tokens defined in the current metadata scope.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `rgTypeRefs` [out]

The array used to store the TypeRef tokens.

### `cMax` [in]

The maximum size of the *rgTypeRefs* array.

### `pcTypeRefs` [out, retval]

A pointer to the number of TypeRef tokens returned in *rgTypeRefs*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumTypeRefs**  returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTypeRefs* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)