# D3DX11CreateEffectFromMemory function

Creates an effect from a binary effect or file.

## Parameters

*pData*

Type: **void\***

Blob of compiled effect data.

*DataLength*

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of the data blob.

*FXFlags*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

No effect flags exist. Set to zero.

*pDevice*

Type: **[**ID3D11Device**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11device)\***

Pointer to the [**ID3D11Device**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11device) on which to create Effect resources.

*ppEffect*

Type: **[**ID3DX11Effect**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effect)\*\***

Address of the newly created [**ID3DX11Effect**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effect) interface.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

> [!Note]
> You must use [Effects 11 source](https://github.com/Microsoft/FX11) to build your effects-type application. For more info about using Effects 11 source, see [Differences Between Effects 10 and Effects 11](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-programming-guide-effects-differences).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-functions)

