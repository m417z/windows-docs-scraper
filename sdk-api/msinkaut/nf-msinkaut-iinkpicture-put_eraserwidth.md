# IInkPicture::put_EraserWidth

## Description

Gets or sets a value that specifies the width of the eraser pen tip.

This property is read/write.

## Parameters

## Remarks

The value specifies the width of the eraser pen tip in ink space units.

You cannot assign negative values to this property.

This property applies only when the [EditingMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_editingmode) property is set to **IOEM_Delete** and the [EraserMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_erasermode) property is set to **IOERM_PointErase**.

## See also

[EditingMode [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_editingmode)

[EraserMode [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_erasermode)

[EraserMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkoverlayerasermode)

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkPicture Control](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control)