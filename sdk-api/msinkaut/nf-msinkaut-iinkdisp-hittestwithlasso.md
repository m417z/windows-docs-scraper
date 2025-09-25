# IInkDisp::HitTestWithLasso

## Description

Retrieves the strokes within a polyline selection area.

## Parameters

### `Points` [in]

The points that are used in the selection tool to select the strokes. The selection area is the area inside the selection boundary in which the boundary first intersects itself. If the boundary does not intersect itself, the method adds a point to the end of the array to create a straight line from the first point to the last point. If the boundary is a straight line (no area within the selection boundary), no strokes are selected.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `IntersectPercent` [in]

The percentage of stroke points that must be contained within the selection tool to include the stroke in the resulting collection of strokes. If zero (`0`), all strokes that are contained within or intersected by the selection tool are included in the resulting collection of strokes. If 100, only strokes fully contained in the selection tool are included in the collection. Strokes that intersect the selection tool are included in the collection if the percentage of points in those strokes contained within the selection tool is greater than or equal to the *percentIntersect* percentage. Fractional percentages are rounded up.

### `LassoPoints` [in, out, optional]

Optional. Retrieves the specific portion of the selection tool that is used for the selection. Because a user can draw many different types of selection tools, some of which overlap multiple times, this can be useful for illustrating which portion of the selection tool was used for selection. The default value is a **NULL** pointer, which means no information is returned.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

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
| **E_OUTOFMEMORY** | Cannot allocate memory operation. |

## See also

[HitTest(Point, Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestcircle)

[HitTest(Rectangle, Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestwithrectangle)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))