# IMetaDataImport::EnumFields

## Description

Enumerates FieldDef tokens for the type referenced by the specified TypeDef token.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `tkTypeDef` [in]

The TypeDef token of the class whose fields are to be enumerated.

### `rgFields` [out]

The list of FieldDef tokens.

### `cMax` [in]

The maximum size of the *rgFields* array.

### `pcTokens` [out]

The actual number of FieldDef tokens returned in *rgFields*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumFields** returned successfully. |
| **S_FALSE** | There are no fields to enumerate. In this case, *pcTokens* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)