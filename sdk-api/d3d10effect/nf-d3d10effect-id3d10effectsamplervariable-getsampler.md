# ID3D10EffectSamplerVariable::GetSampler

## Description

Get a pointer to a sampler interface.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into an array of sampler interfaces. If there is only one sampler interface, use 0.

### `ppSampler` [out]

Type: **[ID3D10SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10samplerstate)****

The address of a pointer to a sampler interface (see [ID3D10SamplerState Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10samplerstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectSamplerVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectsamplervariable)