# D2D1_RENDERING_CONTROLS structure

## Description

Describes limitations to be applied to an imaging effect renderer.

## Members

### `bufferPrecision`

The buffer precision used by default if the buffer precision is not otherwise specified by the effect or by the transform.

### `tileSize`

The tile allocation size to be used by the imaging effect renderer.

## Remarks

The renderer can allocate tiles larger than the minimum tile allocation. The allocated tiles will be powers of two of the minimum size on each axis, except that the size on each axis will not exceed the guaranteed maximum texture size for the device feature level.

The "minimum pixel render extent" is the size of the square tile below which the renderer will expand the tile allocation rather than attempting to subdivide the rendering tile any further. When this threshold is reached, the allocation tile size is expanded. This might occur repeatedly until either rendering can proceed, or it is determined that the graph can't be rendered.

The buffer precision is used for intermediate buffers if it is otherwise unspecified by the effects (for example, through calling [SetValue](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-setvalue(uint32_constbyte_uint32)) on the effect with the [D2D1_PROPERTY_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property) property) or the internal effect topology if required. If the buffer type on the context is [D2D1_BUFFER_PRECISION_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision), and otherwise not specified by the effect or transform, then the precision of the output will be the maximum precision of the inputs to the transform. The buffer precision does not affect the number of channels used.

## See also

[ID2D1DeviceContext::SetRenderingControls method](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-setrenderingcontrols(constd2d1_rendering_controls_))