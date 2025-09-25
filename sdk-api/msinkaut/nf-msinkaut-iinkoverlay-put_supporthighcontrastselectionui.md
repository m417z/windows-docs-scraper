# IInkOverlay::put_SupportHighContrastSelectionUI

## Description

Gets or sets a value that specifies whether all selection user interface (UI) elements are drawn in high contrast when the system is in High Contrast mode.

This property is read/write.

## Parameters

## Remarks

This property changes the way selection UI is displayed when the system changes to High Contrast mode. Selection UI elements include the selection bounding box and the selection handles.

Ink selection uses the COLOR_WINDOWTEXT, COLOR_WINDOW, and COLOR_HIGHLIGHT system colors to draw elements of the selection UI when the system is in High Contrast mode and the **SupportHighContrastSelectionUI** property is **TRUE**. For more information on system colors, see the [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) function.

## See also

[Color Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_color)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[SupportHighContrastInk Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_supporthighcontrastink)