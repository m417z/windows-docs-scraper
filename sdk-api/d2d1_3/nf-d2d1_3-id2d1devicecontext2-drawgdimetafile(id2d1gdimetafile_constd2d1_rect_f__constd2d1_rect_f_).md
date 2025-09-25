# ID2D1DeviceContext2::DrawGdiMetafile(ID2D1GdiMetafile,const D2D1_RECT_F &,const D2D1_RECT_F &)

## Description

Draws a metafile to the device context using the given source and destination rectangles.

## Parameters

### `gdiMetafile` [in]

Type: **[ID2D1GdiMetafile](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafile)***

The metafile to draw.

### `destinationRectangle` [ref]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The rectangle in the target where the metafile will be drawn, relative to the upper left corner (defined in DIPs) of the render target.
If NULL is specified, the destination rectangle is {0, 0, w, h}, where w and h are the width and height of the metafile as reported by
[ID2D1GdiMetafile::GetBounds](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1gdimetafile-getbounds).

### `sourceRectangle` [ref]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The rectangle of the source metafile that will be drawn, relative to the upper left corner (defined in DIPs) of the metafile.
If NULL is specified, the source rectangle is the value returned by [ID2D1GdiMetafile1::GetSourceBounds](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1gdimetafile1-getsourcebounds).

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)