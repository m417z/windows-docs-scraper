# ID3D10Device::GSSetShaderResources

## Description

Bind an array of shader resources to the [geometry shader stage](https://learn.microsoft.com/windows/desktop/direct3d11/geometry-shader-stage).

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin setting shader resources to.

### `NumViews` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of shader resources to set. Up to a maximum of 128 slots are available for shader resources.

### `ppShaderResourceViews` [in]

Type: **[ID3D10ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview)***

Array of [shader resource view](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview) interfaces to set to the device.

## Remarks

If you bind a subresource as an input and an output, this API will fill the destination shader resource slot with **NULL**. The debug layer (when active) will alert you if this is true.

For information about creating shader-resource views, see [ID3D10Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createshaderresourceview).

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)