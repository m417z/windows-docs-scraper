# IInkDrawingAttributes::put_Width

## Description

Gets or sets the y-axis dimension, or width, of the pen tip when drawing ink.

This property is read/write.

## Parameters

## Remarks

If the tablet reports pen pressure (if the [IgnorePressure](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_ignorepressure) property is false), the actual width of the ink varies depending on the amount of pressure applied to the drawing surface. When maximum pressure is applied, the width is 150% of the value of the `Width` property. When minimum pressure is applied, the width is 50% of the value of the `Width` property. By default, this property is set to true, so that pressure from the pen is reported. To specify that pressure should not be reported (that the width of ink does not change), set the **IgnorePressure** property to true.

Precision is limited to one one-thousandth of a HIMETRIC unit (three digits to the right of the decimal point). For example, if you specify a value of 2.0006, the most precise measurement is 2.001.

## See also

[Height Property [InkDrawingAttributes Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_height)

[IInkDrawingAttributes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdrawingattributes)

[IgnorePressure Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_ignorepressure)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[PenTip Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_pentip)