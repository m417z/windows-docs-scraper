# ID3D10Device::VSGetShaderResources

## Description

Get the vertex shader resources.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin getting shader resources from.

### `NumViews` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of resources to get from the device. Up to a maximum of 128 slots are available for shader resources.

### `ppShaderResourceViews` [out]

Type: **[ID3D10ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview)****

Array of [shader resource view](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview) interfaces to be returned by the device.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)