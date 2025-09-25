## Description

The **D3D12DDI_DEVICE_FUNCS_CORE_0088** structure contains the core device functionality available in D3D12 Release 8, Build rev 8. The user-mode driver returns its function pointers in this structure when [**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable) is called with a [**D3D12DDI_TABLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type) of **D3D12DDI_TABLE_TYPE_DEVICE_CORE**.

## Members

### `pfnCheckFormatSupport`

Check format support.

### `pfnCheckMultisampleQualityLevels`

Check multi sample quality levels.

### `pfnGetMipPacking`

Get MIP packing.

### `pfnCalcPrivateElementLayoutSize`

Calculate private element layout size.

### `pfnCreateElementLayout`

Create element layout.

### `pfnDestroyElementLayout`

Destroy element layout.

### `pfnCalcPrivateBlendStateSize`

Calculate private blend state size.

### `pfnCreateBlendState`

Create blend state.

### `pfnDestroyBlendState`

Destroy blend state.

### `pfnCalcPrivateDepthStencilStateSize`

Calculate private depth stencil state size.

### `pfnCreateDepthStencilState`

Create depth stencil state.

### `pfnDestroyDepthStencilState`

Destroy depth stencil state.

### `pfnCalcPrivateRasterizerStateSize`

Calculate private rasterizer state size.

### `pfnCreateRasterizerState`

Create rasterizer state.

### `pfnDestroyRasterizerState`

Destroy rasterizer state.

### `pfnCalcPrivateShaderSize`

Calculate private shader size.

### `pfnCreateVertexShader`

Create vertex shader.

### `pfnCreatePixelShader`

Create pixel shader.

### `pfnCreateGeometryShader`

Create geometry shader.

### `pfnCreateComputeShader`

Create compute shader.

### `pfnCalcPrivateGeometryShaderWithStreamOutput`

Calculate private geometry shader with stream output.

### `pfnCreateGeometryShaderWithStreamOutput`

Create geometry shader with stream output.

### `pfnCalcPrivateTessellationShaderSize`

Calculate private tessellation shader size.

### `pfnCreateHullShader`

Create hull shader.

### `pfnCreateDomainShader`

Pointer to the function to create a domain shader.

### `pfnDestroyShader`

Pointer to the function to destroy a shader.

### `pfnCalcPrivateCommandQueueSize`

Pointer to the function to calculate private command queue size.

### `pfnCreateCommandQueue`

Pointer to the function to create a command queue.

### `pfnDestroyCommandQueue`

Pointer to the function to destroy a command queue.

### `pfnCalcPrivateCommandPoolSize`

Pointer to the function to calculate private command pool size.

### `pfnCreateCommandPool`

Pointer to the function to create a command pool.

### `pfnDestroyCommandPool`

Pointer to the function to destroy a command pool.

### `pfnResetCommandPool`

Pointer to the function to reset a command pool.

### `pfnCalcPrivatePipelineStateSize`

Pointer to the function to calculate private pipeline state size.

### `pfnCreatePipelineState`

Pointer to the function to create pipeline state.

### `pfnDestroyPipelineState`

Pointer to the function to destroy pipeline state.

### `pfnCalcPrivateCommandListSize`

Pointer to the function to calculate the private command list size.

### `pfnCreateCommandList`

Pointer to the function to create a command list.

### `pfnDestroyCommandList`

Pointer to the function to destroy a command list.

### `pfnCalcPrivateFenceSize`

Pointer to the function to calculate private fence size.

### `pfnCreateFence`

Pointer to the function to create a fence.

### `pfnDestroyFence`

Pointer to the function to destroy a fence.

### `pfnCalcPrivateDescriptorHeapSize`

Pointer to the function to calculate private descriptor heap size.

### `pfnCreateDescriptorHeap`

Pointer to the function to create a descriptor heap.

### `pfnDestroyDescriptorHeap`

Pointer to the function to destroy a descriptor heap.

### `pfnGetDescriptorSizeInBytes`

Pointer to the function to get a descriptor's size in bytes.

### `pfnGetCPUDescriptorHandleForHeapStart`

Pointer to the function to get a CPU descriptor handle for heap start.

### `pfnGetGPUDescriptorHandleForHeapStart`

Pointer to the function to get a GPU descriptor handle for heap start.

### `pfnCreateShaderResourceView`

Pointer to the function to create a shader resource view.

### `pfnCreateConstantBufferView`

Pointer to the function to create a constant buffer view.

### `pfnCreateSampler`

Pointer to the function to create a sampler.

### `pfnCreateUnorderedAccessView`

Pointer to the function to create an unordered access view.

### `pfnCreateRenderTargetView`

Pointer to the function to create a render target view.

### `pfnCreateDepthStencilView`

Pointer to the function to create a depth stencil view.

### `pfnCalcPrivateRootSignatureSize`

Pointer to the function to calculate a private root signature size.

### `pfnCreateRootSignature`

Pointer to the function to create a root signature.

### `pfnDestroyRootSignature`

Pointer to the function to destroy a root signature.

### `pfnMapHeap`

Pointer to the function to map a heap.

### `pfnUnmapHeap`

Pointer to the function to unmap a heap.

### `pfnCalcPrivateHeapAndResourceSizes`

Pointer to the function to calculate private heap and resource sizes.

### `pfnCreateHeapAndResource`

Pointer to the function to create a heap and resource.

### `pfnDestroyHeapAndResource`

Pointer to the function to destroy a heap and resource.

### `pfnMakeResident`

Pointer to the function to make resident.

### `pfnEvict`

Pointer to the function to evict.

### `pfnCalcPrivateOpenedHeapAndResourceSizes`

Pointer to the function to calculate private opened heap and resource sizes.

### `pfnOpenHeapAndResource`

Pointer to the function to open heap and resource.

### `pfnCopyDescriptors`

Pointer to the function to copy descriptors.

### `pfnCopyDescriptorsSimple`

Pointer to the function to copy descriptors sample.

### `pfnCalcPrivateQueryHeapSize`

Pointer to the function to calculate private query heap size.

### `pfnCreateQueryHeap`

Pointer to the function to create query heap.

### `pfnDestroyQueryHeap`

Pointer to the function to destroy query heap.

### `pfnCalcPrivateCommandSignatureSize`

Pointer to the function to calculate private command signature size.

### `pfnCreateCommandSignature`

Pointer to the function to create command signature.

### `pfnDestroyCommandSignature`

Pointer to the function to destroy command signature.

### `pfnCheckResourceVirtualAddress`

Pointer to the function to check resource virtual address.

### `pfnCheckResourceAllocationInfo`

Pointer to the function to check resource allocation info.

### `pfnCheckSubresourceInfo`

Pointer to the function to check subresource info.

### `pfnCheckExistingResourceAllocationInfo`

Pointer to the function to check existing resource allocation info.

### `pfnOfferResources`

Offer resources.

### `pfnReclaimResources`

Pointer to the function to reclaim resources.

### `pfnGetImplicitPhysicalAdapterMask`

Pointer to the function to get implicit physical adapter mask.

### `pfnGetPresentPrivateDriverDataSize`

Pointer to the function to get present private driver data size.

### `pfnQueryNodeMap`

Pointer to the function to query a node map.

### `pfnRetrieveShaderComment`

Pointer to the function to retrieve a shader comment.

### `pfnCheckResourceAllocationHandle`

Pointer to the function to check a resource allocation handle.

### `pfnCalcPrivatePipelineLibrarySize`

Pointer to the function to calculate private pipeline library size.

### `pfnCreatePipelineLibrary`

Pointer to the function to create a pipeline library.

### `pfnDestroyPipelineLibrary`

Pointer to the function to destroy a pipeline library.

### `pfnAddPipelineStateToLibrary`

Pointer to the function to add pipeline state to library.

### `pfnCalcSerializedLibrarySize`

Pointer to the function to calculate serialized library size.

### `pfnSerializeLibrary`

Pointer to the function to serialize a library.

### `pfnGetDebugAllocationInfo`

Pointer to the function to get debug allocation info.

### `pfnCalcPrivateCommandRecorderSize`

Pointer to the function to calculate private command recorder size.

### `pfnCreateCommandRecorder`

Pointer to the function to create a command recorder.

### `pfnDestroyCommandRecorder`

Pointer to the function to destroy a command recorder.

### `pfnCommandRecorderSetCommandPoolAsTarget`

Pointer to the function to set the command pool as target for the command recorder.

### `pfnCalcPrivateSchedulingGroupSize`

Pointer to the function to calculate private scheduling group size.

### `pfnCreateSchedulingGroup`

Pointer to the function to create a scheduling group.

### `pfnDestroySchedulingGroup`

Pointer to the function to destroy a scheduling group.

### `pfnEnumerateMetaCommands`

Pointer to the function to enumerate meta-commands.

### `pfnEnumerateMetaCommandParameters`

Pointer to the function to enumerate meta-command parameters.

### `pfnCalcPrivateMetaCommandSize`

Pointer to the function to calculate private meta-command size.

### `pfnCreateMetaCommand`

Pointer to the function to create a meta-command.

### `pfnDestroyMetaCommand`

Pointer to the function to destroy a meta-command.

### `pfnGetMetaCommandRequiredParameterInfo`

Pointer to the function to get required meta-command parameter info.

### `pfnCalcPrivateStateObjectSize`

Pointer to the function to calculate private state object size.

### `pfnCreateStateObject`

Pointer to the function to create a state object.

### `pfnDestroyStateObject`

Pointer to the function to destroy a state object.

### `pfnGetRaytracingAccelerationStructurePrebuildInfo`

Pointer to the function to get ray tracing acceleration structure prebuild info.

### `pfnCheckDriverMatchingIdentifier`

Pointer to the function to check driver matching identifier.

### `pfnGetShaderIdentifier`

Pointer to the function to get a shader identifier.

### `pfnGetShaderStackSize`

Pointer to the function to get a shader stack size.

### `pfnGetPipelineStackSize`

Pointer to the function to get a pipeline stack size.

### `pfnSetPipelineStackSize`

Pointer to the function to set pipeline stack size.

### `pfnSetBackgroundProcessingMode`

Pointer to the function to set the background processing mode.

### `pfnCalcPrivateAddToStateObjectSize`

Pointer to the function to calculate private add to state object size. See the [DirectX Raytracing (DXR) Functional Spec](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

### `pfnAddToStateObject`

Pointer to the function to add to state object. See the [DirectX Raytracing (DXR) Functional Spec](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

### `pfnCreateSamplerFeedbackUnorderedAccessView`

Pointer to the function to create a sampler feedback unordered access view. See the [D3D Sampler Feedback Specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html) for more information.

### `pfnCreateAmplificationShader`

Pointer to the function to create an amplification shader. See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

### `pfnCreateMeshShader`

Pointer to the function to create a mesh shader. See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

### `pfnCalcPrivateMeshShaderSize`

Pointer to the function to calculate private mesh shader size. See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

### `pfnImplicitShaderCacheControl`

Pointer to the function for implicit shader cache control. See the [D3D12 Shader Cache APIs specification](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html) for more information.

## See also

[**D3D12DDI_TABLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type)

[**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable)