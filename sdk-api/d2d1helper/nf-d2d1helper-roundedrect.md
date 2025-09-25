# RoundedRect function

## Description

Creates a [D2D1_ROUNDED_RECT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_rounded_rect) structure.

## Parameters

### `rect` [in, ref]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The size and position of the rectangle.

### `radiusX`

Type: **FLOAT**

The x-radius for the quarter ellipse that is drawn to replace every corner of the rectangle.

### `radiusY`

Type: **FLOAT**

The y-radius for the quarter ellipse that is drawn to replace every corner of the rectangle.

## Return value

Type: **[D2D1_ROUNDED_RECT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_rounded_rect)**

The new rounded rectangle.