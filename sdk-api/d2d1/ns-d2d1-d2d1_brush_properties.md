# D2D1_BRUSH_PROPERTIES structure

## Description

Describes the opacity and transformation of a brush.

## Members

### `opacity`

Type: **FLOAT**

A value between 0.0f and 1.0f, inclusive, that specifies the degree of opacity of the brush.

### `transform`

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)**

The transformation that is applied to the brush.

## Remarks

This structure is used when creating a brush. For convenience, Direct2D provides the [D2D1::BrushProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-brushproperties) function for creating **D2D1_BRUSH_PROPERTIES** structures.

After creating a brush, you can change its opacity or transform by calling the [SetOpacity](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1brush-setopacity) or [SetTransform](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1brush-settransform(constd2d1_matrix_3x2_f_)) methods.

## See also

[D2D1::BrushProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-brushproperties)

[SetOpacity](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1brush-setopacity)

[SetTransform](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1brush-settransform(constd2d1_matrix_3x2_f_))