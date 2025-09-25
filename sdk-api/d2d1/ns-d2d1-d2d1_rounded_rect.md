## Description

Contains the dimensions and corner radii of a rounded rectangle.

## Members

### `rect`

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)**

The coordinates of the rectangle.

### `radiusX`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The x-radius for the quarter ellipse that is drawn to replace every corner of the rectangle.

### `radiusY`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The y-radius for the quarter ellipse that is drawn to replace every corner of the rectangle.

## Remarks

Each corner of the rectangle specified by *rect* is replaced with a quarter ellipse, with a radius in each direction specified by *radiusX* and *radiusY*.

If *radiusX* is greater than or equal to half the width of the rectangle, and *radiusY* is greater than or equal to one-half the height, then the rounded rectangle is an ellipse with the same width and height of *rect*.

Even when both *radiusX* and *radiusY* are zero, the rounded rectangle is different from a rectangle. When stroked, the corners of the rounded rectangle are roundly joined, not mitered (square).