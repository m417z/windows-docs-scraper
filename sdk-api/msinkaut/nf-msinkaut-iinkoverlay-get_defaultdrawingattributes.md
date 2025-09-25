# IInkOverlay::get_DefaultDrawingAttributes

## Description

Gets or sets the default drawing attributes to use when drawing and displaying ink.

This property is read/write.

## Parameters

## Remarks

The drawing attributes specified with this property are the attributes that are assigned to a new cursor.

The default drawing attributes are as follows:

[AntiAliased](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_antialiased) = **TRUE**

[Color](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_color) = **BLACK** (RGB(0,0,0)) if not in High Contrast mode; otherwise, Color=COLOR_WINDOWTEXT.

[FitToCurve](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_fittocurve) = **FALSE**

[Height](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_height) = 1 (in ink space units)

[IgnorePressure](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_ignorepressure) = **FALSE**

[PenTip](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_pentip) = **Ball**

[RasterOperation](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_rasteroperation) = **CopyPen**

[Transparency](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_transparency) = 0 (totally opaque)

[Width](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_width) = 53 (in ink space units)

To set different attributes on a new cursor, use the [DrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursor-get_drawingattributes) property of the [IInkCursor](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor) object.

To change the drawing attributes of a single stroke, use the [DrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursor-get_drawingattributes) property of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object. To change the drawing attributes of a collection of strokes, call the [ModifyDrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-modifydrawingattributes) method of the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

**Note** The [DefaultDrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_defaultdrawingattributes) property contains the drawing attributes that all cursors use unless they set their own [DrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursor-get_drawingattributes) property. For example, a new [IInkCursor](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor) object uses **DefaultDrawingAttributes**, and an old **IInkCursor** object on which the **DrawingAttributes** is set to **NULL** also uses **DefaultDrawingAttributes**.

## See also

[DrawingAttributes Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursor-get_drawingattributes)

[IInkCursor Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))

[ModifyDrawingAttributes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-modifydrawingattributes)