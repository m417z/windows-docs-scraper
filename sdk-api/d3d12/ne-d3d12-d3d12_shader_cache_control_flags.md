## Description

Defines constants that specify shader cache control options.

## Constants

### `D3D12_SHADER_CACHE_CONTROL_FLAG_DISABLE:0x1`

Specifies that the cache shouldn't be used to look up data, and shouldn't have new data stored in it. Attempts to use/create a cache while it's disabled result in **DXGI_ERROR_NOT_CURRENTLY_AVAILABLE**.

### `D3D12_SHADER_CACHE_CONTROL_FLAG_ENABLE:0x2`

Specfies that use of the cache should be resumed.

### `D3D12_SHADER_CACHE_CONTROL_FLAG_CLEAR:0x4`

Specfies that any existing contents of the cache should be deleted.

## Remarks

## See also
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)