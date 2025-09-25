# IInkOverlay::put_EditingMode

## Description

Gets or sets a value that specifies whether the object/control is in ink mode, deletion mode, or selecting/editing mode.

This property is read/write.

## Parameters

## Remarks

The [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) and [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) objects generate an error if you change the **EditingMode** property while ink is being collected. To avoid this conflict, make sure the [CollectingInk](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectingink) property is **FALSE** before changing the **EditingMode** property.

For more information about erasing ink, see [Erasing Ink with the Pen](https://learn.microsoft.com/windows/desktop/tablet/erasing-ink-with-the-pen).

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkEnabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_inkenabled)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkOverlayEditingMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkoverlayeditingmode)