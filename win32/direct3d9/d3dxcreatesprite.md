# D3DXCreateSprite function

Creates a sprite object which is associated with a particular device. Sprite objects are used to draw 2D images to the screen.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, the device to be associated with the sprite.

*ppSprite* \[out\]

Type: **[**LPD3DXSPRITE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxsprite)\***

Address of a pointer to an [**ID3DXSprite**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxsprite) interface. This interface allows the user to access sprite functions.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

This interface can be used to draw two dimensional images in screen space of the associated device.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |
| Library<br> | D3dx9.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-general-purpose)

