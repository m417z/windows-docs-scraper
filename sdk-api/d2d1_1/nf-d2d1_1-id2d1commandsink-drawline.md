# ID2D1CommandSink::DrawLine

## Description

Draws a line drawn between two points.

## Parameters

### `point0`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The start point of the line.

### `point1`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The end point of the line.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to fill the line.

### `strokeWidth`

Type: **FLOAT**

The width of the stroke to fill the line.

### `strokeStyle` [in, optional]

Type: **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of the stroke. If not specified, the stroke is solid.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

### Additional References

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::DrawLine](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-drawline)