# D2D1_DRAWING_STATE_DESCRIPTION1 structure

## Description

Describes the drawing state of a device context.

## Members

### `antialiasMode`

Type: **[D2D1_ANTIALIAS_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_antialias_mode)**

The antialiasing mode for subsequent nontext drawing operations.

### `textAntialiasMode`

Type: **[D2D1_TEXT_ANTIALIAS_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_text_antialias_mode)**

The antialiasing mode for subsequent text and glyph drawing operations.

### `tag1`

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-tag)**

A label for subsequent drawing operations.

### `tag2`

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-tag)**

A label for subsequent drawing operations.

### `transform`

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)**

The transformation to apply to subsequent drawing operations.

### `primitiveBlend`

Type: **[D2D1_PRIMITIVE_BLEND](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_primitive_blend)**

The blend mode for the device context to apply to subsequent drawing operations.

### `unitMode`

Type: **[D2D1_UNIT_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_unit_mode)**

D2D1_UNIT_MODE

## See also

[ID2D1DrawingStateBlock](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1drawingstateblock)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1rendertarget)

[RestoreDrawingState](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-restoredrawingstate)

[SaveDrawingState](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-savedrawingstate)