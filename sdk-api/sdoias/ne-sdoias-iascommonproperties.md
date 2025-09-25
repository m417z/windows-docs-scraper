# IASCOMMONPROPERTIES enumeration

## Description

The values of the
**IASCOMMONPROPERTIES** enumeration type enumerate properties that are present in all SDO objects.

## Constants

### `PROPERTY_SDO_RESERVED:0`

This property is reserved.

### `PROPERTY_SDO_CLASS`

The program ID for the SDO object.

### `PROPERTY_SDO_NAME`

The name of the SDO object.

### `PROPERTY_SDO_DESCRIPTION`

Reserved for future use.

### `PROPERTY_SDO_ID`

Reserved for future use.

### `PROPERTY_SDO_DATASTORE_NAME`

The name of the datastore for the object.

### `PROPERTY_SDO_TEMPLATE_GUID`

### `PROPERTY_SDO_OPAQUE`

### `PROPERTY_SDO_START:0x400`

Indicates the start of [USERPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-userproperties).

## Remarks

The following code snippet retrieves the name of the SDO object, if it exists. The variable pSdo is a pointer to an
[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo) interface.

```cpp
HRESULT hr;
_variant_t vtItemName;
hr = pSdo->GetProperty(PROPERTY_SDO_NAME, &vtItemName);

```

## See also

[ISdo::GetProperty](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-getproperty)