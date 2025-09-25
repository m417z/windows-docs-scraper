# IInkDrawingAttributes::get_Color

## Description

Gets or sets the color of the ink that is drawn with this [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) object.

This property is read/write.

## Parameters

## Remarks

In High Contrast mode, ink always appears with the system color setting (COLOR_WINDOWTEXT), regardless of the setting of the **Color** property. However, the actual color of the ink is always saved as the set color, or default color (**BLACK**) if not set. For example, if the **Color** property is set to **RED**, a user in High Contrast mode sees the ink in the system color, but a user not in High Contrast mode sees the ink drawn as the set color **RED**. This functionality allows a user in High Contrast mode to view the ink in the system setting without modifying the actual stroke color.

This means that by default all ink is mapped to one color when in High Contrast mode. To disable this default color-mapping behavior and implement your own, use the ink collector's [SupportHighContrastInk](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_supporthighcontrastink) property.

To effectively enable High Contrast mode, you must set the ink collector's [AutoRedraw](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_autoredraw) property to **TRUE** (which means that ink is redrawn when the window is invalidated). The Tablet PC application programming interface (API) does not support High Contrast mode if you set the **AutoRedraw** property to **FALSE**.

## See also

[AutoRedraw Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_autoredraw)

[Draw Method [InkRenderer Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-draw)

[IInkDrawingAttributes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdrawingattributes)

[InkDrawingAttribute Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[SupportHighContrastInk Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_supporthighcontrastink)