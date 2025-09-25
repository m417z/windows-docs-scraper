# ID2D1PathGeometry1::ComputePointAndSegmentAtLength(FLOAT,UINT32,const D2D1_MATRIX_3X2_F,FLOAT,D2D1_POINT_DESCRIPTION)

## Description

Computes the point that exists at a given distance along the path geometry along with the index of the segment
the point is on and the directional vector at that point.

## Parameters

### `length`

Type: **FLOAT**

The distance to walk along the path.

### `startSegment`

Type: **UINT**

The index of the segment at which to begin walking. Note: This index is global to the entire path, not just a particular figure.

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the path prior to walking.

### `flatteningTolerance`

Type: **FLOAT**

The flattening tolerance to use when walking along an arc or Bezier segment. The flattening tolerance is the maximum
error allowed when constructing a polygonal approximation of the geometry. No point in the polygonal representation will diverge
from the original geometry by more than the flattening tolerance. Smaller values produce more accurate results but cause slower execution.

### `pointDescription` [out]

Type: **[D2D1_POINT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description)***

When this method returns, contains a description of the point that can be found at the given location.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | One of the inputs was in an invalid range. |

## Remarks

A *length* that is less than 0 or is not a number is treated as if it were 0.

If *length* is greater than the total length of the path, then the end point of the path is returned.

### Example Illustration

Consider this example that explains the value of different parameters returned for the given path geometry.

![A diagram of a path geometry and its lengths.](https://learn.microsoft.com/windows/win32/api/d2d1_1/images/computepointandsegmentatlength.png)
Here are two different scenarios.

### You want to retrieve the segment at a length L2

You call ComputePointAndSegmentAtLength(Length = L2, startSegment =0). The API returns the following:

* [D2D1_POINT_DESCRIPTION::point](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = p2.
* [D2D1_POINT_DESCRIPTION::endSegment](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = 3 (segment DE). This is the value you want.
* [D2D1_POINT_DESCRIPTION::lengthToEndSegment](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = length (AD).

### You wants to improve the performance of calculating a point at a given length for animating along a path

Normally, the time intervals would be small and regular, resulting in many animation points per segment. For the purposes of demonstration, however, we will assume the you query ComputePointAndSegmentAtLength three times, with irregularly-spaced lengths L1, L2, L3:

You call ComputePointAndSegmentAtLength(Length = L1, startSegment = 0). The API returns the following:

* [D2D1_POINT_DESCRIPTION::point](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = P1.
* [D2D1_POINT_DESCRIPTION::endSegment](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = 1 (segment BC).
* [D2D1_POINT_DESCRIPTION::lengthToEndSegment](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = length (AB).

You call ComputePointAndSegmentAtLength(Length = L2 - Length(AB), startSegment = 1). The API returns the following:

* [D2D1_POINT_DESCRIPTION::point](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = P2.
* [D2D1_POINT_DESCRIPTION::endSegment](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = 3 (segment DE).
* [D2D1_POINT_DESCRIPTION::lengthToEndSegment](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = length (AD).

You call ComputePointAndSegmentAtLength(= L3-length(AB)-length(BD), startSegment = 3). The API returns the following:

* [D2D1_POINT_DESCRIPTION::point](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = P3.
* [D2D1_POINT_DESCRIPTION::endSegment](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) = 3 (segment DE).
* [D2D1_POINT_DESCRIPTION::lengthToEndSegment](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description) =0.

## See also

[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)

[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)

[D2D1_POINT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description)

[ID2D1PathGeometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1pathgeometry)

[ID2D1PathGeometry1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1pathgeometry1)