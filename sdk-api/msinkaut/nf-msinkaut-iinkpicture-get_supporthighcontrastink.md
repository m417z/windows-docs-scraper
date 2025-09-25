# IInkPicture::get_SupportHighContrastInk

## Description

Gets or sets a value that specifies whether ink is rendered as just one color when the system is in High Contrast mode.

This property is read/write.

## Parameters

## Remarks

This property changes the way ink renders when the system changes to High Contrast mode.

Real-time ink application uses the COLOR_WINDOWTEXT color when the system is in High Contrast mode and the **SupportHighContrastInk** property is **TRUE**, but the inherent color of a stroke made under these conditions remains unchanged. For example, if the [Color](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_color) property is set to [RGB(0,0,255)](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) (blue), the COLOR_WINDOWTEXT color is set to RGB(255,255,255) (white), and the system is in High Contrast mode, then a newly drawn stroke renders in white but the actual stroke color is still blue. For more information about this behavior, see the **Color** property and the [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) function.

## See also

[Color Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_color)

[DefaultDrawingAttributes Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_defaultdrawingattributes)

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[SupportHighContrastSelectionUI Property [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_supporthighcontrastselectionui)