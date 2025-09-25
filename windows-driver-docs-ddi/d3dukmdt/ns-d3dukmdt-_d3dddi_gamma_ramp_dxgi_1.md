# _D3DDDI_GAMMA_RAMP_DXGI_1 structure

## Description

The D3DDDI_GAMMA_RAMP_DXGI_1 structure describes a gamma function.

## Members

### `Scale`

A [D3DDDI_DXGI_RGB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_dxgi_rgb) structure that holds the scale for the gamma function.

### `Offset`

A [D3DDDI_DXGI_RGB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_dxgi_rgb) structure that holds the offset for the gamma function.

### `GammaCurve`

An array of [D3DDDI_DXGI_RGB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_dxgi_rgb) structures that describe the curve of the gamma function.

## See also

[D3DDDI_DXGI_RGB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_dxgi_rgb)