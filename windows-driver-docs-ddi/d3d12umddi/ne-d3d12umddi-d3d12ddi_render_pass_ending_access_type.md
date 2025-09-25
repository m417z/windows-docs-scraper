# D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE enumeration

## Description

## Constants

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_DISCARD`

Indicates that the application will have no future dependencies on the data written to the resource during this Render Pass. However, dependencies may be appropriate for a depth buffer where the depth buffer will never be textured from prior to future writes.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_PRESERVE`

Indicates that the application will have a dependency on the written contents of this resource in the future, and they must be preserved.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE`

Allows the application to directly resolve a MSAA (Multisampling anti-aliasing) surface to a separate resource at the conclusion of the Render Pass. Ideally, this is done while the MSAA contents are currently in the tile cache, for TBDRs (Tile Based Deferred Rendering).
The resolve destination is expected to be in the *hDstResource* resource state field of the [D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_resolve_parameters) structure, at the time the Render Pass ends.
The resolve source will be transitioned to the *hSrcResource* resource state of the [[D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_resolve_parameters) structure, at the time the Render Pass ends.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_NO_ACCESS`

Indicates the resource will not be read from or written to during the Render Pass. It is most expected to used to denote whether the depth/stencil plane for a DSV is not accessed.

> [!IMPORTANT]
> This value must be paired with the *D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_NO_ACCESS* value of the [D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type) enumeration.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_SUSPEND_WRITING`

Indicates that the application will continue writing to the resource in an immediately succeeding Render Pass, with no intervening GPU work.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_SUSPEND_LOCAL_READ`

Indicates that the application has written to the resource, and it will read from the resource in the future in a one-to-one (plus optional gutter pixels) fashion. In the pixel shader, only the current pixel plus an optional number of surrounding pixels will be read from. This enumeration also indicates that no GPU operations will occur between SUSPEND and RESUME.

## Remarks

## See also