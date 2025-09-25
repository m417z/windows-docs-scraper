# IInkDrawingAttributes::get_PenTip

## Description

Gets or sets a value that indicates which pen tip to use when drawing ink that is associated with this [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) object.

This property is read/write.

## Parameters

## Remarks

For a complete list of pen tips available to use, see the [InkPenTip](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpentip) enumeration.

When this property is set to [InkPenTip.IPT_Ball](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpentip), the [Height](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_height) property is ignored.

To create a square pen tip, set the **PenTip** property to [InkPenTip.IPT_Rectangle](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpentip). Then set the [Height](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_height) property equal to the [Width](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_width) property.

## See also

[Height Property [InkDrawingAttributes Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_height)

[IInkDrawingAttributes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdrawingattributes)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkPenTip Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpentip)

[Width Property [InkDrawingAttributes Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_width)