# IInkDivisionUnit::get_Strokes

## Description

Gets the collection of strokes that are contained in an object or used to create an object.

This property is read-only.

## Parameters

## Remarks

The collection of strokes may be the copies of the strokes contained in an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object or the strokes that were used to create the object or collection.

**Note** The [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionresult-get_strokes) property for the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object does not return the actual collection that the **InkDisp** object works with, but instead returns a copy. For example, this means that adding or removing strokes to this collection does not affect the **InkDisp** object's strokes; to add or remove strokes, use **InkDisp** methods such as [AddStrokesAtRectangle](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-addstrokesatrectangle), [DeleteStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestroke), and [DeleteStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-deletestrokes). However, each stroke in the collection is a reference to the original [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object.

## See also

[IInkDivisionUnit Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))