# D3D12DDI_DEPTH_STENCIL_DESC_0025 structure

## Description

The D3D12DDI_DEPTH_STENCIL_DESC_0025 structure describes a depth stencil state.

## Members

### `DepthEnable`

A Boolean value that specifies whether depth is enabled. TRUE indicates depth is enabled; FALSE indicates depth is disabled.

### `DepthWriteMask`

A bitwise value that indicates the write properties for a depth stencil state. This member is a valid bitwise OR of the following values from the [D3D12DDI_DEPTH_WRITE_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_depth_write_mask) enumeration.

### `DepthFunc`

A [D3D12DDI_COMPARISON_FUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_comparison_func)-typed value that indicates the depth-comparison function to perform.

### `StencilEnable`

A Boolean value that specifies whether stencil is enabled. TRUE indicates stencil is enabled; FALSE indicates stencil is disabled.

### `FrontEnable`

A Boolean value that specifies whether the performance of stencil operations on forward-facing polygons is enabled. TRUE indicates that the performance on forward-facing polygons is enabled; FALSE indicates that it is disabled.

### `BackEnable`

A Boolean value that specifies whether the performance of stencil operations on back-facing polygons is enabled. TRUE indicates that the performance on back-facing polygons is enabled; FALSE indicates that it is disabled.

### `StencilReadMask`

An 8-bit bitwise value that the driver uses in a bitwise AND operation with the stencil value in the stencil buffer immediately after reading the stencil value out of the stencil buffer.

### `StencilWriteMask`

An 8-bit bitwise value that the driver uses in a bitwise AND operation with the current stencil value before writing the result back out to the stencil buffer.

### `FrontFace`

A [D3D12DDI_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_depth_stencilop_desc) structure that describes the stencil operation to perform on forward-facing polygons.

### `BackFace`

A [D3D12DDI_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_depth_stencilop_desc) structure that describes the stencil operation to perform on back-facing polygons.

### `LibraryReference`

A [D3D12DDI_LIBRARY_REFERENCE_0010](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_library_reference_0010) structure that describes the library.

### `DepthBoundsTestEnable`

TRUE to enable depth-bounds testing; otherwise, FALSE. The default value is FALSE.

## Remarks

If the StencilEnable member is set to TRUE, the FrontEnable member, BackEnable member, or both must also be set to TRUE.

## See also