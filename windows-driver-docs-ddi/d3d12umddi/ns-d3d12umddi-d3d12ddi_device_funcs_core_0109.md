## Description

The **D3D12DDI_DEVICE_FUNCS_CORE_0109** structure contains the core device functionality available in D3D12 Release 8, Build rev 109. The user-mode driver (UMD) returns its function pointers in this structure when its [**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable) function is called with a [**D3D12DDI_TABLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type) of **D3D12DDI_TABLE_TYPE_DEVICE_CORE**.

## Members

### `pfnCheckFormatSupport`

Points to a function that checks the support of a particular format on the GPU.

### `pfnCheckMultisampleQualityLevels`

Points to a function that checks the available quality levels for multisample anti-aliasing with a given format and sample count.

### `pfnGetMipPacking`

Points to a function that retrieves information about how mips are packed in a resource.

### `pfnCalcPrivateElementLayoutSize`

Points to a function that calculates the size of the private element layout.

### `pfnCreateElementLayout`

Points to a function that creates an element layout.

### `pfnDestroyElementLayout`

Points to a function that destroys an element layout.

### `pfnCalcPrivateBlendStateSize`

Points to a function that calculates the size of the private blend state.

### `pfnCreateBlendState`

Points to a function that creates a blend state.

### `pfnDestroyBlendState`

Points to a function that destroys a blend state.

### `pfnCalcPrivateDepthStencilStateSize`

Points to a function that calculates the size of the private depth stencil state.

### `pfnCreateDepthStencilState`

Points to a function that creates a depth stencil state.

### `pfnDestroyDepthStencilState`

Points to a function that destroys a depth stencil state.

### `pfnCalcPrivateRasterizerStateSize`

Points to a function that calculates the size of the private rasterizer state.

### `pfnCreateRasterizerState`

Points to a function that creates a rasterizer state.

### `pfnDestroyRasterizerState`

Points to a function that destroys a rasterizer state.

### `pfnCalcPrivateShaderSize`

Points to a function that calculates the size of the private shader.

### `pfnCreateVertexShader`

Points to a function that creates a vertex shader.

### `pfnCreatePixelShader`

Points to a function that creates a pixel shader.

### `pfnCreateGeometryShader`

Points to a function that creates a geometry shader.

### `pfnCreateComputeShader`

Points to a function that creates a compute shader.

### `pfnCalcPrivateGeometryShaderWithStreamOutput`

Points to a function that calculates the size of a private geometry shader with stream output.

### `pfnCreateGeometryShaderWithStreamOutput`

Points to a function that creates a geometry shader with stream output.

### `pfnCalcPrivateTessellationShaderSize`

Points to a function that calculates the size of the private tessellation shader.

### `pfnCreateHullShader`

Points to a function that creates a hull shader.

### `pfnCreateDomainShader`

Points to a function that creates a domain shader.

### `pfnDestroyShader`

Points to a function that destroys a shader.

### `pfnCalcPrivateCommandQueueSize`

Points to a function that calculates the size of the private command queue.

### `pfnCreateCommandQueue`

Points to a function that creates a command queue.

### `pfnDestroyCommandQueue`

Points to a function that destroys a command queue.

### `pfnCalcPrivateCommandPoolSize`

Points to a function that calculates the size of the private command pool.

### `pfnCreateCommandPool`

Points to a function that creates a command pool.

### `pfnDestroyCommandPool`

Points to a function that destroys a command pool.

### `pfnResetCommandPool`

Points to a function that resets a command pool.

### `pfnCalcPrivatePipelineStateSize`

Points to a function that calculates the size of the private pipeline state.

### `pfnCreatePipelineState`

Points to a function that creates pipeline state.

### `pfnDestroyPipelineState`

Points to a function that destroys pipeline state.

### `pfnCalcPrivateCommandListSize`

Points to a function that calculates the private command list size.

### `pfnCreateCommandList`

Points to a function that creates a command list.

### `pfnDestroyCommandList`

Points to a function that destroys a command list.

### `pfnCalcPrivateFenceSize`

Points to a function that calculates a private fence size.

### `pfnCreateFence`

Points to a function that creates a fence.

### `pfnDestroyFence`

Points to a function that destroys a fence.

### `pfnCalcPrivateDescriptorHeapSize`

Points to a function that calculates private descriptor heap size.

### `pfnCreateDescriptorHeap`

Points to a function that creates a descriptor heap.

### `pfnDestroyDescriptorHeap`

Points to a function that destroys a descriptor heap.

### `pfnGetDescriptorSizeInBytes`

Points to a function that gets a descriptor's size in bytes.

### `pfnGetCPUDescriptorHandleForHeapStart`

Points to a function that gets a CPU descriptor handle for heap start.

### `pfnGetGPUDescriptorHandleForHeapStart`

Points to a function that gets a GPU descriptor handle for heap start.

### `pfnCreateShaderResourceView`

Points to a function that creates a shader resource view.

### `pfnCreateConstantBufferView`

Points to a function that creates a constant buffer view.

### `pfnCreateSampler`

Points to a function that creates a sampler.

### `pfnCreateUnorderedAccessView`

Points to a function that creates an unordered access view.

### `pfnCreateRenderTargetView`

Points to a function that creates a render target view.

### `pfnCreateDepthStencilView`

Points to a function that creates a depth stencil view.

### `pfnCalcPrivateRootSignatureSize`

Points to a function that calculates a private root signature size.

### `pfnCreateRootSignature`

Points to a function that creates a root signature.

### `pfnDestroyRootSignature`

Points to a function that destroys a root signature.

### `pfnMapHeap`

Points to a function that maps a heap into the application's address space.

### `pfnUnmapHeap`

Points to a function that unmaps a previously mapped heap from the application's address space.

### `pfnCalcPrivateHeapAndResourceSizes`

Points to a function that calculates the size of the private heap and resource.

### `pfnCreateHeapAndResource`

Points to a function that creates a heap and associated resource.

### `pfnDestroyHeapAndResource`

Points to a function that destroys a heap and its associated resource.

### `pfnMakeResident`

Points to a function that makes a set of resources resident in physical memory.

### `pfnEvict`

Points to a function that evicts a set of resources from physical memory.

### `pfnCalcPrivateOpenedHeapAndResourceSizes`

Points to a function that calculates the size of the private heap and resource for opened resources.

### `pfnOpenHeapAndResource`

Points to a function that opens a heap and resource created by another process.

### `pfnCopyDescriptors`

Points to a function that copies an array of descriptors to the destination descriptor heap.

### `pfnCopyDescriptorsSimple`

Points to a function that copies descriptors to the destination descriptor heap using a simple method.

### `pfnCalcPrivateQueryHeapSize`

Points to a function that calculates the size of the private query heap.

### `pfnCreateQueryHeap`

Points to a function that creates a query heap.

### `pfnDestroyQueryHeap`

Points to a function that destroys a query heap.

### `pfnCalcPrivateCommandSignatureSize`

Points to a function that calculates the size of the private command signature.

### `pfnCreateCommandSignature`

Points to a function that creates a command signature.

### `pfnDestroyCommandSignature`

Points to a function that destroys a command signature.

### `pfnCheckResourceVirtualAddress`

Points to a function that checks if a resource's virtual address is valid.

### `pfnCheckResourceAllocationInfo`

Points to a function that checks the allocation information for a given resource.

### `pfnCheckSubresourceInfo`

Points to a function that checks the information of a subresource within a resource.

### `pfnCheckExistingResourceAllocationInfo`

Points to a function that checks the allocation information for an existing resource.

### `pfnOfferResources`

Points to a function that offers resources to the operating system, allowing them to be paged out.

### `pfnReclaimResources`

Points to a function that reclaims resources that were previously offered to the operating system.

### `pfnGetImplicitPhysicalAdapterMask`

Points to a function that gets the mask of physical adapters that can be used implicitly by a device.

### `pfnGetPresentPrivateDriverDataSize`

Points to a function that gets the size of private driver data for present operations.

### `pfnQueryNodeMap`

Points to a function that queries the mapping of nodes within a multi-adapter configuration.

### `pfnRetrieveShaderComment`

Points to a function that retrieves the comment string embedded in a shader.

### `pfnCheckResourceAllocationHandle`

Points to a function that checks the allocation handle for a resource.

### `pfnCalcPrivatePipelineLibrarySize`

Points to a function that calculates the size of the private pipeline library.

### `pfnCreatePipelineLibrary`

Points to a function that creates a pipeline library.

### `pfnDestroyPipelineLibrary`

Points to a function that destroys a pipeline library.

### `pfnAddPipelineStateToLibrary`

Points to a function that adds a pipeline state object to a pipeline library.

### `pfnCalcSerializedLibrarySize`

Points to a function that calculates the size of a serialized pipeline library.

### `pfnSerializeLibrary`

Points to a function that serializes a library.

### `pfnGetDebugAllocationInfo`

Points to a function that gets debug allocation info.

### `pfnCalcPrivateCommandRecorderSize`

Points to a function that calculates private command recorder size.

### `pfnCreateCommandRecorder`

Points to a function that creates a command recorder.

### `pfnDestroyCommandRecorder`

Points to a function that destroys a command recorder.

### `pfnCommandRecorderSetCommandPoolAsTarget`

Points to a function that sets the command pool as target for the command recorder.

### `pfnCalcPrivateSchedulingGroupSize`

Points to a function that calculates private scheduling group size.

### `pfnCreateSchedulingGroup`

Points to a function that creates a scheduling group.

### `pfnDestroySchedulingGroup`

Points to a function that destroys a scheduling group.

### `pfnEnumerateMetaCommands`

Points to a function that enumerates meta-commands.

### `pfnEnumerateMetaCommandParameters`

Points to a function that enumerates meta-command parameters.

### `pfnCalcPrivateMetaCommandSize`

Points to a function that calculates private meta-command size.

### `pfnCreateMetaCommand`

Points to a function that creates a meta-command.

### `pfnDestroyMetaCommand`

Points to a function that destroys a meta-command.

### `pfnGetMetaCommandRequiredParameterInfo`

Points to a function that gets required meta-command parameter info.

### `pfnCalcPrivateStateObjectSize`

Points to a function that calculates private state object size.

### `pfnCreateStateObject`

Points to a function that creates a state object.

### `pfnDestroyStateObject`

Points to a function that destroys a state object.

### `pfnGetRaytracingAccelerationStructurePrebuildInfo`

Points to a function that gets ray tracing acceleration structure prebuild info.

### `pfnCheckDriverMatchingIdentifier`

Points to a function that checks driver matching identifier.

### `pfnGetShaderIdentifier`

Points to a function that gets a shader identifier.

### `pfnGetShaderStackSize`

Points to a function that gets a shader stack size.

### `pfnGetPipelineStackSize`

Points to a function that gets a pipeline stack size.

### `pfnSetPipelineStackSize`

Points to a function that sets pipeline stack size.

### `pfnSetBackgroundProcessingMode`

Points to a function that sets the background processing mode.

### `pfnCalcPrivateAddToStateObjectSize`

Points to a function that calculates private add to state object size. See the [DirectX Raytracing (DXR) Functional Spec](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

### `pfnAddToStateObject`

Points to a function that adds to state object. See the [DirectX Raytracing (DXR) Functional Spec](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

### `pfnCreateSamplerFeedbackUnorderedAccessView`

Points to a function that creates a sampler feedback unordered access view. See the [D3D Sampler Feedback Specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html) for more information.

### `pfnCreateAmplificationShader`

Points to a function that creates an amplification shader. See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

### `pfnCreateMeshShader`

Points to a function that creates a mesh shader. See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

### `pfnCalcPrivateMeshShaderSize`

Points to a function that calculates private mesh shader size. See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

### `pfnImplicitShaderCacheControl`

Pointer to a function for implicit shader cache control. See the [D3D12 Shader Cache APIs specification](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html) for more information.

### `pfnGetProgramIdentifier`

Points to a [**PFND3D12DDI_GET_PROGRAM_IDENTIFIER_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_program_identifier_0108) function that identifies a program for the purpose of setting it on a command list. See the [D3D12 Work Graphs specification](https://github.com/microsoft/DirectX-Specs/blob/master/d3d/WorkGraphs.md) for more information.

### `pfnGetWorkGraphMemoryRequirements`

Points to a [**PFND3D12DDI_GET_WORK_GRAPH_MEMORY_REQUIREMENTS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_work_graph_memory_requirements_0108) function that gets the work graph memory requirements. See the [D3D12 Work Graphs specification](https://github.com/microsoft/DirectX-Specs/blob/master/d3d/WorkGraphs.md) for more information.

## See also

[**D3D12DDI_TABLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type)

[**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable)