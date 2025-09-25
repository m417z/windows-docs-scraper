# D3D10_DDI_BLEND_OP enumeration

## Description

The D3D10_DDI_BLEND_OP enumeration type contains values that identify blending operations in a call to the driver's [CreateBlendState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createblendstate) function.

## Constants

### `D3D10_DDI_BLEND_OP_ADD`

The result is the destination added to the source (Result = Source + Destination).

### `D3D10_DDI_BLEND_OP_SUBTRACT`

The result is the destination subtracted from to the source (Result = Source - Destination).

### `D3D10_DDI_BLEND_OP_REV_SUBTRACT`

The result is the source subtracted from the destination (Result = Destination - Source).

### `D3D10_DDI_BLEND_OP_MIN`

The result is the minimum of the source and destination (Result = MIN(Source, Destination))

### `D3D10_DDI_BLEND_OP_MAX`

The result is the maximum of the source and destination (Result = MAX(Source, Destination))

## See also

[CreateBlendState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createblendstate)