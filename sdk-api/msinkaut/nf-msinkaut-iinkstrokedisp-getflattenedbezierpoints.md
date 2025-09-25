# IInkStrokeDisp::GetFlattenedBezierPoints

## Description

Retrieves the bounding box in **ink space** coordinates for either all of the strokes in an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object, an individual stroke, or a [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Parameters

### `FittingError` [in, optional]

Optional. The maximum distance (accuracy), using ink space units, between the Bezier control points and the points of the stroke. This is also known as the curve fitting error level. The default value is 0.

### `FlattenedBezierPoints` [out, retval]

When this method returns, contains a point array that indicates the points that were used to draw the Bezier curve representation of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object. The Variant result contains an array in the form x1, y1, x2, y2, and so on, of the Bezier points.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TPC_E_INVALID_STROKE** | The stroke is invalid. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | Cannot allocate Stroke handler helper object. |
| **E_INVALIDARG** | The fitting error was out of range. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

You should ideally set the *fittingError* parameter between 0 and 500. If the value is greater than 500, a stroke may appear distorted or coarse when drawn. Strokes appear smoothest when the fitting error level is set to 0, but the drawing performance is slowest at this level.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[IInkStrokeDisp::BezierPoints Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_bezierpoints)