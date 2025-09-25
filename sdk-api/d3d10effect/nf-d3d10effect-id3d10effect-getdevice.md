# ID3D10Effect::GetDevice

## Description

Get the device that created the effect.

## Parameters

### `ppDevice` [out]

Type: **[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)****

A pointer to an [ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

An effect is created for a specific device, by calling a function such as [D3DX10CreateEffectFromFile](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10createeffectfromfile).

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)