# ID3D10ShaderReflection1::IsSampleFrequencyShader

## Description

Indicates whether a pixel shader is intended to run a pixel frequency or sample frequency.

## Parameters

### `pbSampleFrequency`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a BOOL variable that will be set to true if the shader is intended to run at sample frequency; false otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This method requires Windows Vista Service Pack 1.

## See also

[ID3D10ShaderReflection1 Interface](https://learn.microsoft.com/windows/desktop/api/d3d10_1shader/nn-d3d10_1shader-id3d10shaderreflection1)