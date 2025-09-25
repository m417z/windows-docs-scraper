# D3D10DDI_CORELAYER_DEVICECALLBACKS structure

## Description

The D3D10DDI_CORELAYER_DEVICECALLBACKS structure contains Microsoft Direct3D 10 runtime callback functions that the user-mode display driver can use.

## Members

### `pfnSetErrorCb`

A pointer to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, which the driver uses to send errors back to the Direct3D 10 runtime because many of the driver's functions (in [D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)) return void.

### `pfnStateVsConstBufCb`

A pointer to the [pfnStateVsConstBufCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_vs_constbuf_cb) function.

### `pfnStatePsSrvCb`

A pointer to the [pfnStatePsSrvCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_ps_srv_cb) function.

### `pfnStatePsShaderCb`

A pointer to the [pfnStatePsShaderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_ps_shader_cb) function.

### `pfnStatePsSamplerCb`

A pointer to the [pfnStatePsSamplerCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_ps_sampler_cb) function.

### `pfnStateVsShaderCb`

A pointer to the [pfnStateVsShaderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_vs_shader_cb) function.

### `pfnStatePsConstBufCb`

A pointer to the [pfnStatePsConstBufCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_ps_constbuf_cb) function.

### `pfnStateIaInputLayoutCb`

A pointer to the [pfnStateIaInputLayoutCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_ia_inputlayout_cb) function.

### `pfnStateIaVertexBufCb`

A pointer to the [pfnStateIaVertexBufCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_ia_vertexbuf_cb) function.

### `pfnStateIaIndexBufCb`

A pointer to the [pfnStateIaIndexBufCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_ia_indexbuf_cb) function.

### `pfnStateGsConstBufCb`

A pointer to the [pfnStateGsConstBufCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_gs_constbuf_cb) function.

### `pfnStateGsShaderCb`

A pointer to the [pfnStateGsShaderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_gs_shader_cb) function.

### `pfnStateIaPrimitiveTopologyCb`

A pointer to the [pfnStateIaPrimitiveTopologyCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_ia_primitive_topology_cb) function.

### `pfnStateVsSrvCb`

A pointer to the [pfnStateVsSrvCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_vs_srv_cb) function.

### `pfnStateVsSamplerCb`

A pointer to the [pfnStateVsSamplerCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_vs_sampler_cb) function.

### `pfnStateGsSrvCb`

A pointer to the [pfnStateGsSrvCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_gs_srv_cb) function.

### `pfnStateGsSamplerCb`

A pointer to the [pfnStateGsSamplerCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_gs_sampler_cb) function.

### `pfnStateOmRenderTargetsCb`

A pointer to the [pfnStateOmRenderTargetsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_om_rendertargets_cb) function.

### `pfnStateOmBlendStateCb`

A pointer to the [pfnStateOmBlendStateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_om_blendstate_cb) function.

### `pfnStateOmDepthStateCb`

A pointer to the [pfnStateOmDepthStateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_om_depthstate_cb) function.

### `pfnStateRsRastStateCb`

A pointer to the [pfnStateRsRastStateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_rs_raststate_cb) function.

### `pfnStateSoTargetsCb`

A pointer to the [pfnStateSoTargetsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_so_targets_cb) function.

### `pfnStateRsViewportsCb`

A pointer to the [pfnStateRsViewportsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_rs_viewports_cb) function.

### `pfnStateRsScissorCb`

A pointer to the [pfnStateRsScissorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_rs_scissor_cb) function.

### `pfnDisableDeferredStagingResourceDestruction`

A pointer to the [pfnDisableDeferredStagingResourceDestruction](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_disable_deferred_staging_resource_destruction_cb) function. By default, the Direct3D 10 runtime defers the destruction of staging resources until the driver indicates that the hardware no longer requires them. The driver can call this function to disable this feature if the driver does not require the deferred destruction functionality.

### `pfnStateTextFilterSizeCb`

A pointer to the [pfnStateTextFilterSizeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_textfiltersize_cb) function.

## Remarks

Because the Direct3D 10 runtime might change the function pointers dynamically, the user-mode display driver cannot cache the function pointers directly.

The driver uses the functions with "State" in their name to retrieve the current state of the pipeline.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)