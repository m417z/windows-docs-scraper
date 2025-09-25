# IInkOverlay::put_AutoRedraw

## Description

Gets or sets a value that specifies whether an ink collector repaints the ink when the window is invalidated.

This property is read/write.

## Parameters

## Remarks

If **TRUE**, the ink collector repaints the ink when the window is invalidated. For example, if you minimize the window and then restore it, the ink is automatically redrawn. If **FALSE**, the ink collector does not repaint the ink when the window is invalidated. For example, if you minimize the window and then restore it, the ink disappears from the screen.

When [AutoRedraw](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_autoredraw) is **FALSE**, the ink appears while inking unless the [DynamicRendering](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_dynamicrendering) property is false.

When your application is performing custom rendering or when your application is sensitive to painting issues, you can handle the repainting yourself and set the [AutoRedraw](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_autoredraw) property to **FALSE** for the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object, the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object, or the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control. Use the events in the following table to handle the repainting.

| Object or Control | Event |
| --- | --- |
| InkCollector Object | The underlying controls Invalidated and Paint events. |
| InkOverlay Object | The underlying controls Invalidated and Paint events. |
| InkPicture Control | InkPicture controls inherited Invalidated and Paint events. |

## See also

[Draw Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-draw)

[DynamicRendering Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_dynamicrendering)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)