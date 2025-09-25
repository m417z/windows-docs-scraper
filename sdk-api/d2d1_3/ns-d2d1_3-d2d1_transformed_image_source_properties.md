# D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES structure

## Description

Properties of a transformed image source.

## Members

### `orientation`

Type: **[D2D1_ORIENTATION](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_orientation)**

The orientation at which the image source is drawn.

### `scaleX`

Type: **FLOAT**

The horizontal scale factor at which the image source is drawn.

### `scaleY`

Type: **FLOAT**

The vertical scale factor at which the image source is drawn.

### `interpolationMode`

Type: **[D2D1_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_interpolation_mode)**

The interpolation mode used when the image source is drawn. This is ignored if the image source is drawn using the DrawImage method, or using an image brush.

### `options`

Type: **[D2D1_TRANSFORMED_IMAGE_SOURCE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_transformed_image_source_options)**

Image source option flags.