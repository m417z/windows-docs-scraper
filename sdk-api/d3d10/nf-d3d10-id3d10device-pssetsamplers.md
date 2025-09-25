# ID3D10Device::PSSetSamplers

## Description

Set an array of sampler states to the [pixel shader](https://learn.microsoft.com/previous-versions/bb205146(v=vs.85)) pipeline stage.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin setting samplers to.

### `NumSamplers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of samplers in the array. Each pipeline stage has a total of 16 sampler slots available.

### `ppSamplers` [in]

Type: **[ID3D10SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10samplerstate)***

Pointer to an array of sampler-state interfaces (see [ID3D10SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10samplerstate)). See Remarks.

## Remarks

Any sampler may be set to **NULL**; this invokes the default state, which is defined to be the following.

| State | Default Value |
| --- | --- |
| Filter | D3D10_FILTER_MIN_MAG_MIP_LINEAR |
| AddressU | D3D10_TEXTURE_ADDRESS_CLAMP |
| AddressV | D3D10_TEXTURE_ADDRESS_CLAMP |
| AddressW | D3D10_TEXTURE_ADDRESS_CLAMP |
| MipLODBias | 0 |
| MaxAnisotropy | 1 |
| ComparisonFunc | D3D10_COMPARISON_NEVER |
| BorderColor[0] | 1.0f |
| BorderColor[1] | 1.0f |
| BorderColor[2] | 1.0f |
| BorderColor[3] | 1.0f |
| MinLOD | -FLT_MAX |
| MaxLOD | FLT_MAX |

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)