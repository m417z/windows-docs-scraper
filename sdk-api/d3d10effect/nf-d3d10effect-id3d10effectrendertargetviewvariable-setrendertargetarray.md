# ID3D10EffectRenderTargetViewVariable::SetRenderTargetArray

## Description

Set an array of render-targets.

## Parameters

### `ppResources` [out]

Type: **[ID3D10RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rendertargetview)****

Set an array of render-target-view interfaces. See [ID3D10RenderTargetView Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rendertargetview).

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based array index to store the first interface.

### `Count` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectRenderTargetViewVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectrendertargetviewvariable)