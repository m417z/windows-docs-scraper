# ID2D1CommandSink2::DrawGdiMetafile

## Description

Draws a metafile to the command sink using the given source and destination rectangles.

## Parameters

### `gdiMetafile` [in]

Type: **[ID2D1GdiMetafile](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafile)***

The metafile to draw.

### `destinationRectangle` [in]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The rectangle in the target where the metafile will be drawn, relative to the upper left corner (defined in DIPs). If NULL is specified, the destination rectangle is the size of the target.

### `sourceRectangle` [in]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The rectangle of the source metafile that will be drawn, relative to the upper left corner (defined in DIPs).
If NULL is specified, the source rectangle is the value returned by [ID2D1GdiMetafile1::GetSourceBounds](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1gdimetafile1-getsourcebounds).

## Return value

This method does not return a value.

## See also

[ID2D1CommandSink2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1commandsink2)