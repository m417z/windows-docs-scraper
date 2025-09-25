# IInkDrawingAttributes::put_FitToCurve

## Description

Gets or sets the value that specifies whether Bezier smoothing is used to render ink.

This property is read/write.

## Parameters

## Remarks

Bezier smoothing renders ink as a series of curves instead of as lines between pen sample points. Rendering ink as a series of curves is useful for smoothing the ink, especially when the person writing the ink has unsteady writing.

If you set this property while collecting a stroke or strokes, the ink does not render as a series of curves until it is redrawn or refreshed.

## See also

[GetFlattenedBezierPoints Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getflattenedbezierpoints)

[IInkDrawingAttributes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdrawingattributes)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)