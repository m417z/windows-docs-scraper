# D3D10DDI_DEVICEFUNCS structure

## Description

The D3D10DDI_DEVICEFUNCS structure contains functions that the user-mode display driver can implement to render graphics primitives and process state changes.

## Members

### `pfnDefaultConstantBufferUpdateSubresourceUP`

A pointer to the driver's [DefaultConstantBufferUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup) function.

### `pfnVsSetConstantBuffers`

A pointer to the driver's [VsSetConstantBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnPsSetShaderResources`

A pointer to the driver's [PsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnPsSetShader`

A pointer to the driver's [PsSetShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnPsSetSamplers`

A pointer to the driver's [PsSetSamplers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnVsSetShader`

A pointer to the driver's [VsSetShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnDrawIndexed`

A pointer to the driver's [DrawIndexed](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawindexed) function.

### `pfnDraw`

A pointer to the driver's [Draw](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_draw) function.

### `pfnDynamicIABufferMapNoOverwrite`

A pointer to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function. For more information about whether to implement a separate **DynamicIABufferMapNoOverwrite** function or to point to the multipurpose **ResourceMap**, see the Remarks section of **ResourceMap**.

### `pfnDynamicIABufferUnmap`

A pointer to the driver's [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function. For more information about whether to implement a separate **DynamicIABufferUnmap** function or to point to the multipurpose **ResourceUnmap**, see the Remarks section of [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap).

### `pfnDynamicConstantBufferMapDiscard`

A pointer to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function. For more information about whether to implement a separate **DynamicConstantBufferMapDiscard** function or to point to the multipurpose **ResourceMap**, see the Remarks section of **ResourceMap**.

### `pfnDynamicIABufferMapDiscard`

A pointer to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function. For more information about whether to implement a separate **DynamicIABufferMapDiscard** function or to point to the multipurpose **ResourceMap**, see the Remarks section of **ResourceMap**.

### `pfnDynamicConstantBufferUnmap`

A pointer to the driver's [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function. For more information about whether to implement a separate **DynamicConstantBufferUnmap** function or to point to the multipurpose **ResourceUnmap**, see the Remarks section of [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap).

### `pfnPsSetConstantBuffers`

A pointer to the driver's [PsSetConstantBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnIaSetInputLayout`

A pointer to the driver's [IaSetInputLayout](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setinputlayout) function.

### `pfnIaSetVertexBuffers`

A pointer to the driver's [IaSetVertexBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_setvertexbuffers) function.

### `pfnIaSetIndexBuffer`

A pointer to the driver's [IaSetIndexBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_setindexbuffer) function.

### `pfnDrawIndexedInstanced`

A pointer to the driver's [DrawIndexedInstanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawindexedinstanced) function.

### `pfnDrawInstanced`

A pointer to the driver's [DrawInstanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawinstanced) function.

### `pfnDynamicResourceMapDiscard`

A pointer to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function. For more information about whether to implement a separate **DynamicResourceMapDiscard** function or to point to the multipurpose **ResourceMap**, see the Remarks section of **ResourceMap**.

### `pfnDynamicResourceUnmap`

A pointer to the driver's [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function. For more information about whether to implement a separate **DynamicResourceUnmap** function or to point to the multipurpose **ResourceUnmap**, see the Remarks section of **ResourceUnmap**.

### `pfnGsSetConstantBuffers`

A pointer to the driver's [GsSetConstantBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnGsSetShader`

A pointer to the driver's [GsSetShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnIaSetTopology`

A pointer to the driver's [IaSetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_settopology) function.

### `pfnStagingResourceMap`

A pointer to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function. For more information about whether to implement a separate **StagingResourceMap** function or to point to the multipurpose **ResourceMap**, see the Remarks section of **ResourceMap**.

### `pfnStagingResourceUnmap`

A pointer to the driver's [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function. For more information about whether to implement a separate **StagingResourceUnmap** function or to point to the multipurpose **ResourceUnmap**, see the Remarks section of [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap).

### `pfnVsSetShaderResources`

A pointer to the driver's [VsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnVsSetSamplers`

A pointer to the driver's [VsSetSamplers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnGsSetShaderResources`

A pointer to the driver's [GsSetShaderResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnGsSetSamplers`

A pointer to the driver's [GsSetSamplers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnSetRenderTargets`

A pointer to the driver's [SetRenderTargets](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setrendertargets) function.

### `pfnShaderResourceViewReadAfterWriteHazard`

A pointer to the driver's [ShaderResourceViewReadAfterWriteHazard](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_shaderresourceviewreadafterwritehazard) function.

### `pfnResourceReadAfterWriteHazard`

A pointer to the driver's [ResourceReadAfterWriteHazard](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcereadafterwritehazard) function.

### `pfnSetBlendState`

A pointer to the driver's [SetBlendState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setblendstate) function.

### `pfnSetDepthStencilState`

A pointer to the driver's [SetDepthStencilState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setdepthstencilstate) function.

### `pfnSetRasterizerState`

A pointer to the driver's [SetRasterizerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setrasterizerstate) function.

### `pfnQueryEnd`

A pointer to the driver's [QueryEnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_queryend) function.

### `pfnQueryBegin`

A pointer to the driver's [QueryBegin](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querybegin) function.

### `pfnResourceCopyRegion`

A pointer to the driver's [ResourceCopyRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopyregion) function.

### `pfnResourceUpdateSubresourceUP`

A pointer to the driver's [ResourceUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup) function.

### `pfnSoSetTargets`

A pointer to the driver's [SoSetTargets](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_so_settargets) function.

### `pfnDrawAuto`

A pointer to the driver's [DrawAuto](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawauto) function.

### `pfnSetViewports`

A pointer to the driver's [SetViewports](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setviewports) function.

### `pfnSetScissorRects`

A pointer to the driver's [SetScissorRects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setscissorrects) function.

### `pfnClearRenderTargetView`

A pointer to the driver's [ClearRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_clearrendertargetview) function.

### `pfnClearDepthStencilView`

A pointer to the driver's [ClearDepthStencilView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_cleardepthstencilview) function.

### `pfnSetPredication`

A pointer to the driver's [SetPredication](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setpredication) function.

### `pfnQueryGetData`

A pointer to the driver's [QueryGetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata) function.

### `pfnFlush`

A pointer to the driver's [Flush(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_flush) function.

### `pfnGenMips`

A pointer to the driver's [GenMips](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_genmips) function.

### `pfnResourceCopy`

A pointer to the driver's [ResourceCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopy) function.

### `pfnResourceResolveSubresource`

A pointer to the driver's [ResourceResolveSubresource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceresolvesubresource) function.

### `pfnResourceMap`

A pointer to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function.

### `pfnResourceUnmap`

A pointer to the driver's [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function.

### `pfnResourceIsStagingBusy`

A pointer to the driver's [ResourceIsStagingBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceisstagingbusy) function.

### `pfnRelocateDeviceFuncs`

A pointer to the driver's [RelocateDeviceFuncs](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_relocatedevicefuncs) function.

### `pfnCalcPrivateResourceSize`

A pointer to the driver's [CalcPrivateResourceSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateresourcesize) function.

### `pfnCalcPrivateOpenedResourceSize`

A pointer to the driver's [CalcPrivateOpenedResourceSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateopenedresourcesize) function.

### `pfnCreateResource`

A pointer to the driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function.

### `pfnOpenResource`

A pointer to the driver's [OpenResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openresource) function.

### `pfnDestroyResource`

A pointer to the driver's [DestroyResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyresource) function.

### `pfnCalcPrivateShaderResourceViewSize`

A pointer to the driver's [CalcPrivateShaderResourceViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshaderresourceviewsize) function.

### `pfnCreateShaderResourceView`

A pointer to the driver's [CreateShaderResourceView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createshaderresourceview) function.

### `pfnDestroyShaderResourceView`

A pointer to the driver's [DestroyShaderResourceView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshaderresourceview) function.

### `pfnCalcPrivateRenderTargetViewSize`

A pointer to the driver's [CalcPrivateRenderTargetViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivaterendertargetviewsize) function.

### `pfnCreateRenderTargetView`

A pointer to the driver's [CreateRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrendertargetview) function.

### `pfnDestroyRenderTargetView`

A pointer to the driver's [DestroyRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyrendertargetview) function.

### `pfnCalcPrivateDepthStencilViewSize`

A pointer to the driver's [CalcPrivateDepthStencilViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedepthstencilviewsize) function.

### `pfnCreateDepthStencilView`

A pointer to the driver's [CreateDepthStencilView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilview) function.

### `pfnDestroyDepthStencilView`

A pointer to the driver's [DestroyDepthStencilView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydepthstencilview) function.

### `pfnCalcPrivateElementLayoutSize`

A pointer to the driver's [CalcPrivateElementLayoutSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateelementlayoutsize) function.

### `pfnCreateElementLayout`

A pointer to the driver's [CreateElementLayout](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createelementlayout) function.

### `pfnDestroyElementLayout`

A pointer to the driver's [DestroyElementLayout](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyelementlayout) function.

### `pfnCalcPrivateBlendStateSize`

A pointer to the driver's [CalcPrivateBlendStateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateblendstatesize) function.

### `pfnCreateBlendState`

A pointer to the driver's [CreateBlendState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createblendstate) function.

### `pfnDestroyBlendState`

A pointer to the driver's [DestroyBlendState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyblendstate) function.

### `pfnCalcPrivateDepthStencilStateSize`

A pointer to the driver's [CalcPrivateDepthStencilStateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedepthstencilstatesize) function.

### `pfnCreateDepthStencilState`

A pointer to the driver's [CreateDepthStencilState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilstate) function.

### `pfnDestroyDepthStencilState`

A pointer to the driver's [DestroyDepthStencilState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydepthstencilstate) function.

### `pfnCalcPrivateRasterizerStateSize`

A pointer to the driver's [CalcPrivateRasterizerStateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivaterasterizerstatesize) function.

### `pfnCreateRasterizerState`

A pointer to the driver's [CreateRasterizerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrasterizerstate) function.

### `pfnDestroyRasterizerState`

A pointer to the driver's [DestroyRasterizerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyrasterizerstate) function.

### `pfnCalcPrivateShaderSize`

A pointer to the driver's [CalcPrivateShaderSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshadersize) function.

### `pfnCreateVertexShader`

A pointer to the driver's [CreateVertexShader(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createvertexshader) function.

### `pfnCreateGeometryShader`

A pointer to the driver's [CreateGeometryShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_creategeometryshader) function.

### `pfnCreatePixelShader`

A pointer to the driver's [CreatePixelShader(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createpixelshader) function.

### `pfnCalcPrivateGeometryShaderWithStreamOutput`

A pointer to the driver's [CalcPrivateGeometryShaderWithStreamOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivategeometryshaderwithstreamoutput) function.

### `pfnCreateGeometryShaderWithStreamOutput`

A pointer to the driver's [CreateGeometryShaderWithStreamOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_creategeometryshaderwithstreamoutput) function.

### `pfnDestroyShader`

A pointer to the driver's [DestroyShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshader) function.

### `pfnCalcPrivateSamplerSize`

A pointer to the driver's [CalcPrivateSamplerSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatesamplersize) function.

### `pfnCreateSampler`

A pointer to the driver's [CreateSampler](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createsampler) function.

### `pfnDestroySampler`

A pointer to the driver's [DestroySampler](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroysampler) function.

### `pfnCalcPrivateQuerySize`

A pointer to the driver's [CalcPrivateQuerySize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatequerysize) function.

### `pfnCreateQuery`

A pointer to the driver's [CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery) function.

### `pfnDestroyQuery`

A pointer to the driver's [DestroyQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyquery) function.

### `pfnCheckFormatSupport`

A pointer to the driver's [CheckFormatSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkformatsupport) function.

### `pfnCheckMultisampleQualityLevels`

A pointer to the driver's [CheckMultisampleQualityLevels](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkmultisamplequalitylevels) function.

### `pfnCheckCounterInfo`

A pointer to the driver's [CheckCounterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounterinfo) function.

### `pfnCheckCounter`

A pointer to the driver's [CheckCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounter) function.

### `pfnDestroyDevice`

A pointer to the driver's [DestroyDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydevice) function.

### `pfnSetTextFilterSize`

A pointer to the driver's [SetTextFilterSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_settextfiltersize) function.

### `pfnResetPrimitiveID`

### `pfnSetVertexPipelineOutput`

## Remarks

The order of user-mode display driver functions (that is, the order of the members of the D3D10DDI_DEVICEFUNCS structure) is in decreasing order of priority (in regard to performance).

The user-mode display driver can use different names for these functions because the address of the function table (this structure) is shared between the Direct3D 10 runtime and the driver through the call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

The **pfnResetPrimitiveID** and **pfnSetVertexPipelineOutput** members (not shown here) and their data types are reserved for system use and should not be used in your driver.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)