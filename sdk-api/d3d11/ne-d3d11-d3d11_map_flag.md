# D3D11_MAP_FLAG enumeration

## Description

Specifies how the CPU should respond when an application calls the [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) method on a resource that is being used by the GPU.

## Constants

### `D3D11_MAP_FLAG_DO_NOT_WAIT:0x100000L`

Specifies that [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) should return DXGI_ERROR_WAS_STILL_DRAWING when the GPU blocks the CPU from accessing a resource. For more information about this error code, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

This enumeration is used by [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map).

D3D11_MAP_FLAG_DO_NOT_WAIT cannot be used with [D3D11_MAP_WRITE_DISCARD](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map) or [D3D11_MAP_WRITE_NOOVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map).

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)