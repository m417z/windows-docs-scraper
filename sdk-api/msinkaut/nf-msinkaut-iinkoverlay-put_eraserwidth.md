# IInkOverlay::put_EraserWidth

## Description

Gets or sets the value that specifies the width of the eraser pen tip.

This property is read/write.

## Parameters

## Remarks

The value specifies the width of the eraser pen tip in ink space units.

You cannot assign negative values to this property.

This property applies only when the [EditingMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_editingmode) property is set to **IOEM_Delete** and the [EraserMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_erasermode) property is set to **IOERM_PointErase**.

## See also

[EditingMode Property [InkOverlay Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_editingmode)

[EraserMode Property [InkOverlay Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_erasermode)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkOverlayEditingMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkoverlayeditingmode)

[InkOverlayEraserMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkoverlayerasermode)