# IMetaDataImport::EnumEvents

## Description

Enumerates event definition tokens for the specified TypeDef token.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `tkTypDef` [in]

The TypeDef token whose event definitions are to be enumerated.

### `rgEvents` [out]

The array of returned events.

### `cMax` [in]

The maximum size of the *rgEvents* array.

### `pcEvents` [out]

The actual number of events returned in *rgEvents*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumEvents** returned successfully. |
| **S_FALSE** | There are no events to enumerate. In this case, *pcEvents* is zero. |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)