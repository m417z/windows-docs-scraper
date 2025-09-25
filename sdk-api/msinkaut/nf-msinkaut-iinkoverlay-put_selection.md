# IInkOverlay::put_Selection

## Description

Gets or sets the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection that is currently selected inside the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object or the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control.

This property is read/write.

## Parameters

## Remarks

To get the bounding rectangle of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection after it has been moved or resized, call the [GetBoundingBox](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getboundingbox) method of the InkStrokes collection returned by this property.

To get the bounding rectangle of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection before it was moved, handle the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-selectionmoved) or the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-selectionmoved) event.

To get the bounding rectangle of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection before it was resized, handle the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-selectionresized) or the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-selectionresized) event.

## See also

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))

[SelectionMoved Event [InkPicture Control]](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-selectionmoved)

[SelectionResized Event [InkPicture Control]](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-selectionresized)