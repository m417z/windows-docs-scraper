# D3DX10CreateSprite function

Create a sprite for drawing a 2D texture.

> [!Note]
> Instead of using this function, we recommend that you use [Direct2D](https://learn.microsoft.com/windows/win32/direct2d/direct2d-portal) and the [DirectXTK](https://github.com/Microsoft/DirectXTK) library, **SpriteBatch** class.

## Parameters

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\***

A pointer to the device (see [**ID3D10Device Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)) that will draw the sprite.

*cDeviceBufferSize* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the vertex buffer, in number of sprites, that will be sent to the device when [**ID3DX10Sprite::Flush**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10sprite-flush) or [**ID3DX10Sprite::DrawSpritesImmediate**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10sprite-drawspritesimmediate) is called. This should be a small number if you know you will be rendering a small number of sprites at a time (to save memory) and a large number if you know you will be rendering a large number of sprites at a time. The maximum value is 4096. If 0 is specified, the vertex buffer size will automatically be set to 4096.

*ppSprite* \[out\]

Type: **[**LPD3DX10SPRITE**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10sprite)\***

The address of a pointer to a sprite interface (see [**ID3DX10Sprite Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10sprite)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |
| Library<br> | D3DX10.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

