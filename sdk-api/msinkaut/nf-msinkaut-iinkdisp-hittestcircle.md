# IInkDisp::HitTestCircle

## Description

Retrieves the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection that are either completely inside or intersected by a known circle.

## Parameters

### `X` [in]

The x-position of the center of the hit test circle in ink space units.

### `Y` [in]

The y-position of the center of the hit test circle in ink space units.

### `radius` [in]

The radius of the circle to use in the hit test, in ink space units.

### `Strokes` [out, retval]

When this method returns, contains the collection of strokes that are either completely inside or intersected by the specified circle.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

If a stroke intersects the circle, the complete stroke is returned.

The method computes the intersection, considering the full set of drawing attributes that apply to the stroke, including the full pen width, Bezier smoothing (if present), and shape of the pen tip.

After a rotation or shear transform has been performed on a stroke or a collection of strokes, the transformed `x-` and `y-` coordinates are no longer concentric with the original coordinates. Because of this, the `radius` argument should not be calculated from the `x-` or `y-` coordinates.

To determine which points of a known stroke intersect the test area, call the [HitTest](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-hittestcircle) method of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object.

The application must always pass in a destination pointer for the resulting collection of strokes. If there are no intersections, the collection has a count of zero.

## See also

[HitTest(Point[], Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestwithlasso)

[HitTest(Rectangle, Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestwithrectangle)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))