# BrushProperties function

## Description

Creates a [D2D1_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_brush_properties) structure.

## Parameters

### `opacity` [in]

Type: **FLOAT**

The base opacity of the brush. The default value is 1.0.

### `transform` [in, ref]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)**

The transformation to apply to the brush. The default value is [D2D1::IdentityMatrix](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-identitymatrix).

## Return value

Type: **[D2D1_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_brush_properties)**

The new brush properties structure.

## See also

[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)