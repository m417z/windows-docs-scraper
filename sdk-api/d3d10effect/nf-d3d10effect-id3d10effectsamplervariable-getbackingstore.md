# ID3D10EffectSamplerVariable::GetBackingStore

## Description

Get a pointer to a variable that contains sampler state.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into an array of sampler descriptions. If there is only one sampler variable in the effect, use 0.

### `pSamplerDesc` [in]

Type: **[D3D10_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_sampler_desc)***

A pointer to a sampler description (see [D3D10_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_sampler_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectSamplerVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectsamplervariable)