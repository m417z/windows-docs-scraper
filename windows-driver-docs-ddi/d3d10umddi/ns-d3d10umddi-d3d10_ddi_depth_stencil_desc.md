# D3D10_DDI_DEPTH_STENCIL_DESC structure

## Description

The D3D10_DDI_DEPTH_STENCIL_DESC structure describes a depth stencil state.

## Members

### `DepthEnable` [in]

A Boolean value that specifies whether depth is enabled. **TRUE** indicates depth is enabled; **FALSE** indicates depth is disabled.

### `DepthWriteMask` [in]

A bitwise value that indicates the write properties for a depth stencil state. This member is a valid bitwise OR of the following values from the D3D10_DDI_DEPTH_WRITE_MASK enumeration.

|Value|Meaning|
|--- |--- |
|D3D10_DDI_DEPTH_WRITE_MASK_ZERO (0)|No properties|
|D3D10_DDI_DEPTH_WRITE_MASK_ALL (1)|All properties|

### `DepthFunc` [in]

A [D3D10_DDI_COMPARISON_FUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_comparison_func)-typed value that indicates the depth-comparison function to perform.

### `StencilEnable` [in]

A Boolean value that specifies whether stencil is enabled. **TRUE** indicates stencil is enabled; **FALSE** indicates stencil is disabled.

### `FrontEnable` [in]

A Boolean value that specifies whether the performance of stencil operations on forward-facing polygons is enabled. **TRUE** indicates that the performance on forward-facing polygons is enabled; **FALSE** indicates that it is disabled.

### `BackEnable` [in]

A Boolean value that specifies whether the performance of stencil operations on back-facing polygons is enabled. **TRUE** indicates that the performance on back-facing polygons is enabled; **FALSE** indicates that it is disabled.

### `StencilReadMask` [in]

An 8-bit bitwise value that the driver uses in a bitwise AND operation with the stencil value in the stencil buffer immediately after reading the stencil value out of the stencil buffer.

### `StencilWriteMask` [in]

An 8-bit bitwise value that the driver uses in a bitwise AND operation with the current stencil value before writing the result back out to the stencil buffer.

### `FrontFace` [in]

A [D3D10_DDI_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_depth_stencilop_desc) structure that describes the stencil operation to perform on forward-facing polygons.

### `BackFace` [in]

A [D3D10_DDI_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_depth_stencilop_desc) structure that describes the stencil operation to perform on back-facing polygons.

## Remarks

If the **StencilEnable** member is set to **TRUE**, the **FrontEnable** member, **BackEnable** member, or both must also be set to **TRUE**.

## See also

[CalcPrivateDepthStencilStateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedepthstencilstatesize)

[CreateDepthStencilState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilstate)

[D3D10_DDI_COMPARISON_FUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_comparison_func)

[D3D10_DDI_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_depth_stencilop_desc)