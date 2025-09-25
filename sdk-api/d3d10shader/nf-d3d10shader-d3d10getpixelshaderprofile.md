# D3D10GetPixelShaderProfile function

## Description

Get the pixel [shader profile](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-models) best suited to a given device.

## Parameters

### `pDevice` [in]

Type: **[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)***

Pointer to the device (see [ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)).

## Return value

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The shader profile.

## See also

[Shader Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-functions)