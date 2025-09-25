# D3D10_DDI_STENCIL_OP enumeration

## Description

The D3D10_DDI_STENCIL_OP enumeration type contains values that identify operations on stencil buffers in a call to the driver's [CreateDepthStencilState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilstate) function.

## Constants

### `D3D10_DDI_STENCIL_OP_KEEP`

Do not update the entry in the stencil buffer. D3D10_DDI_STENCIL_OP_KEEP is the default value.

### `D3D10_DDI_STENCIL_OP_ZERO`

Set the stencil-buffer entry to 0.

### `D3D10_DDI_STENCIL_OP_REPLACE`

Replace the stencil-buffer entry with a reference value.

### `D3D10_DDI_STENCIL_OP_INCR_SAT`

Increment the stencil-buffer entry, clamping to the maximum value.

### `D3D10_DDI_STENCIL_OP_DECR_SAT`

Decrement the stencil-buffer entry, clamping to zero.

### `D3D10_DDI_STENCIL_OP_INVERT`

Invert the bits in the stencil-buffer entry.

### `D3D10_DDI_STENCIL_OP_INCR`

Increment the stencil-buffer entry, wrapping to zero if the new value exceeds the maximum value.

### `D3D10_DDI_STENCIL_OP_DECR`

Decrement the stencil-buffer entry, wrapping to the maximum value if the new value is less than zero.

## See also

[CreateDepthStencilState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilstate)