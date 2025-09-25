# D2D1_SATURATION_PROP enumeration

## Description

Identifiers for properties of the [Saturation effect](https://learn.microsoft.com/windows/desktop/Direct2D/saturation).

## Constants

### `D2D1_SATURATION_PROP_SATURATION:0`

The saturation of the image. You can set the saturation to a value between 0 and 1. If you set it to 1 the output image is fully saturated.
If you set it to 0 the output image is monochrome. The saturation value is unitless.

The type is FLOAT.

The default is 0.5f.

### `D2D1_SATURATION_PROP_FORCE_DWORD:0xffffffff`