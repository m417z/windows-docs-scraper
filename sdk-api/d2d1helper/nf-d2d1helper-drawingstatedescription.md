# DrawingStateDescription function

## Description

Creates a [D2D1_DRAWING_STATE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_drawing_state_description) structure.

## Parameters

### `antialiasMode`

Type: **[D2D1_ANTIALIAS_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_antialias_mode)**

The antialiasing mode for subsequent non-text drawing operations. The default value is [D2D1_ANTIALIAS_MODE_PER_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_antialias_mode).

### `textAntialiasMode`

Type: **[D2D1_TEXT_ANTIALIAS_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_text_antialias_mode)**

The antialiasing mode for subsequent text and glyph drawing operations. The default value is [D2D1_TEXT_ANTIALIAS_MODE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_text_antialias_mode).

### `tag1`

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-tag)**

A label for subsequent drawing operations. The default value is 0.

### `tag2`

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-tag)**

A label for subsequent drawing operations. The default value is 0.

### `transform` [in, ref]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)**

The transformation to be applied to subsequent drawing operations. The default value is provided by the  [D2D1::IdentityMatrix](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-identitymatrix) function, which returns the identity matrix.

## Return value

Type: **[D2D1_DRAWING_STATE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_drawing_state_description)**

A structure that describes the drawing state of a render target.