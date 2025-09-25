# ID3D11DeviceContext::HSGetSamplers

## Description

Get an array of sampler state interfaces from the [hull-shader stage](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-tessellation).

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into a zero-based array to begin getting samplers from (ranges from 0 to D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1).

### `NumSamplers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of samplers to get from a device context. Each pipeline stage has a total of 16 sampler slots available (ranges from 0 to D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot).

### `ppSamplers` [out, optional]

Type: **[ID3D11SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11samplerstate)****

Pointer to an array of sampler-state interfaces (see [ID3D11SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11samplerstate)).

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)