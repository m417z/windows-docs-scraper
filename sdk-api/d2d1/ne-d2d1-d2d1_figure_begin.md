# D2D1_FIGURE_BEGIN enumeration

## Description

Indicates whether a specific [ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink) figure is filled or hollow.

## Constants

### `D2D1_FIGURE_BEGIN_FILLED:0`

Indicates the figure will be filled by the FillGeometry ([ID2D1CommandSink::FillGeometry](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1commandsink-fillgeometry)
or [ID2D1RenderTarget::FillGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-fillgeometry)) method.

### `D2D1_FIGURE_BEGIN_HOLLOW:1`

Indicates the figure will not be filled by the FillGeometry ([ID2D1CommandSink::FillGeometry](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1commandsink-fillgeometry)
or [ID2D1RenderTarget::FillGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-fillgeometry)) method and will only consist of an outline.
Moreover, the bounds of a hollow figure are zero.
D2D1_FIGURE_BEGIN_HOLLOW should be used for stroking, or for other geometry operations.

### `D2D1_FIGURE_BEGIN_FORCE_DWORD:0xffffffff`

## See also

[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)

[ID2D1SimplifiedGeometrySink::BeginFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-beginfigure)

[Path Geometries Overview](https://learn.microsoft.com/windows/win32/Direct2D/path-geometries-overview)