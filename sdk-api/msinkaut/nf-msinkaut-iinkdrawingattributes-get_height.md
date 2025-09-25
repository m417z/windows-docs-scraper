# IInkDrawingAttributes::get_Height

## Description

Gets or sets the height of the pen when drawing ink with the [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) object.

This property is read/write.

## Parameters

## Remarks

This property applies only to the [Rectangle](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpentip) pen tip. The value represents the height of the side of the rectangle. If using the **Ball** pen tip then the height of the pen tip is equal to the [Width](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_width) property, and the **Height** property is ignored.

Precision is limited to 1/1000 (three digits to the right of the decimal point). For example, if you specify a value of 2.0006, the most precise measurement is 2.001.

## See also

[IInkDrawingAttributes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdrawingattributes)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkPenTip Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpentip)

[PenTip Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_pentip)

[Width Property [InkDrawingAttributes Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_width)