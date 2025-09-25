## Description

A **D3D12DDI_BARRIER_SYNC** value is a bit-wise OR of the following fields that specify the synchronization scope of GPU work with respect to the barrier.

## Constants

### `D3D12DDI_BARRIER_SYNC_NONE:0x0`

Synchronization is not needed either before or after a barrier. When used, **D3D12DDI_BARRIER_SYNC_NONE** must be the only bit set.

A **SyncBefore** value of **D3D12DDI_BARRIER_SYNC_NONE** implies there has been no preceding barriers or accesses made to the resource in the same [ExecuteCommandLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_executecommandlists) scope.

A **SyncAfter** value of **D3D12DDI_BARRIER_SYNC_NONE** implies that the corresponding subresources are not accessed after the barrier in the same [ExecuteCommandLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_executecommandlists) scope.

In both cases, **AccessAfter** must be [**D3D12DDI_BARRIER_ACCESS_NO_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access).

### `D3D12DDI_BARRIER_SYNC_ALL:0x1`

A **SyncBefore** value of **D3D12DDI_BARRIER_SYNC_ALL** indicates all preceding work must complete before executing the barrier.

A **SyncAfter** value of **D3D12DDI_BARRIER_SYNC_ALL** indicates all subsequent work must wait for the barrier to complete.

### `D3D12DDI_BARRIER_SYNC_DRAW:0x2`

This value is an umbrella scope for all Draw pipeline stages. Synchronize against the following GPU workloads:

* *DrawInstanced*
* *DrawIndexedInstanced*
* *SetGraphicsRootDescriptorTable*
* *SetGraphicsRootShaderResource*
* *SetGraphicsRootUnorderedAccessView*
* *SetGraphicsRootConstantBufferView*

The *SetGraphicsRootXxx* synchronization is required to support [**D3D12DDI_DESCRIPTOR_RANGE_FLAG_0013_DATA_STATIC_WHILE_SET_AT_EXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_descriptor_range_flags) descriptors.

A **SyncBefore** value of **D3D12DDI_BARRIER_SYNC_DRAW** indicates all preceding Draw work must complete before executing the barrier.

A **SyncAfter** value of **D3D12DDI_BARRIER_SYNC_DRAW** indicates all subsequent Draw work must wait for the barrier to complete.

### `D3D12DDI_BARRIER_SYNC_INPUT_ASSEMBLER:0x4`

Synchronize against Input Assembler stage execution.

### `D3D12DDI_BARRIER_SYNC_INDEX_INPUT:0x4`

Maps to D3D12DDI_BARRIER_SYNC_INPUT_ASSEMBLER.

### `D3D12DDI_BARRIER_SYNC_VERTEX_SHADING:0x8`

Synchronize against all vertex shading stages, including vertex, domain, hull, tessellation, geometry, amplification and mesh shading.

### `D3D12DDI_BARRIER_SYNC_PIXEL_SHADING:0x10`

Synchronize against pixel shader execution.

### `D3D12DDI_BARRIER_SYNC_DEPTH_STENCIL:0x20`

Synchronize against depth/stencil read/write operations. This includes depth-stencil view (DSV) accesses during Draw* and ClearRenderTargetView.

### `D3D12DDI_BARRIER_SYNC_RENDER_TARGET:0x40`

Synchronize against render target read/write operations. This includes render-target view (RTV) writes during Draw* and ClearRenderTargetView.

### `D3D12DDI_BARRIER_SYNC_COMPUTE_SHADING:0x80`

Synchronize against the following GPU workloads:

* *Dispatch*
* *SetComputeRootDescriptorTable*
* *SetComputeRootShaderResource*
* *SetComputeRootUnorderedAccessView*
* *SetComputeRootConstantBufferView*

The *SetComputeRootXxx* synchronization is required to support **D3D12DDI_DESCRIPTOR_RANGE_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTION** descriptors.

### `D3D12DDI_BARRIER_SYNC_RAYTRACING:0x100`

Synchronize against raytracing execution.

### `D3D12DDI_BARRIER_SYNC_COPY:0x200`

Synchronize against Copy commands.

### `D3D12DDI_BARRIER_SYNC_RESOLVE:0x400`

Synchronize against Resolve commands.

### `D3D12DDI_BARRIER_SYNC_EXECUTE_INDIRECT:0x800`

Synchronize against ExecuteIndirect execution.

### `D3D12DDI_BARRIER_SYNC_PREDICATION:0x800`

Synchronize against Predication commands. Aliased with *D3D12DDI_BARRIER_SYNC_EXECUTE_INDIRECT**.

### `D3D12DDI_BARRIER_SYNC_ALL_SHADING:0x1000`

Synchronize against all shader execution.

### `D3D12DDI_BARRIER_SYNC_NON_PIXEL_SHADING:0x2000`

Synchronize against shader execution except pixel shading. Exists for compatibility with the legacy ResourceBarrier API.

### `D3D12DDI_BARRIER_SYNC_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO:0x4000`

Synchronize against [**PFND3D12DDI_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_emit_raytracing_acceleration_structure_postbuild_info_0054) work.

### `D3D12DDI_BARRIER_SYNC_CLEAR_UNORDERED_ACCESS_VIEW:0x8000`

Synchronize against execution to a UAV.

### `D3D12DDI_BARRIER_SYNC_VIDEO_DECODE:0x100000`

Synchronize against Video Decode execution.

### `D3D12DDI_BARRIER_SYNC_VIDEO_PROCESS:0x200000`

Synchronize against Video Process execution.

### `D3D12DDI_BARRIER_SYNC_VIDEO_ENCODE:0x400000`

Synchronize against Video Encode execution.

### `D3D12DDI_BARRIER_SYNC_BUILD_RAYTRACING_ACCELERATION_STRUCTURE:0x800000`

Synchronize against [**PFND3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_build_raytracing_acceleration_structure_0054) work.

The corresponding barrier **AccessBefore** or **AccessAfter** field must have the **D3D12DDI_BARRIER_ACCESS_RAYTRACING_ACCELERATION_STRUCTURE_WRITE** bit set.

### `D3D12DDI_BARRIER_SYNC_COPY_RAYTRACING_ACCELERATION_STRUCTURE:0x1000000`

Synchronize against [**PFND3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_build_raytracing_acceleration_structure_0054) work.

The corresponding barrier **AccessBefore** or **AccessAfter** field must have the **D3D12DDI_BARRIER_ACCESS_RAYTRACING_ACCELERATION_STRUCTURE_WRITE** bit set.

### `D3D12DDI_BARRIER_SYNC_SPLIT:0x80000000`

Special sync bit indicating a split barrier. Used as a **SyncAfter** value to indicate the start of a split barrier. The application must provide a matching barrier with **SyncBefore** set to D3D12DDI_BARRIER_SYNC_SPLIT. See Remarks.

## Remarks

A split barrier is a hint to the driver that a state transition must occur between two points in a command stream, even cross ExecuteCommandLists boundaries. Drivers can complete the required layout transitions and cache flushes any time between the start and end of a split barrier.

Enhanced Barrier APIs allow SPLIT synchronization. Split barriers are represented by a pair of barriers where the initial barrier uses a **D3D12DDI_BARRIER_SYNC_SPLIT** **SyncAfter** value, and the final barrier uses a **D3D12DDI_BARRIER_SYNC_SPLIT** **SyncBefore** value.

Split barrier pairs must use identical **LayoutBefore**, **LayoutAfter**, **AccessBefore**, and **AccessAfter** values for both the initial and final barriers. Split barrier pairs must be sequential with no other intervening barriers on the same resource. The following code snippet is an application-level example.

``` cpp
// BEGIN split from compute shader UAV to pixel shader SRV
splitBarrierBegin.SyncBefore = D3D12_BARRIER_SYNC_COMPUTE
splitBarrierBegin.SyncAfter = D3D12_BARRIER_SYNC_SPLIT
splitBarrierBegin.AccessBefore = D3D12_BARRIER_ACCESS_UNORDERED_ACCESS
splitBarrierBegin.AccessAfter = D3D12_BARRIER_ACCESS_DIRECT_QUEUE_SHADER_RESOURCE
splitBarrierBegin.LayoutBefore = D3D12_BARRIER_LAYOUT_UNORDERED_ACCESS
splitBarrierBegin.LayoutAfter = D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_SHADER_RESOURCE

// END split from compute shader UAV to pixel shader SRV
splitBarrierEnd.SyncBefore = D3D12_BARRIER_SYNC_SPLIT
splitBarrierEnd.SyncAfter = D3D12_BARRIER_SYNC_PIXEL_SHADING
splitBarrierEnd.AccessBefore = D3D12_BARRIER_ACCESS_UNORDERED_ACCESS
splitBarrierEnd.AccessAfter = D3D12_BARRIER_ACCESS_DIRECT_QUEUE_SHADER_RESOURCE
splitBarrierEnd.LayoutBefore = D3D12_BARRIER_LAYOUT_UNORDERED_ACCESS
splitBarrierEnd.LayoutAfter = D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_SHADER_RESOURCE

```

Split barriers across ExecuteCommandLists boundaries are allowed. In this case all **AccessBefore** and **AccessAfter** values are effectively ignored since the ExecuteCommandLists boundaries takes care of any cache flushing. Essentially, cross-ExecuteCommandLists split barriers are layout-only barriers. Therefore, splitting a buffer barrier or a simultaneous-access texture barrier across ExecuteCommandLists boundaries serves no purpose. An unmatched BEGIN or END split barrier on a buffer or simultaneous-access texture in a given ExecuteCommandLists scope is effectively unused and the Debug Layer produces a warning.

## See also

[**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access)

[**D3D12DDI_BUFFER_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_buffer_barrier_0088)

[**D3D12DDI_GLOBAL_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_global_barrier_0088)

[**D3D12DDI_RANGED_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_ranged_barrier_0088)

[**D3D12DDI_TEXTURE_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_texture_barrier_0088)