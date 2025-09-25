# IMetaDataImport::EnumFieldsWithName

## Description

Enumerates FieldDef tokens of the specified type with the specified name.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `tkTypeDef` [in]

The token of the type whose fields are to be enumerated.

### `szName` [in]

The field name that limits the scope of the enumeration.

### `rFields` [out]

Array used to store the FieldDef tokens.

### `cMax` [in]

The maximum size of the *rFields* array.

### `pcTokens` [out]

The actual number of FieldDef tokens returned in *rFields*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumFieldsWithName** returned successfully. |
| **S_FALSE** | There are no fields to enumerate. In this case, *pcTokens* is 0 (zero). |

## Remarks

Unlike [EnumFields](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadataimport-enumfields), **EnumFieldsWithName** discards all field tokens that do not have the specified name.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)