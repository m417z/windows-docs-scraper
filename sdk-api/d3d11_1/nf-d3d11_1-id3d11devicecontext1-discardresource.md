# ID3D11DeviceContext1::DiscardResource

## Description

Discards a resource from the device context.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) interface for the resource to discard. The resource must have been created with usage [D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) or [D3D11_USAGE_DYNAMIC](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage), otherwise the runtime drops the call to **DiscardResource**; if the debug layer is enabled, the runtime returns an error message.

## Remarks

**DiscardResource** informs the graphics processing unit (GPU) that the existing content in the resource that *pResource* points to is no longer needed.

## See also

[ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1)