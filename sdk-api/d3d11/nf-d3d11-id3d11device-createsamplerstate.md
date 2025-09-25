# ID3D11Device::CreateSamplerState

## Description

Create a sampler-state object that encapsulates sampling information for a texture.

## Parameters

### `pSamplerDesc` [in]

Type: **const [D3D11_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_sampler_desc)***

Pointer to a sampler state description (see [D3D11_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_sampler_desc)).

### `ppSamplerState` [out, optional]

Type: **[ID3D11SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11samplerstate)****

Address of a pointer to the sampler state object created (see [ID3D11SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11samplerstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

4096 unique sampler state objects can be created on a device at a time.

If an application attempts to create a sampler-state interface with the same state as an existing interface, the same interface will be returned and the total number of unique sampler state objects will stay the same.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)