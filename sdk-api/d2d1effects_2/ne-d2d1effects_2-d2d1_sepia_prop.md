# D2D1_SEPIA_PROP enumeration

## Description

Identifiers for properties of the [Sepia effect](https://learn.microsoft.com/windows/desktop/Direct2D/sepia-effect).

## Constants

### `D2D1_SEPIA_PROP_INTENSITY:0`

The D2D1_SEPIA_PROP_INTENSITY property is a float value indicating the intensity of the sepia effect. The allowed range is 0.0 to 1.0. The default value is 0.5.

### `D2D1_SEPIA_PROP_ALPHA_MODE:1`

The D2D1_SEPIA_PROP_ALPHA_MODE property is a [D2D1_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode) enumeration value indicating the alpha mode of the input file.
See the About Alpha Modes section of the [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes) topic for additional information..
The default value is D2D1_ALPHA_MODE_PREMULTIPLIED.

### `D2D1_SEPIA_PROP_FORCE_DWORD:0xffffffff`