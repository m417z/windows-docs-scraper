# IMetaDataImport::EnumMethodSemantics

## Description

Enumerates the properties and the property-change events to which the specified method is related.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `tkMethodDef` [in]

 A MethodDef token that limits the scope of the enumeration.

### `rgEventProp` [out]

The array used to store the events or properties.

### `cMax` [in]

The maximum size of the *rgEventProp* array.

### `pcEventProp` [out]

The number of events or properties returned in *rgEventProp*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumMethodSemantics** returned successfully. |
| **S_FALSE** | There are no events or properties to enumerate. In this case, *pcEventProp* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)