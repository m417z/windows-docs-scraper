# D2D1_STROKE_STYLE_PROPERTIES1 structure

## Description

Describes the stroke that outlines a shape.

## Members

### `startCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style)**

The cap to use at the start of each open figure.

### `endCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style)**

The cap to use at the end of each open figure.

### `dashCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style)**

The cap to use at the start and end of each dash.

### `lineJoin`

Type: **[D2D1_LINE_JOIN](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_line_join)**

The line join to use.

### `miterLimit`

Type: **FLOAT**

The limit beyond which miters are either clamped or converted to bevels.

### `dashStyle`

Type: **[D2D1_DASH_STYLE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_dash_style)**

The type of dash to use.

### `dashOffset`

Type: **FLOAT**

The location of the first dash, relative to the start of the figure.

### `transformType`

Type: **[D2D1_STROKE_TRANSFORM_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_stroke_transform_type)**

The rule that determines what render target properties affect the nib of the stroke.

## See also

[ID2D1Factory1::CreateStrokeStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-createstrokestyle(constd2d1_stroke_style_properties1_constfloat_uint32_id2d1strokestyle1))

[ID2D1StrokeStyle1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1strokestyle1)