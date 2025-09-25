# IInkPicture::get_InkEnabled

## Description

Gets or sets a value that specifies whether the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control collects pen input (in-air packets, cursor in range events, and so on).

This property is read/write.

## Parameters

## Remarks

The [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control) control collects ink in Windows Vista, Microsoft Windows XP Tablet PC Edition or any edition of Windows 2000, Windows Server 2003, or Windows XP on which the Windows XP Tablet PC Edition Software Development Kit (SDK) is installed. However, handwriting recognition occurs only if Windows Vista, Windows XP Tablet PC Edition, or the Recognizer Pack is installed.

In any edition of Windows 2000, Windows Server 2003, or of Windows XP other than Windows XP Tablet PC Edition, the **InkEnabled** property is always **FALSE** if the Tablet PC SDK is not installed.

If the window input rectangle of an enabled object (set in the constructor or with the [SetWindowInputRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setwindowinputrectangle)) overlaps the window input rectangle of another enabled object, the E_INK_OVERLAPPING_INPUT_RECT error is returned.

**Note** Overlap can occur without an error as long as only one of the input rectangles is enabled at any time.

While the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control is not enabled, you receive no events.

When the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_enabled) property of a container [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control is set to **VARIANT_FALSE**, all of its contained controls are disabled as well.

You cannot set this property to **VARIANT_FALSE** while the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control is collecting ink (the [CollectingInk Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_collectingink) property is **VARIANT_TRUE**).

For best results, set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_enabled) property to **VARIANT_FALSE** when an application shuts down.

This property must be set to **VARIANT_FALSE** before setting or calling specific properties and methods of the control. If you try to change the specified properties or call the specified methods, an error occurs. The following properties and methods cannot be set or called unless the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_enabled) property is first set to **VARIANT_FALSE**:

1. Properties:
   * [Ink](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_ink)
   * [MarginX Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_marginx)
   * [MarginY Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_marginy)
2. Methods:
   * [SetAllTabletsMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setalltabletsmode)
   * [SetSingleTabletIntegratedMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setsingletabletintegratedmode)

## See also

[CollectionMode Property [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_collectionmode)

[EditingMode Property [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_editingmode)

[Enabled Property [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_enabled)

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[Ink Property [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_ink)

[InkPicture Control](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control)

[MarginX Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_marginx)

[MarginY Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_marginy)

[SetAllTabletsMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setalltabletsmode)

[SetSingleTabletIntegratedMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setsingletabletintegratedmode)

[SetWindowInputRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setwindowinputrectangle)