# ID2D1CommandSink::FillGeometry

## Description

Indicates to the command sink a geometry to be filled.

## Parameters

### `geometry` [in]

Type: **[ID2D1Geometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1geometry)***

The geometry that should be filled.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The primary brush used to fill the geometry.

### `opacityBrush` [in, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

A brush whose alpha channel is used to modify the opacity of the primary fill brush.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

If the opacity brush is specified, the primary brush will be a bitmap brush fixed on both the x-axis and the y-axis.

Ellipses and rounded rectangles are converted to the corresponding geometry before being passed to **FillGeometry**.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::FillGeometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-fillgeometry)