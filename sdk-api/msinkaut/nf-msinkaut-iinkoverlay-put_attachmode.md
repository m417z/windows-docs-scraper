# IInkOverlay::put_AttachMode

## Description

Gets or sets the value that specifies whether the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object is attached behind or in front of the known window.

This property is read/write.

## Parameters

## Remarks

**Note** An error occurs if the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object is not disabled before setting this property. To disable the **InkOverlay** object, set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property to **FALSE**. You can then set the **AttachMode** property and re-enable the object by setting the **Enabled** property to **TRUE**.

**Caution** If **AttachMode** is set to [InFront](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkoverlayattachmode) and then a control is added to the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)'s attached control, then you will have to reset the **InkOverlay**'s [hWnd](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_hwnd). First set [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) to **FALSE**, then set the **hWnd** property, and then set **Enabled** to **TRUE**.

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkOverlayAttachMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkoverlayattachmode)