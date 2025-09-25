# IInkStrokeDisp::Split

## Description

Splits the stroke at the specified location on the stroke.

## Parameters

### `SplitAt` [in]

The floating point index value that represents where to split the stroke.

**Note** A floating point index is a float value that represents a location somewhere between two points in the stroke. As examples, if 0.0 is the first point in the stroke and 1.0 is the second point in the stroke, 0.5 is halfway between the first and second points. Similarly, a floating point index value of 37.25 represents a location that is 25 percent along the line between points 37 and 38 of the stroke.

### `NewStroke` [out, retval]

When this method returns, contains a pointer to the new [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object that is created from the split operation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate Stroke handler helper object. |
| **E_INVALIDARG** | The parameter is invalid. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

This method inserts the new stroke immediately after the original stroke in the stroke set and renumbers the remaining stroke indices.

When an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) is split, the beginning portion of the stroke remains the ID of the original **IInkStrokeDisp**. The end portion of the **IInkStrokeDisp** becomes a new **IInkStrokeDisp** with an ID that is one greater than the highest **IInkStrokeDisp** ID. If the original **IInkStrokeDisp** was in an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection (other than the [Ink.Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionresult-get_strokes)), only the beginning portion remains in that collection.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)