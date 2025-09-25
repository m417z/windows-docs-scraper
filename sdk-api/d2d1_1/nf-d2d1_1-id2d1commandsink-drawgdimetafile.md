# ID2D1CommandSink::DrawGdiMetafile

## Description

Draw a metafile to the device context.

## Parameters

### `gdiMetafile` [in]

Type: **[ID2D1GdiMetafile](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafile)***

The metafile to draw.

### `targetOffset` [in, optional]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The offset from the upper left corner of the render target.

## Return value

This method does not return a value.

## Remarks

The *targetOffset* defines the offset in the destination space that the image will be rendered to. The entire logical extent of the image is rendered to the corresponding destination. If you don't specify the offset, the destination origin will be (0, 0). The top, left corner of the image will be mapped to the target offset. This will not necessarily be the origin.

## See also

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)