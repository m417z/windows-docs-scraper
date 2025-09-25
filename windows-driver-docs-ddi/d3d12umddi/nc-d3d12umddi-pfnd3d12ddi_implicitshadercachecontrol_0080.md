## Description

The **pfnImplicitShaderCacheControl** callback function can optionally perform an application-requested action on the driver-managed shader cache.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A [**D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_implicit_shader_cache_control_flags_0080) value that describes the shader cache control action(s) to take on the driver-managed shader cache.

## Remarks

The runtime calls **pfnImplicitShaderCacheControl** in response to an application request for cache control. These application requests are considered as hints to the driver.

This callback function is supported only in developer mode.

See the [D3D12 Shader Cache APIs specification](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html) for more information.

## See also

[**D3D12DDI_D3D12_OPTIONS_DATA_008n**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0080)

[**D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_implicit_shader_cache_control_flags_0080)