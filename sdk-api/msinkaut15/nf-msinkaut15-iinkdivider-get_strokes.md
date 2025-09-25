# IInkDivider::get_Strokes

## Description

Gets or sets the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection on which the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object performs layout analysis.

This property is read/write.

## Parameters

## Remarks

This property maintains the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection which the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object analyzes and from which the **InkDivider** object creates the [IInkDivisionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult) object. This property must be assigned a InkStrokes collection in order for the **InkDivider** object to perform layout analysis.

You should only assign this property once to a given [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object. Assigning a subsequent [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) object once one has been assigned will cause inaccurate results to be returned. Also, you may not change the [LineHeight](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivider-get_lineheight) or [RecognizerContext](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivider-get_recognizercontext) property after a InkStrokes collection is assigned to the **Strokes** property.

To keep the **Strokes** property of the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object synchronized with an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object, use the [InkAdded](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkadded) and [InkDeleted](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkdeleted) events of the **InkDisp** object to listen for strokes that should be added or removed from the **InkDivider** object. This covers cases where strokes are added to, deleted from, clipped, or split within the **InkDisp** object.

**Note** Moving, scaling, or other transformations on strokes in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object do not generate [InkAdded](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkadded) or [InkDeleted](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkdeleted) events. Perform the same transformations on the strokes in the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object to keep the **Strokes** property of the **InkDivider** object synchronized.

## See also

[IInkDivider](https://learn.microsoft.com/windows/win32/api/msinkaut15/nn-msinkaut15-iinkdivider)

[InkDivider Class](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))