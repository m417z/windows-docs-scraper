# IMetaDataImport::EnumCustomAttributes

## Description

Enumerates custom attribute-definition tokens associated with the specified type or member.

## Parameters

### `phEnum` [in, out]

A pointer to the returned enumerator.

### `tk` [in]

 A token for the scope of the enumeration, or zero for all custom attributes.

### `tkType` [in]

A token for the type of the attributes to be enumerated, or zero for all types.

### `rgCustomAttributes` [out]

An array of custom attribute tokens.

### `cMax` [in]

The maximum size of the *rgCustomAttributes* array.

### `pcCustomAttributes` [out]

The actual number of token values returned in *rgCustomAttributes*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumCustomAttributes** returned successfully. |
| **S_FALSE** | There are no custom attributes to enumerate. In this case, *pcCustomAttributes* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)