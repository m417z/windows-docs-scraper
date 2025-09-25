# D2D1_DPICOMPENSATION_PROP enumeration

## Description

Identifiers for properties of the [DPI compensation effect](https://learn.microsoft.com/windows/desktop/Direct2D/dpi-compensation).

## Constants

### `D2D1_DPICOMPENSATION_PROP_INTERPOLATION_MODE:0`

The interpolation mode the effect uses to scale the image.

The type is [D2D1_DPICOMPENSATION_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_dpicompensation_interpolation_mode).

The default value is D2D1_DPICOMPENSATION_INTERPOLATION_MODE_LINEAR.

### `D2D1_DPICOMPENSATION_PROP_BORDER_MODE:1`

The mode used to calculate the border of the image, soft or hard. See Border modes for more info.

The type is [D2D1_BORDER_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_border_mode).

The default value is D2D1_BORDER_MODE_SOFT.

### `D2D1_DPICOMPENSATION_PROP_INPUT_DPI:2`

The DPI of the input image.

The type is FLOAT.

The default value is 96.0f.

### `D2D1_DPICOMPENSATION_PROP_FORCE_DWORD:0xffffffff`