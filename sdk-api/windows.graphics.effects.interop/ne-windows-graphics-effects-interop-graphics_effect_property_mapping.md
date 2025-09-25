# GRAPHICS_EFFECT_PROPERTY_MAPPING enumeration

## Description

Indicates how a strongly-typed effect property maps to an underlying Direct2D effect property. This enumeration supports the Windows.UI.Composition API and is not meant to be used directly in your code.

## Constants

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_UNKNOWN`

Specifies that the value cannot be mapped to a Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_DIRECT`

Specifies that the value can be set as-is on the Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORX`

Specifies that the value maps to the X component of a vector-typed Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORY`

Specifies that the value maps to the Y component of a vector-typed Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORZ`

Specifies that the value maps to the Z component of a vector-typed Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORW`

Specifies that the value maps to the W component of a vector-typed Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_RECT_TO_VECTOR4`

Specifies that a rect value maps to a Vector4 Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_RADIANS_TO_DEGREES`

Specifies that the value needs to be converted from radians to degrees before being set on the Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_COLORMATRIX_ALPHA_MODE`

Specifies a color matrix alpha mode enum value needs to be converted to the equivalent Direct2D enum value before being set on the effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_COLOR_TO_VECTOR3`

Specifies that a Windows.UI.Color value needs to be converted to an RGB Vector3 before being set on the Direct2D effect property.

### `GRAPHICS_EFFECT_PROPERTY_MAPPING_COLOR_TO_VECTOR4`

Specifies that a Windows.UI.Color value needs to be converted to an RGBA Vector4 before being set on the Direct2D effect property.