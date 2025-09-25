# ID3D11DeviceContext::PSSetSamplers

## Description

Set an array of sampler states to the pixel shader pipeline stage.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin setting samplers to (ranges from 0 to D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1).

### `NumSamplers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of samplers in the array. Each pipeline stage has a total of 16 sampler slots available (ranges from 0 to D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot).

### `ppSamplers` [in, optional]

Type: **[ID3D11SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11samplerstate)***

Pointer to an array of sampler-state interfaces (see [ID3D11SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11samplerstate)). See Remarks.

## Remarks

Any sampler may be set to **NULL**; this invokes the default state, which is defined to be the following.

| State | Default Value |
| --- | --- |
| Filter | D3D11_FILTER_MIN_MAG_MIP_LINEAR |
| AddressU | D3D11_TEXTURE_ADDRESS_CLAMP |
| AddressV | D3D11_TEXTURE_ADDRESS_CLAMP |
| AddressW | D3D11_TEXTURE_ADDRESS_CLAMP |
| MipLODBias | 0 |
| MaxAnisotropy | 1 |
| ComparisonFunc | D3D11_COMPARISON_NEVER |
| BorderColor[0] | 1.0f |
| BorderColor[1] | 1.0f |
| BorderColor[2] | 1.0f |
| BorderColor[3] | 1.0f |
| MinLOD | -FLT_MAX |
| MaxLOD | FLT_MAX |

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)