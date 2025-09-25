# RenderingControls function

## Description

Returns a filled D2D1_RENDERING_CONTROLS structure.

## Parameters

### `bufferPrecision`

Type: **[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)**

The buffer precision used by default if the buffer precision is not otherwise specified by the effect or the transform.

### `tileSize`

Type: **[D2D1_SIZE_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-u)**

The minimum tile allocation size to be used by the imaging effect renderer.

## Return value

Type: **[D2D1_RENDERING_CONTROLS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_rendering_controls)**

Describes limitations to be applied to an imaging effect renderer.