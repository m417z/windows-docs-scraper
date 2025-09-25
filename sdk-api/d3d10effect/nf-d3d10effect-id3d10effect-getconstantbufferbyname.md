# ID3D10Effect::GetConstantBufferByName

## Description

Get a constant buffer by name.

## Parameters

### `Name` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The constant-buffer name.

## Return value

Type: **[ID3D10EffectConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectconstantbuffer)***

A pointer to the constant buffer indicated by the Name. See [ID3D10EffectConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectconstantbuffer).

## Remarks

An effect that contains a variable that will be read/written by an application requires at least one constant buffer. For best performance, an effect should organize variables into one or more constant buffers based on their frequency of update.

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)