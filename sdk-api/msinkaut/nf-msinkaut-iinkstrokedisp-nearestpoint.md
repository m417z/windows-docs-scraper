# IInkStrokeDisp::NearestPoint

## Description

Finds the location on the stroke nearest to a known point and returns the distance that point is from the stroke. Everything is in ink space coordinates.

## Parameters

### `X` [in]

The x-position in ink space of the point to test.

### `Y` [in]

The y-position in ink space of the point to test.

### `Distance` [in, out, optional]

Optional. The distance from the point to the stroke. This parameter can be **NULL**. The default value is 0.

### `Point` [out, retval]

When this method returns, contains the floating point index value that represents the closest location on the stroke.

A floating point index is a float value that represents a location somewhere between two points in the stroke. As examples, if 0.0 is the first point in the stroke and 1.0 is the second point in the stroke, 0.5 is halfway between the first and second points. Similarly, a floating point index value of 37.25 represents a location that is 25 percent along the line between points 37 and 38 of the stroke.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

The *distance* parameter describes the distance from the point to the envelope of the stroke. This is the distance between the two points minus half the width of the stroke.

## See also

[GetRectangleIntersections Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getrectangleintersections)

[HitTest(Point, Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestcircle)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[NearestPoint Method [InkDisp Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-nearestpoint)