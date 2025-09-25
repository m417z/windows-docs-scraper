# IInkCollector::put_hWnd

## Description

Gets or sets the handle value of the window on which ink is drawn.

This property is read/write.

## Parameters

## Remarks

If two or more windows exist, this property allows you to specify which window collects ink.

**Note** The [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object or the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object must be disabled before setting this property. To disable the **InkCollector** or **InkOverlay** objects, set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property to **FALSE**. You can then set the **hWnd** property and re-enable the object by setting the **Enabled** property to **TRUE**.

In Automation, this property is called **hWnd Property**.

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[IInkCollector](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkcollector)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)