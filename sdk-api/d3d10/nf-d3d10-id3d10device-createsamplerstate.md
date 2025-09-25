# ID3D10Device::CreateSamplerState

## Description

Create a sampler-state object that encapsulates sampling information for a [texture](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-type).

## Parameters

### `pSamplerDesc` [in]

Type: **const [D3D10_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_sampler_desc)***

Pointer to a sampler state description (see [D3D10_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_sampler_desc)).

### `ppSamplerState` [out]

Type: **[ID3D10SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10samplerstate)****

Address of a pointer to the sampler state object created (see [ID3D10SamplerState Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10samplerstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

4096 unique sampler state objects can be created on a device at a time.

If an application attempts to create a sampler state with the same description as an already existing sampler state, then the same interface with an incremented reference count will be returned and the total number of unique sampler state objects will stay the same.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)