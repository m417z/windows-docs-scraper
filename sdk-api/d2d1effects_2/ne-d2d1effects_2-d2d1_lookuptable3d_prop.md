# D2D1_LOOKUPTABLE3D_PROP enumeration

## Description

Identifiers for the properties of the 3D Lookup Table effect.

## Constants

### `D2D1_LOOKUPTABLE3D_PROP_LUT:0`

The D2D1_LOOKUPTABLE3D_PROP_LUT property is a pointer to an [ID2D1LookupTable3D](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1lookuptable3d) object. The default value is null.

### `D2D1_LOOKUPTABLE3D_PROP_ALPHA_MODE:1`

The D2D1_LOOKUPTABLE3D_PROP_ALPHA_MODE property is a [D2D1_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode) value indicating the alpha mode of the input file.
See the About Alpha Modes section of the [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes) topic for additional information.

### `D2D1_LOOKUPTABLE3D_PROP_FORCE_DWORD:0xffffffff`

## See also

[Built-in Effects](https://learn.microsoft.com/windows/desktop/Direct2D/built-in-effects)

[CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)