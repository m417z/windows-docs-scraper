# IInkEdit::putref_DrawingAttributes

## Description

Gets or sets the drawing attributes for ink that is yet to be drawn on the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control.

This property is read/write.

## Parameters

## Remarks

The **DrawingAttributes** property specifies the appearance of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object. For example, you can specify the width and color of ink drawn on the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control.

Successive calls to the **DrawingAttributes** property change only the **DrawingAttributes** properties of new [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) objects. The calls do not apply to **IInkStrokeDisp** objects that the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control already collected or is in the process of collecting.

This property is different from the [DrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursor-get_drawingattributes) property of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object, which specifies the attributes of already collected ink. The [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control's **DrawingAttributes** property is more analogous to the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) object's [DefaultDrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_defaultdrawingattributes) property, except that for the **DefaultDrawingAttributes** property the [FitToCurve](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_fittocurve) property is set to **TRUE** by default.

## See also

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)