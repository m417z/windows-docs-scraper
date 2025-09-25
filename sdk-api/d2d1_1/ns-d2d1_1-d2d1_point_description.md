# D2D1_POINT_DESCRIPTION structure

## Description

Describes a point on a path geometry.

## Members

### `point`

The end point after walking the path.

### `unitTangentVector`

A unit vector indicating the tangent point.

### `endSegment`

The index of the segment on which point resides. This index is global to the entire path, not just to a particular figure.

### `endFigure`

The index of the figure on which point resides.

### `lengthToEndSegment`

The length of the section of the path stretching from the start of the path to the start of **endSegment**.

## See also

[ID2D1PathGeometry1::ComputePointAndSegmentAtLength](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1pathgeometry1-computepointandsegmentatlength(float_uint32_constd2d1_matrix_3x2_f_d2d1_point_description))