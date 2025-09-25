# D3D12DDI_SHADERCACHE_HASH structure

## Description

The **D3D12DDI_SHADERCACHE_HASH** structure contains a hash value associated with a shader in the shader cache.

## Members

### `Hash`

A hash value. When a shader is compiled, a hash value based on the shader code and possibly other relevant data is computed. This hash is then used as a key to store and retrieve the compiled shader code from the shader cache.

## See also

[**PFND3D12DDI_CREATE_SHADER_0026**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_shader_0026)

[**pfnShaderCacheGetValueCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_shadercachegetvalue_cb_0021)

[**pfnShaderCacheStoreValueCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_shadercachestorevalue_cb_0021)