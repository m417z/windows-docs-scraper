# D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_TYPE enumeration

## Description

Declares the type of resource access for the call to [PFND3D12DDI_BEGIN_RENDER_PASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass).

## Constants

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_DISCARD`

Indicates that the application does not have any dependency on the prior contents of the resource.

A given implementation may return the previously-written contents, or it may return uninitialized data. However, reading from the resource must not produce a GPU hang, the 'read' may only return undefined data in the worst case.
A read is defined as a traditional:

* UAV (Unordered Access View)
* SRV (Shader Resource View)
* CBV (Constant Buffer View)
* VBV (Vertex Buffer View)
* IBV (Index Buffer View)
* IndirectArg binding/read
* blend/depth-testing-induced read

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_PRESERVE`

Indicates that the application has a dependency on the prior contents of the resource, and the contents must be loaded from main memory.

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_CLEAR`

Indicates that the application has a dependency on the resource being cleared to a specific (app-provided) color.

> [!NOTE]
> This clear occurs whether or not the resource has interacted with anything beyond the Render Pass.

The API will allow the application to specify the clear values in the call to [PFND3D12DDI_BEGIN_RENDER_PASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass), via the [D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_clear_parameters) structure.

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_NO_ACCESS`

Indicates that the resource will not be read from or written to during the Render Pass. This value also indicates whether the depth/stencil plane for a DSV (Data Source View) was not accessed.

> [!IMPORTANT]
> This field must be paired with the *D3D12DDI_RENDER_PASS_ENDING_ACCESS_NO_ACCESS* flag in [D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type).

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_RESUME_WRITING`

Indicates that the application is to resume writing in the following conditions:

* Resumes writing to a surface that was previously written to in the previous Render Pass
* Has the *D3D12DDI_RENDER_PASS_ENDING_ACCESS_SUSPEND_WRITING* flag in the [D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type) enumeration
* There was no intervening GPU work that occurred between the two Render Passes

The writing in the *resuming* Render Pass occurs right after the writing in the *suspending* Render Pass.
The intent of this flag is to allow writes to the same Render Target in order to span multiple command lists, and without flushing any on-chip caches.
Writing may resume from a Render Pass in a separate Command List, as long as the suspending/resuming Command Lists are executed (back to back) in the same ExecuteCommandLists group.

### `D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_RESUME_LOCAL_READ`

Indicates that the application wants to read from a resource that was previously and immediately written to by the GPU (i.e. still potentially in tile cache), and will be read from in a pixel-local fashion (i.e. reads will always be on the exact output pixel, or adjacent pixels).

This enumeration value, paired with *D3D12DDI_RENDER_PASS_ENDING_ACCESS_SUSPEND_LOCAL_READ* value in the [D3D12DDI_RENDER_PASS_ENDING_ACCESS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_ending_access_type) enumeration, is to allow resources to be read from, when possible, without issuing a flush between two subsequent Render Pass operations.

Specifically, the application warrants:

* The resource has previously been written to in a Render Pass that had the ‘write’ characteristics of *D3D12DDI_RENDER_PASS_ENDING_ACCESS_SUSPEND_LOCAL_READ*.
* No GPU operations have occurred between the previous Render Pass’ D3D12DDI_RENDER_PASS_ENDING_ACCESS_SUSPEND_LOCAL_READ and the current Render Pass.
    * A D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_RESUME_LOCAL_READ may be chained from within the same Command List, or between Command Lists in the same ExecuteCommandLists call, but not across separate ExecuteCommandLists calls.
* The resource to be read from matches the size and format of the newly-bound render target.
* All reads/writes are ‘1-to-1’ (plus optional gutter read pixels specified by the app), the reads from the source texture will be written to the same location on the target texture, and the render target texture is the same size as the source texture.

The kernel size of the read (how many surrounding pixels are needed) are specified at [PFND3D12DDI_BEGIN_RENDER_PASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass) time, through the AdditionalWidth/AdditionalHeight fields on [D3D12_RENDER_PASS_BEGINNING_ACCESS_RESUME_LOCAL_READ_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_resume_local_read_parameters). The AdditionalWidth/AdditionalHeight parameters must match those on the previous [D3D12DDI_RENDER_PASS_ENDING_ACCESS_SUSPEND_LOCAL_READ_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_suspend_local_read_parameters).

## Remarks

## See also