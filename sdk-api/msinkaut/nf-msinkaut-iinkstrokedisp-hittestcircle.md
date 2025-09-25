# IInkStrokeDisp::HitTestCircle

## Description

Determines whether a stroke is either completely inside or intersected by a given circle.

## Parameters

### `X` [in]

The x-position of the center of the hit-test circle in ink space coordinates.

### `Y` [in]

The y-position of the center of the hit-test circle in ink space coordinates.

### `Radius` [in]

The radius of the circle to use in the hit test.

### `Intersects` [out, retval]

**VARIANT_TRUE** if the stroke intersects or is inside the circle; otherwise, **VARIANT_FALSE**

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## See also

[GetRectangleIntersections Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getrectangleintersections)

[HitTest(Point, Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestcircle)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[NearestPoint Method [IInkStrokeDisp Interface]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-nearestpoint)