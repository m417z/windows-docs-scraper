# D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053 enumeration

## Description

The **D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053** enumeration specifies the type of resource access being requested at the start of a render pass.

## Constants

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053_DISCARD`

Indicates that the application doesn't have any dependency on the prior contents of the resource.

A given driver implementation can return the previously-written contents or uninitialized data. Regardless, reading from the resource must not produce a GPU hang, and the 'read' can only return undefined data in the worst case. A read is defined as a traditional:

* UAV (Unordered Access View)
* SRV (Shader Resource View)
* CBV (Constant Buffer View)
* VBV (Vertex Buffer View)
* IBV (Index Buffer View)
* IndirectArg binding/read
* blend/depth-testing-induced read

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053_PRESERVE`

Indicates that the application has a dependency on the prior contents of the resource, and the contents must be loaded from main memory.

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053_CLEAR`

Indicates that the originating application has a dependency on the resource being cleared to a specific (app-provided) color.

This clear occurs whether or not the resource has interacted with anything beyond the Render Pass.

The clear parameters are specified in the [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_clear_parameters_0053) structure.

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0053_NO_ACCESS`

Indicates that the resource won't be read from or written to during the Render Pass. This value also indicates whether the depth/stencil plane for a DSV (Data Source View) was not accessed.

This value must be paired with the **D3D12DDI_RENDER_PASS_ENDING_ACCESS_NO_ACCESS** value in [**D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type_0053).

## D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER

This value signifies that:

* The resource was read or written in the preceding pass, and data from that resource that might be in tile memory can stay there for the current pass.

* The current pass will render to the resource in such a way that processing for a given pixel coordinate will access the same location in the resource that the previous pass accessed.

The driver should reference the[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS_0101**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_preserve_local_parameters_0101) structure for this type.

The end of the previous pass must specify [**D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type_0053) and the same **AdditionalWidth**/**AdditionalHeight** parameters.

## D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_SRV

This value signifies that:

* The resource was read or written in the preceding pass, and data from that resource that may be in tile memory can stay there for the current pass.

* The current pass will read from the resource via SRV (shader resource view) binding(s) in the descriptor heap in such a way that processing for a given pixel coordinate will access the same location in the resource that the previous pass accessed.

The driver should reference the[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_preserve_local_parameters_0101) structure for this type.

The end of the previous pass must specify [**D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_SRV**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type_0053) and the same **AdditionalWidth**/**AdditionalHeight** parameters.

## D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_UAV

This value signifies that:

* The resource was read or written in the preceding pass, and data from that resource that may be in tile memory can stay there for the current pass.

* The current pass will read/write the resource via UAV binding(s) in the descriptor heap in such a way that processing for a given pixel coordinate will access the same location in the resource that the previous pass accessed.

The driver should reference the[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_preserve_local_parameters_0101) structure for this type.

The end of the previous pass must specify [**D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE_0101_PRESERVE_LOCAL_UAV**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type_0053) and the same **AdditionalWidth**/**AdditionalHeight** parameters.

## Remarks

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE_0101_PRESERVE_LOCAL_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_preserve_local_parameters_0101)

[**pfnBeginRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass_0053)