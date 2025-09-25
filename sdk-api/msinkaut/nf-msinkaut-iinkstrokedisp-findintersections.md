# IInkStrokeDisp::FindIntersections

## Description

Retrieves the points where this [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object intersects other **IInkStrokeDisp** objects within a known [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Parameters

### `Strokes` [in]

 The known collection of strokes that are used to calculate the points where this stroke intersects strokes in the collection. If **NULL**, use all strokes in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

**Note** The known collection of strokes must come from the same [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object as the stroke being tested for intersection. If it is not from the same **InkDisp** object, **E_INK_MISMATCHED_INK_OBJECT** is returned (see "HRESULT value" below). The **FindIntersections** method is the only Tablet PC application programming interface (API) that requires that the known collection of strokes come from the same **InkDisp** object.

### `Intersections` [out, retval]

When this method returns, contains an array of floating point index values that indicate the locations where this stroke intersects strokes within a known collection of strokes.

A floating point index is a float value that represents a location somewhere between two points in the stroke. As examples, if 0.0 is the first point in the stroke and 1.0 is the second point in the stroke, 0.5 is halfway between the first and second points. Similarly, a floating point index value of 37.25 represents a location that is 25 percent along the line between points 37 and 38 of the stroke.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) handle helper object. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_INCOMPATIBLE_OBJECT** | The *strokes* parameter does not point to a compatible [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. |
| **E_INK_MISMATCHED_INK_OBJECT** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection and this [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object don't match. |

## Remarks

This method can determine only the points of intersection.

## See also

[GetRectangleIntersections Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getrectangleintersections)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))