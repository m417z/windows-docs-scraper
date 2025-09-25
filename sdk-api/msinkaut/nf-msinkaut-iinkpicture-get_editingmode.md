# IInkPicture::get_EditingMode

## Description

Gets or sets a value that specifies whether the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control is in ink mode, deletion mode, or selecting/editing mode.

This property is read/write.

## Parameters

## Remarks

The [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) and [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) objects generate an error if you change the **EditingMode** property while ink is being collected. To avoid this conflict, make sure the [CollectingInk](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_collectingink) property is **FALSE** before changing the **EditingMode** property.

For more information about erasing ink, see [Erasing Ink with the Pen](https://learn.microsoft.com/windows/desktop/tablet/erasing-ink-with-the-pen).

## See also

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkPicture Control](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control)