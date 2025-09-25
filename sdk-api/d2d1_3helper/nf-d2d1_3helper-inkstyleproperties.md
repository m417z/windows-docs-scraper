# InkStyleProperties function

## Description

Creates a [D2D1_INK_STYLE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_style_properties) structure.

## Parameters

### `nibShape`

Type: **[D2D1_INK_NIB_SHAPE](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_ink_nib_shape)**

The pre-transform shape of the nib (pen tip) used to draw a given ink object.

### `nibTransform` [ref]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)**

The transform applied to the nib. Note that the translation components of the transform matrix are ignored for the purposes of rendering.

## Return value

Type: **[D2D1_INK_STYLE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_style_properties)**

Returns the created [D2D1_INK_STYLE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_style_properties) structure.

## See also

[D2D1_INK_STYLE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_style_properties)