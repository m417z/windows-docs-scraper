# ID3D11DeviceContext::HSSetShaderResources

## Description

Bind an array of shader resources to the [hull-shader stage](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-tessellation).

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin setting shader resources to (ranges from 0 to D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1).

### `NumViews` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of shader resources to set. Up to a maximum of 128 slots are available for shader resources(ranges from 0 to D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot).

### `ppShaderResourceViews` [in, optional]

Type: **[ID3D11ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11shaderresourceview)***

Array of [shader resource view](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11shaderresourceview) interfaces to set to the device.

## Remarks

If an overlapping resource view is already bound to an output slot, such as a render target, then the method will fill the destination shader resource slot with **NULL**.

For information about creating shader-resource views, see [ID3D11Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createshaderresourceview).

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)