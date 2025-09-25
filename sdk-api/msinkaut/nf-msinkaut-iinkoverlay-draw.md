# IInkOverlay::Draw

## Description

Sets a rectangle in which to redraw the ink within the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object.

## Parameters

### `Rect` [in]

The rectangle on which to draw, in pixel coordinates. When this parameter is **NULL**, the entire window is redrawn.

## Return value

This method can return one of these values.

## Remarks

[InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) within the rectangle represented by *rDrawRect* is drawn when the area is next repainted if the [AutoRedraw](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_autoredraw) property is **TRUE**.

## See also

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkRectangle Class](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class)