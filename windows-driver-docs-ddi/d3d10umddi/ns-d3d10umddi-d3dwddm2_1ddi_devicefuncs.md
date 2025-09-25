## Description

This structure contains the user mode device function table for Windows Display Driver Model (WDDM) 2.1. In general, unless a function is commented as optional in *d3d10umdd.h* (or optional under certain conditions), a driver must implement it.

## Members

### `pfnDefaultConstantBufferUpdateSubresourceUP`

A pointer to the [**DefaultConstantBufferUpdateSubresourceUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup) function.

### `pfnVsSetConstantBuffers`

A pointer to the [**VsSetConstantBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnPsSetShaderResources`

A pointer to the [**PsSetShaderResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnPsSetShader`

A pointer to the [**PsSetShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnPsSetSamplers`

A pointer to the [**PsSetSamplers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnVsSetShader`

A pointer to the [**VsSetShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnDrawIndexed`

A pointer to the [**DrawIndexed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawindexed) function.

### `pfnDraw`

A pointer to the [**Draw**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_draw) function.

### `pfnDynamicIABufferMapNoOverwrite`

### `pfnDynamicIABufferUnmap`

### `pfnDynamicConstantBufferMapDiscard`

### `pfnDynamicIABufferMapDiscard`

### `pfnDynamicConstantBufferUnmap`

### `pfnPsSetConstantBuffers`

A pointer to the [**PsSetConstantBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnIaSetInputLayout`

A pointer to the [**IaSetInputLayout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setinputlayout) function.

### `pfnIaSetVertexBuffers`

A pointer to the [**IaSetVertexBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_setvertexbuffers) function.

### `pfnIaSetIndexBuffer`

A pointer to the [**IaSetIndexBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_setindexbuffer) function.

### `pfnDrawIndexedInstanced`

A pointer to the [**DrawIndexedInstanced**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawindexedinstanced) function.

### `pfnDrawInstanced`

A pointer to the [**DrawInstanced**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawinstanced) function.

### `pfnDynamicResourceMapDiscard`

### `pfnDynamicResourceUnmap`

### `pfnGsSetConstantBuffers`

A pointer to the [**GsSetConstantBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnGsSetShader`

A pointer to the [**GsSetShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnIaSetTopology`

A pointer to the [**IaSetTopology**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_ia_settopology) function.

### `pfnStagingResourceMap`

### `pfnStagingResourceUnmap`

### `pfnVsSetShaderResources`

A pointer to the [**VsSetShaderResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnVsSetSamplers`

A pointer to the [**VsSetSamplers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnGsSetShaderResources`

A pointer to the [**GsSetShaderResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnGsSetSamplers`

A pointer to the [**GsSetSamplers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnSetRenderTargets`

A pointer to the [**SetRenderTargets**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setrendertargets) function.

### `pfnShaderResourceViewReadAfterWriteHazard`

A pointer to the [**ShaderResourceViewReadAfterWriteHazard**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_shaderresourceviewreadafterwritehazard) function.

### `pfnResourceReadAfterWriteHazard`

A pointer to the [**ResourceReadAfterWriteHazard**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcereadafterwritehazard) function.

### `pfnSetBlendState`

A pointer to the [**SetBlendState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setblendstate) function.

### `pfnSetDepthStencilState`

A pointer to the [**SetDepthStencilState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setdepthstencilstate) function.

### `pfnSetRasterizerState`

A pointer to the [**SetRasterizerState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setrasterizerstate) function.

### `pfnQueryEnd`

A pointer to the [**QueryEnd**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_queryend) function.

### `pfnQueryBegin`

A pointer to the [**QueryBegin**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querybegin) function.

### `pfnResourceCopyRegion`

A pointer to the [**ResourceCopyRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopyregion) function.

### `pfnResourceUpdateSubresourceUP`

A pointer to the [**ResourceUpdateSubresourceUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup) function.

### `pfnSoSetTargets`

A pointer to the [**SoSetTargets**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_so_settargets) function.

### `pfnDrawAuto`

A pointer to the [**DrawAuto**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_drawauto) function.

### `pfnSetViewports`

A pointer to the [**SetViewports**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setviewports) function.

### `pfnSetScissorRects`

A pointer to the [**SetScissorRects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setscissorrects) function.

### `pfnClearRenderTargetView`

A pointer to the [**ClearRenderTargetView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_clearrendertargetview) function.

### `pfnClearDepthStencilView`

A pointer to the [**ClearDepthStencilView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_cleardepthstencilview) function.

### `pfnSetPredication`

A pointer to the [**SetPredication**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setpredication) function.

### `pfnQueryGetData`

A pointer to the [**QueryGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata) function.

### `pfnFlush`

A pointer to the [**Flush**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush) function.

### `pfnGenMips`

A pointer to the [**GenMips**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_genmips) function.

### `pfnResourceCopy`

A pointer to the [**ResourceCopy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopy) function.

### `pfnResourceResolveSubresource`

A pointer to the [**ResourceResolveSubresource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceresolvesubresource) function.

### `pfnResourceMap`

A pointer to the [**ResourceMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function.

### `pfnResourceUnmap`

A pointer to the [**ResourceUnmap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function.

### `pfnResourceIsStagingBusy`

A pointer to the [**ResourceIsStagingBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceisstagingbusy) function.

### `pfnRelocateDeviceFuncs`

A pointer to the [**RelocateDeviceFuncs**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_relocatedevicefuncs) function.

### `pfnCalcPrivateResourceSize`

A pointer to the [**CalcPrivateResourceSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateresourcesize) function.

### `pfnCalcPrivateOpenedResourceSize`

A pointer to the [**CalcPrivateOpenedResourceSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateopenedresourcesize) function.

### `pfnCreateResource`

A pointer to the [**CreateResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function.

### `pfnOpenResource`

A pointer to the [**OpenResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openresource) function.

### `pfnDestroyResource`

A pointer to the [**DestroyResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyresource) function.

### `pfnCalcPrivateShaderResourceViewSize`

A pointer to the [**CalcPrivateShaderResourceViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshaderresourceviewsize) function.

### `pfnCreateShaderResourceView`

A pointer to the [**CreateShaderResourceView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createshaderresourceview) function.

### `pfnDestroyShaderResourceView`

A pointer to the [**DestroyShaderResourceView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshaderresourceview) function.

### `pfnCalcPrivateRenderTargetViewSize`

A pointer to the [**CalcPrivateRenderTargetViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivaterendertargetviewsize) function.

### `pfnCreateRenderTargetView`

A pointer to the [**CreateRenderTargetView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrendertargetview) function.

### `pfnDestroyRenderTargetView`

A pointer to the [**DestroyRenderTargetView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyrendertargetview) function.

### `pfnCalcPrivateDepthStencilViewSize`

A pointer to the [**CalcPrivateDepthStencilViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedepthstencilviewsize) function.

### `pfnCreateDepthStencilView`

A pointer to the [**CreateDepthStencilView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilview) function.

### `pfnDestroyDepthStencilView`

A pointer to the [**DestroyDepthStencilView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydepthstencilview) function.

### `pfnCalcPrivateElementLayoutSize`

A pointer to the [**CalcPrivateElementLayoutSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateelementlayoutsize) function.

### `pfnCreateElementLayout`

A pointer to the [**CreateElementLayout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createelementlayout) function.

### `pfnDestroyElementLayout`

A pointer to the [**DestroyElementLayout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyelementlayout) function.

### `pfnCalcPrivateBlendStateSize`

A pointer to the [**CalcPrivateBlendStateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateblendstatesize) function.

### `pfnCreateBlendState`

A pointer to the [**CreateBlendState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createblendstate) function.

### `pfnDestroyBlendState`

A pointer to the [**DestroyBlendState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyblendstate) function.

### `pfnCalcPrivateDepthStencilStateSize`

A pointer to the [**CalcPrivateDepthStencilStateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedepthstencilstatesize) function.

### `pfnCreateDepthStencilState`

A pointer to the [**CreateDepthStencilState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilstate) function.

### `pfnDestroyDepthStencilState`

A pointer to the [**DestroyDepthStencilState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydepthstencilstate) function.

### `pfnCalcPrivateRasterizerStateSize`

A pointer to the [**CalcPrivateRasterizerStateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivaterasterizerstatesize) function.

### `pfnCreateRasterizerState`

A pointer to the [**CreateRasterizerState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrasterizerstate) function.

### `pfnDestroyRasterizerState`

A pointer to the [**DestroyRasterizerState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyrasterizerstate) function.

### `pfnCalcPrivateShaderSize`

A pointer to the [**CalcPrivateShaderSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshadersize) function.

### `pfnCreateVertexShader`

A pointer to the [**CreateVertexShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvertexshader) function.

### `pfnCreateGeometryShader`

A pointer to the [**CreateGeometryShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_creategeometryshader) function.

### `pfnCreatePixelShader`

A pointer to the [**CreatePixelShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpixelshader) function.

### `pfnCalcPrivateGeometryShaderWithStreamOutput`

A pointer to the [**CalcPrivateGeometryShaderWithStreamOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivategeometryshaderwithstreamoutput) function.

### `pfnCreateGeometryShaderWithStreamOutput`

A pointer to the [**CreateGeometryShaderWithStreamOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_creategeometryshaderwithstreamoutput) function.

### `pfnDestroyShader`

A pointer to the [**DestroyShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshader) function.

### `pfnCalcPrivateSamplerSize`

A pointer to the [**CalcPrivateSamplerSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatesamplersize) function.

### `pfnCreateSampler`

A pointer to the [**CreateSampler**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createsampler) function.

### `pfnDestroySampler`

A pointer to the [**DestroySampler**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroysampler) function.

### `pfnCalcPrivateQuerySize`

A pointer to the [**CalcPrivateQuerySize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatequerysize) function.

### `pfnCreateQuery`

A pointer to the [**CreateQuery**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function.

### `pfnDestroyQuery`

A pointer to the [**DestroyQuery**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyquery) function.

### `pfnCheckFormatSupport`

A pointer to the [**CheckFormatSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkformatsupport) function.

### `pfnCheckMultisampleQualityLevels`

A pointer to the [**CheckMultisampleQualityLevels**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkmultisamplequalitylevels) function.

### `pfnCheckCounterInfo`

A pointer to the [**CheckCounterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounterinfo) function.

### `pfnCheckCounter`

A pointer to the [**CheckCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounter) function.

### `pfnDestroyDevice`

A pointer to the [**DestroyDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydevice) function.

### `pfnSetTextFilterSize`

A pointer to the [**SetTextFilterSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_settextfiltersize) function.

### `pfnResourceConvert`

### `pfnResourceConvertRegion`

### `pfnResetPrimitiveID`

### `pfnSetVertexPipelineOutput`

### `pfnDrawIndexedInstancedIndirect`

A pointer to the [**DrawIndexedInstancedIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_drawindexedinstancedindirect) function.

### `pfnDrawInstancedIndirect`

A pointer to the [**DrawInstancedIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_drawinstancedindirect) function.

### `pfnCommandListExecute`

A pointer to the [**CommandListExecute**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_commandlistexecute) function.

### `pfnHsSetShaderResources`

A pointer to the [**HsSetShaderResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnHsSetShader`

A pointer to the [**HsSetShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnHsSetSamplers`

A pointer to the [**HsSetSamplers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnHsSetConstantBuffers`

A pointer to the [**HsSetConstantBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnDsSetShaderResources`

A pointer to the [**DsSetShaderResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnDsSetShader`

A pointer to the [**DsSetShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnDsSetSamplers`

A pointer to the [**DsSetSamplers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnDsSetConstantBuffers`

A pointer to the [**DsSetConstantBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnCreateHullShader`

A pointer to the [**CreateHullShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createhullshader) function.

### `pfnCreateDomainShader`

A pointer to the [**CreateDomainShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createdomainshader) function.

### `pfnCheckDeferredContextHandleSizes`

A pointer to the [**CheckDeferredContextHandleSizes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_checkdeferredcontexthandlesizes) function.

### `pfnCalcDeferredContextHandleSize`

A pointer to the [**CalcDeferredContextHandleSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcdeferredcontexthandlesize) function.

### `pfnCalcPrivateDeferredContextSize`

A pointer to the [**CalcPrivateDeferredContextSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivatedeferredcontextsize) function.

### `pfnCreateDeferredContext`

A pointer to the [**CreateDeferredContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createdeferredcontext) function.

### `pfnAbandonCommandList`

A pointer to the [**AbandonCommandList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_abandoncommandlist) function.

### `pfnCalcPrivateCommandListSize`

A pointer to the [**CalcPrivateCommandListSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivatecommandlistsize) function.

### `pfnCreateCommandList`

A pointer to the [**CreateCommandList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createcommandlist) function.

### `pfnDestroyCommandList`

A pointer to the [**DestroyCommandList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_destroycommandlist) function.

### `pfnCalcPrivateTessellationShaderSize`

A pointer to the [**CalcPrivateTessellationShaderSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivatetessellationshadersize) function.

### `pfnPsSetShaderWithIfaces`

A pointer to the [**PsSetShaderWithIfaces**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces) function.

### `pfnVsSetShaderWithIfaces`

A pointer to the [**VsSetShaderWithIfaces**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces) function.

### `pfnGsSetShaderWithIfaces`

A pointer to the [**GsSetShaderWithIfaces**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces) function.

### `pfnHsSetShaderWithIfaces`

A pointer to the [**HsSetShaderWithIfaces**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces) function.

### `pfnDsSetShaderWithIfaces`

A pointer to the [**DsSetShaderWithIfaces**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces) function.

### `pfnCsSetShaderWithIfaces`

A pointer to the [**CsSetShaderWithIfaces**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setshader_with_ifaces) function.

### `pfnCreateComputeShader`

A pointer to the [**CreateComputeShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createcomputeshader) function.

### `pfnCsSetShader`

A pointer to the [**CsSetShader**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshader) function.

### `pfnCsSetShaderResources`

A pointer to the [**CsSetShaderResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setshaderresources) function.

### `pfnCsSetSamplers`

A pointer to the [**CsSetSamplers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setsamplers) function.

### `pfnCsSetConstantBuffers`

A pointer to the [**CsSetConstantBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

### `pfnCalcPrivateUnorderedAccessViewSize`

A pointer to the [**CalcPrivateUnorderedAccessViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivateunorderedaccessviewsize) function.

### `pfnCreateUnorderedAccessView`

A pointer to the [**CreateUnorderedAccessView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview) function.

### `pfnDestroyUnorderedAccessView`

A pointer to the [**DestroyUnorderedAccessView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_destroyunorderedaccessview) function.

### `pfnClearUnorderedAccessViewUint`

A pointer to the [**ClearUnorderedAccessViewUint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_clearunorderedaccessviewuint) function.

### `pfnClearUnorderedAccessViewFloat`

A pointer to the [**ClearUnorderedAccessViewFloat**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_clearunorderedaccessviewfloat) function.

### `pfnCsSetUnorderedAccessViews`

A pointer to the [**CsSetUnorderedAccessViews**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setunorderedaccessviews) function.

### `pfnDispatch`

A pointer to the [**Dispatch**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_dispatch) function.

### `pfnDispatchIndirect`

A pointer to the [**DispatchIndirect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_dispatchindirect) function.

### `pfnSetResourceMinLOD`

A pointer to the [**SetResourceMinLOD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_setresourceminlod) function.

### `pfnCopyStructureCount`

A pointer to the [**CopyStructureCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_copystructurecount) function.

### `pfnRecycleCommandList`

A pointer to the [**RecycleCommandList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_recyclecommandlist) function.

### `pfnRecycleCreateCommandList`

A pointer to the [**RecycleCreateCommandList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_recyclecreatecommandlist) function.

### `pfnRecycleCreateDeferredContext`

A pointer to the [**RecycleCreateDeferredContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_recyclecreatedeferredcontext) function.

### `pfnRecycleDestroyCommandList`

### `pfnDiscard`

A pointer to the [**Discard**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_discard) function.

### `pfnAssignDebugBinary`

A pointer to the [**AssignDebugBinary**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_assigndebugbinary) function.

### `pfnDynamicConstantBufferMapNoOverwrite`

### `pfnCheckDirectFlipSupport`

A pointer to the [**CheckDirectFlipSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkdirectflipsupport) function.

### `pfnClearView`

A pointer to the [**ClearView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_clearview) function.

### `pfnUpdateTileMappings`

A pointer to the [**UpdateTileMappings**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_updatetilemappings) function.

### `pfnCopyTileMappings`

A pointer to the [**CopyTileMappings**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_copytilemappings) function.

### `pfnCopyTiles`

A pointer to the [**CopyTiles**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_copytiles) function.

### `pfnUpdateTiles`

A pointer to the [**UpdateTiles**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_updatetiles) function.

### `pfnTiledResourceBarrier`

A pointer to the [**TiledResourceBarrier**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_tiledresourcebarrier) function.

### `pfnGetMipPacking`

A pointer to the [**GetMipPacking**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_getmippacking) function.

### `pfnResizeTilePool`

A pointer to the [**ResizeTilePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_resizetilepool) function.

### `pfnSetMarker`

A pointer to the [**SetMarker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_setmarker) function.

### `pfnSetMarkerMode`

A pointer to the [**SetMarkerMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_setmarkermode) function.

### `pfnSetHardwareProtection`

Pointer to a [**SetHardwareProtection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_sethardwareprotection) function.

### `pfnGetResourceLayout`

### `pfnRetrieveShaderComment`

### `pfnSetHardwareProtectionState`

### `pfnAcquireResource`

### `pfnReleaseResource`