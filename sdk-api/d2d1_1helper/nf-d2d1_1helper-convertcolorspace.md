# ConvertColorSpace function

## Description

Convert a [D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f) from one color space to another.

## Parameters

### `sourceColorSpace`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

The color space of the input.

### `destinationColorSpace`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

The desired color space of the output.

### `color` [ref]

Type: **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The input color.

## Return value

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The converted color in the new color space.