# D2D1_ARC_SEGMENT structure

## Description

Describes an elliptical arc between two points.

## Members

### `point`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The end point of the arc.

### `size`

Type: **[D2D1_SIZE_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-size-f)**

The x-radius and y-radius of the arc.

### `rotationAngle`

Type: **FLOAT**

A value that specifies how many degrees in the clockwise direction the ellipse is rotated relative to the current coordinate system.

### `sweepDirection`

Type: **[D2D1_SWEEP_DIRECTION](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_sweep_direction)**

A value that specifies whether the arc sweep is clockwise or counterclockwise.

### `arcSize`

Type: **[D2D1_ARC_SIZE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_arc_size)**

A value that specifies whether the given arc is larger than 180 degrees.