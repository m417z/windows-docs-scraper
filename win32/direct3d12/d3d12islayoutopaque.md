# D3D12IsLayoutOpaque function

Indicates whether the layout is opaque.

## Parameters

*Layout*

Type: **[**D3D12\_TEXTURE\_LAYOUT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout)**

The layout to check, as a [**D3D12\_TEXTURE\_LAYOUT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout).

## Return value

Type: **bool**

A **bool** that indicates whether the layout is opaque. A layout is opaque if it is D3D12\_TEXTURE\_LAYOUT\_UNKNOWN or D3D12\_TEXTURE\_LAYOUT\_64KB\_UNDEFINED\_SWIZZLE.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

