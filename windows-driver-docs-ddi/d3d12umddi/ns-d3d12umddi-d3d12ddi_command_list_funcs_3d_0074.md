## Description

**D3D12DDI_COMMAND_LIST_FUNCS_3D_0074** is used to provide pointers to the user-mode driver's command list 3D DDI functions for version Direct3D 12 Release 7, Build rev 4.

## Members

### `pfnCloseCommandList`

Close the command list.

### `pfnResetCommandList`

Reset the command list.

### `pfnDrawInstanced`

Draw instanced.

### `pfnDrawIndexedInstanced`

Draw indexed instanced.

### `pfnDispatch`

Dispatch.

### `pfnClearUnorderedAccessViewUint`

Clear the unordered access view of UINT values.

### `pfnClearUnorderedAccessViewFloat`

Clear the unordered access view of FLOAT values.

### `pfnClearRenderTargetView`

Clear the render target view.

### `pfnClearDepthStencilView`

Clear the depth stencil view.

### `pfnDiscardResource`

Discard resource.

### `pfnCopyTextureRegion`

Copy texture region.

### `pfnResourceCopy`

Resource copy.

### `pfnCopyTiles`

Copy tiles.

### `pfnCopyBufferRegion`

Copy buffer region.

### `pfnResourceResolveSubresource`

Resource resolve subresource.

### `pfnExecuteBundle`

Execute bundle.

### `pfnExecuteIndirect`

Execute indirect.

### `pfnResourceBarrier`

Resource barrier.

### `pfnBlt`

Blt.

### `pfnPresent`

Present.

### `pfnBeginQuery`

Begin query.

### `pfnEndQuery`

End query.

### `pfnResolveQueryData`

Resolve query data.

### `pfnSetPredication`

Set predication.

### `pfnIaSetTopology`

Set topology.

### `pfnRsSetViewports`

Set view ports.

### `pfnRsSetScissorRects`

Set scissor rectangles.

### `pfnOmSetBlendFactor`

Set blend factor.

### `pfnOmSetStencilRef`

Set stencil reference.

### `pfnSetPipelineState`

Set pipeline state.

### `pfnSetDescriptorHeaps`

Set descriptor heaps.

### `pfnSetComputeRootSignature`

Set compute root signature.

### `pfnSetGraphicsRootSignature`

Set graphics root signature.

### `pfnSetComputeRootDescriptorTable`

Set compute root descriptor table.

### `pfnSetGraphicsRootDescriptorTable`

Set graphics root descriptor table.

### `pfnSetComputeRoot32BitConstant`

Set compute root 32-bit constant.

### `pfnSetGraphicsRoot32BitConstant`

Set graphics root 32-bit constant.

### `pfnSetComputeRoot32BitConstants`

Set compute root 32-bit constants.

### `pfnSetGraphicsRoot32BitConstants`

Set graphics root 32-bit constants.

### `pfnSetComputeRootConstantBufferView`

Set compute root constant buffer view.

### `pfnSetGraphicsRootConstantBufferView`

Set graphics root constant buffer view.

### `pfnSetComputeRootShaderResourceView`

Set compute root shader resource view.

### `pfnSetGraphicsRootShaderResourceView`

Set graphics root shader resource view.

### `pfnSetComputeRootUnorderedAccessView`

Set compute root unordered access view.

### `pfnSetGraphicsRootUnorderedAccessView`

Set graphics root unordered access view.

### `pfnIASetIndexBuffer`

Set index buffer.

### `pfnIASetVertexBuffers`

Set vertex buffers.

### `pfnSOSetTargets`

Set targets.

### `pfnOMSetRenderTargets`

Set render targets.

### `pfnSetMarker`

Set marker.

### `pfnClearRootArguments`

Clear root arguments.

### `pfnAtomicCopyBufferRegion`

Atomic copy buffer region.

### `pfnOMSetDepthBounds`

Set depth bounds.

### `pfnSetSamplePositions`

Set sample positions.

### `pfnResourceResolveSubresourceRegion`

Resource resolve subresource region.

### `pfnSetProtectedResourceSession`

Set protected resource session.

### `pfnWriteBufferImmediate`

Write buffer immediate.

### `pfnSetViewInstanceMask`

Set view instance mask.

### `pfnInitializeMetaCommand`

Initialize a meta-command.

### `pfnExecuteMetaCommand`

Execute a meta-command.

### `pfnBuildRaytracingAccelerationStructure`

Build a ray tracing acceleration structure.

### `pfnEmitRaytracingAccelerationStructurePostbuildInfo`

Emit ray tracing acceleration structure post build info.

### `pfnCopyRaytracingAccelerationStructure`

Copy ray tracing acceleration structure.

### `pfnSetPipelineState1`

Set pipeline state.

### `pfnDispatchRays`

Dispatch rays.

### `pfnRSSetShadingRate`

Sets the command-level shading rate and combiners.

### `pfnRSSetShadingRateImage`

Sets the screen space image.

### `pfnDispatchMesh`

Pointer to a [**PFND3D12DDI_DISPATCH_MESH_0074**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_mesh_0074) callback function.

## Remarks

The graphics kernel calls the user mode-driver's [**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable) callback with a [**tableType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type) value of **D3D12DDI_TABLE_TYPE_COMMAND_LIST_3D** to obtain the UMD's 3D command list functions for this DDI version.

## See also

[**D3D12DDI_TABLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type)

[**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable)