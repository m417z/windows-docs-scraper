# IInkOverlay::put_MousePointer

## Description

Gets or sets a value that indicates the type of mouse pointer that appears.

This property is read/write.

## Parameters

## Remarks

If you set the [MousePointer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_mousepointer) property to [IMP_Default](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkmousepointer), the mouse cursor setting is based on the current cursor's drawing attributes. If the ink collector is disabled, the mouse cursor setting is based on the underlying windows mouse cursor [DrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursor-get_drawingattributes) property. If the **MousePointer** property is set to **IMP_Custom** and the [MouseIcon](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_mouseicon) property is **NULL**, then the ink collector no longer handles mouse cursor settings. Setting the mouse cursor to any other setting (other than the **MousePointer** property set to **IMP_Default** and the **MouseIcon** property set to **NULL**) forces the mouse cursor to use the current setting.

You can use this property when you want to indicate changes in functionality as the mouse pointer passes over controls on a form or dialog box. The [IMP_Hourglass](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkmousepointer) setting is useful for indicating that the user should wait for a process or operation to finish.

## See also

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkMousePointer Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkmousepointer)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[MouseIcon Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_mouseicon)