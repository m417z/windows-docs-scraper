## Description

**D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAGS_0080** enumerates the control action(s) to take on a driver-managed shader cache.

## Constants

### `D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAG_0080_DISABLE`

Disable the shader cache. A disabled cache cannot be used to look up data or have new data stored in it.

### `D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAG_0080_ENABLE`

Resumes use of the cache.

### `D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAG_0080_CLEAR`

Delete any existing cache content.

## Remarks

**D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAGS_0080** is a parameter passed to a driver's [**PFND3D12DDI_IMPLICITSHADERCACHECONTROL_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_implicitshadercachecontrol_0080).

A driver will not receive both **D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAG_0080_DISABLE** and **D3D12DDI_IMPLICIT_SHADER_CACHE_CONTROL_FLAG_0080_ENABLE** at the same time.

See the [D3D12 Shader Cache APIs specification](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html) for more information.

## See also

[**PFND3D12DDI_IMPLICITSHADERCACHECONTROL_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_implicitshadercachecontrol_0080)