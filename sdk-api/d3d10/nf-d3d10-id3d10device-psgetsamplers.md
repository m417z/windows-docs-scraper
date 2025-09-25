# ID3D10Device::PSGetSamplers

## Description

Get an array of sampler states from the [pixel shader](https://learn.microsoft.com/previous-versions/bb205146(v=vs.85)) pipeline stage.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin getting samplers from.

### `NumSamplers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of samplers to get from the device. Each pipeline stage has a total of 16 sampler slots available.

### `ppSamplers` [out]

Type: **[ID3D10SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10samplerstate)****

Array of sampler-state interface pointers (see [ID3D10SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10samplerstate)) to be returned by the device.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)