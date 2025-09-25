# ArcSegment function

## Description

Creates a [D2D1_ARC_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_arc_segment) structure.

## Parameters

### `point` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The end point of the arc.

### `size` [in, ref]

Type: **const [D2D1_SIZE_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-f)**

The x-radius and y-radius of the arc.

### `rotationAngle` [in]

Type: **FLOAT**

The number of degrees that the ellipse is rotated relative to the current coordinate system. A positive number specifies a clockwise rotation and a negative number specifies a counterclockwise rotation.

### `sweepDirection` [in]

Type: **[D2D1_SWEEP_DIRECTION](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_sweep_direction)**

A value that specifies whether the arc sweep is clockwise or counterclockwise.

### `arcSize` [in]

Type: **[D2D1_ARC_SIZE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_arc_size)**

A value that specifies whether the arc is larger than 180 degrees.

## Return value

Type: **[D2D1_ARC_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_arc_segment)**

The new arc segment.

## See also

[ID2D1GeometrySink](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1geometrysink)