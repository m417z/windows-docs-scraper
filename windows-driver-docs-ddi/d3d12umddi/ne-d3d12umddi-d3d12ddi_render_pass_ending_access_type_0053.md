# D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053 enumeration

## Description

The **D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053** enumeration specifies the type of resource access to provide to an application at the transition out of a render pass.

## Constants

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053_DISCARD`

Indicates that the application will have no future dependencies on the data written to the resource during this Render Pass. However, dependencies may be appropriate for a depth buffer where the depth buffer will never be textured from prior to future writes.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053_PRESERVE`

Indicates that the application will have a dependency on the written contents of this resource in the future, and they must be preserved.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053_RESOLVE`

Indicates that the resource(s) should be directly resolved to a separate resource at the conclusion of the Render Pass. An example is resolving an MSAA (Multisampling anti-aliasing) surface to a separate resource at the conclusion of the Render Pass. Ideally, this is done while the MSAA contents are currently in the tile cache, for TBDRs (Tile Based Deferred Rendering).

At the time the Render Pass ends, the driver should set members of the [**D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_resolve_parameters_0053) structure as follows:

* Set the resolve destination in the **hDstResource** resource state field.

* Set the resolve source in the **hSrcResource** resource state field.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053_NO_ACCESS`

Signifies the resource will not be read from or written to during the Render Pass. It is most expected to used to denote whether the depth/stencil plane for a DSV is not accessed.

This value must be paired with the [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053_NO_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053) enumeration value.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER`

Signifies that the resource was read or written to during the Render Pass, and data from that resource that might be in tile memory can stay there for the next Render Pass.

The driver should reference the[**D3D12DDI_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS_0101**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_preserve_local_parameters_0101) structure for this type.

This value must be paired with the [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053) enumeration value.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_SRV`

Signifies that the resource was read or written to during the Render Pass, and data from that resource that might be in tile memory can stay there for the next Render Pass.

The driver should reference the[**D3D12DDI_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS_0101**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_preserve_local_parameters_0101) structure for this type.

This value must be paired with the [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_SRV**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053) enumeration value.

### `D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_UAV`

Signifies that the resource was read or written to during the Render Pass, and data from that resource that might be in tile memory can stay there for the next Render Pass.

The driver should reference the[**D3D12DDI_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS_0101**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_preserve_local_parameters_0101) structure for this type.

This value must be paired with the [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_UAV**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053) enumeration value.

## Remarks

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_beginning_access_type_0053)

[**pfnBeginRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass_0053)