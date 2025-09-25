# D3DWDDM2_0DDI_CORELAYER_DEVICECALLBACKS structure

## Description

This structure contains the function table for the core layer device callback functions.

## Members

### `pfnSetErrorCb`

A pointer to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function.

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

A pointer to the [pfnDisableDeferredStagingResourceDestruction](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_disable_deferred_staging_resource_destruction_cb) function.

### `pfnStateTextFilterSizeCb`

A pointer to the [pfnStateTextFilterSizeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_state_textfiltersize_cb) function.

### `pfnStateHsSrvCb`

A pointer to the [pfnStateHsSrvCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_hs_srv_cb) function.

### `pfnStateHsShaderCb`

A pointer to the [pfnStateHsShaderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_hs_shader_cb) function.

### `pfnStateHsSamplerCb`

A pointer to the [pfnStateHsSamplerCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_hs_sampler_cb) function.

### `pfnStateHsConstBufCb`

A pointer to the [pfnStateHsConstBufCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_hs_constbuf_cb) function.

### `pfnStateDsSrvCb`

A pointer to the [pfnStateDsSrvCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_ds_srv_cb) function.

### `pfnStateDsShaderCb`

A pointer to the [pfnStateDsShaderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_ds_shader_cb) function.

### `pfnStateDsSamplerCb`

A pointer to the [pfnStateDsSamplerCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_ds_sampler_cb) function.

### `pfnStateDsConstBufCb`

A pointer to the [pfnStateDsConstBufCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_ds_constbuf_cb) function.

### `pfnPerformAmortizedProcessingCb`

A pointer to the [pfnPerformAmortizedProcessingCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_perform_amortized_processing_cb) function.

### `pfnStateCsSrvCb`

A pointer to the [pfnStateCsSrvCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_cs_srv_cb) function.

### `pfnStateCsUavCb`

A pointer to the [pfnStateCsUavCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_cs_uav_cb) function.

### `pfnStateCsShaderCb`

A pointer to the [pfnStateCsShaderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_cs_shader_cb) function.

### `pfnStateCsSamplerCb`

A pointer to the [pfnStateCsSamplerCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_cs_sampler_cb) function.

### `pfnStateCsConstBufCb`

A pointer to the [pfnStateCsConstBufCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_state_cs_constbuf_cb) function.

### `pfnCreateContextCb`

A pointer to the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function.

### `pfnCreateContextVirtualCb`

A pointer to the [pfnCreateContextVirtualCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createcontextvirtualcb) function.