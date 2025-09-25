# IInkPicture::get_hWnd

## Description

Gets or sets the handle value of the window on which ink is drawn.

This property is read/write.

## Parameters

## Remarks

If two or more windows exist, this property allows you to specify which window collects ink.

**Note** The [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object or the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object must be disabled before setting this property. To disable the **InkCollector** or **InkOverlay** objects, set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property to **VARIANT_FALSE**. You can then set the [hWnd](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_hwnd) property and re-enable the object by setting the **Enabled** property to **VARIANT_TRUE**.

In Automation, this property is called [hWnd Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_hwnd).

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkPicture Control](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control)