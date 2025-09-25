# ID3D11DeviceContext::Unmap

## Description

Invalidate the pointer to a resource and reenable the GPU's access to that resource.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to a [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) interface.

### `Subresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A subresource to be unmapped.

## Remarks

For info about how to use **Unmap**, see [How to: Use dynamic resources](https://learn.microsoft.com/windows/desktop/direct3d11/how-to--use-dynamic-resources).

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)