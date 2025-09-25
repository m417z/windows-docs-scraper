# IASCOMPONENTPROPERTIES enumeration

## Description

The values of the
**IASCOMPONENTPROPERTIES** enumeration type enumerate identifiers for an SDO object.

## Constants

### `PROPERTY_COMPONENT_ID`

The component ID for the SDO object.

### `PROPERTY_COMPONENT_PROG_ID`

The program ID for the SDO object.

### `PROPERTY_COMPONENT_START`

The start value for RADIUS Protocol properties, defined for convenience.

## Remarks

The following code snippet demonstrates obtaining the component ID of an SDO object. The variable pSdo points to an
[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo) interface.

```cpp
HRESULT    hr;
_variant_t    vtProperty;
hr = pSdo->GetProperty(PROPERTY_COMPONENT_ID, &vtProperty);

```

## See also

[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo)

[ISdo::GetProperty](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-getproperty)