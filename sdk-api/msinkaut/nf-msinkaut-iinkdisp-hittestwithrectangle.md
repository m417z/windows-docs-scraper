# IInkDisp::HitTestWithRectangle

## Description

Retrieves the strokes that are contained within a specified rectangle.

## Parameters

### `SelectionRectangle` [in]

The selection rectangle, of type [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class), in ink space coordinates.

### `IntersectPercent` [in]

The float or single percentage value that determines which strokes are included in the collection. Strokes that intersect the rectangle are included in the collection if the percentage of points in those strokes contained within the rectangle is greater than or equal to the *IntersectPercent* percentage.

### `Strokes` [out, retval]

When this method returns, contains a pointer to the collection of strokes that makes up the ink.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INVALIDARG** | Invalid display handle. |

## Remarks

To determine which points of a known stroke intersect the test area, call the [GetRectangleIntersections](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getrectangleintersections) method of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object, which retrieves the points where a stroke intersects a known rectangle.

## See also

[HitTest(Point, Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestcircle)

[HitTest(Point[], Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestwithlasso)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))