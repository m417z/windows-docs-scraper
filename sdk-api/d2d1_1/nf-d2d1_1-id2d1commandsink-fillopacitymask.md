# ID2D1CommandSink::FillOpacityMask

## Description

Fills an opacity mask on the command sink.

## Parameters

### `opacityMask` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap whose alpha channel will be sampled to define the opacity mask.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush with which to fill the mask.

### `destinationRectangle` [in, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The destination rectangle in which to fill the mask. If not specified, this is the origin.

### `sourceRectangle` [in, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The source rectangle within the opacity mask. If not specified, this is the entire mask.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The opacity mask bitmap must be considered to be clamped on each axis.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::FillOpacityMask](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1rendertarget-fillopacitymask)