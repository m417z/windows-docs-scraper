# ID2D1CommandSink::DrawGeometry

## Description

Indicates the geometry to be drawn to the command sink.

## Parameters

### `geometry` [in]

Type: **[ID2D1Geometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1geometry) ***

The geometry to be stroked.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush that will be used to fill the stroked geometry.

### `strokeWidth`

Type: **FLOAT**

The width of the stroke.

### `strokeStyle` [in, optional]

Type: **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of the stroke.

## Return value

Type: **HRESULT**

An HRESULT.

## Remarks

[Ellipses](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1ellipsegeometry) and [rounded rectangles](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1roundedrectanglegeometry) are converted to the corresponding ellipse and rounded rectangle geometries before calling into the **DrawGeometry** method.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::DrawGeometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-drawgeometry)