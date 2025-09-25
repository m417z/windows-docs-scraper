## Description

The user-mode display driver's **PFND3D12DDI_CREATE_SHADER_0026** callback function creates a shader.

## Parameters

### `unnamedParam1`

[in] A handle to the display device (graphics context) for which to create the shader.

### `unnamedParam2`

[in] Pointer to a [**D3D12DDIARG_CREATE_SHADER_0026**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_shader_0026) structure that describes the shader to create.

### `unnamedParam3`

[out] Handle to the shader that the driver created.

## Remarks

The [**D3D12DDI_DEVICE_FUNCS_CORE_*XXX***](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0109) structure contains pointers to **PFND3D12DDI_CREATE_SHADER_0026** callback functions for the various shader types that the driver supports.

## See also

[**D3D12DDIARG_CREATE_SHADER_0026**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_shader_0026)