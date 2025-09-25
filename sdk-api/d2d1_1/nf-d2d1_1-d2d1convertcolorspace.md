# D2D1ConvertColorSpace function

## Description

Converts the given color from one colorspace to another.

## Parameters

### `sourceColorSpace`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

The source color space.

### `destinationColorSpace`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

The destination color space.

### `color` [in]

Type: **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)***

The source color.

## Return value

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The converted color.