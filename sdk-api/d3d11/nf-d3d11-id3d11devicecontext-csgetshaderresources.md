# ID3D11DeviceContext::CSGetShaderResources

## Description

Get the compute-shader resources.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin getting shader resources from (ranges from 0 to D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1).

### `NumViews` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of resources to get from the device. Up to a maximum of 128 slots are available for shader resources (ranges from 0 to D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot).

### `ppShaderResourceViews` [out, optional]

Type: **[ID3D11ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11shaderresourceview)****

Array of [shader resource view](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11shaderresourceview) interfaces to be returned by the device.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)