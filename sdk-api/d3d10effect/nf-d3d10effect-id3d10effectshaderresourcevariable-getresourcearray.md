# ID3D10EffectShaderResourceVariable::GetResourceArray

## Description

Get an array of shader resources.

## Parameters

### `ppResources` [out]

Type: **[ID3D10ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview)****

The address of an array of shader-resource-view interfaces. See [ID3D10ShaderResourceView Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview).

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based array index to get the first interface.

### `Count` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectShaderResourceVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectshaderresourcevariable)