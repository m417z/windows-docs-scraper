# D3DX10\_SPRITE\_FLAG enumeration

Sprite flags that tell the sprite drawing API how to behave. These are passed into [**ID3DX10Sprite::Begin**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10sprite-begin).

## Constants

**D3DX10\_SPRITE\_SORT\_TEXTURE**

Sort the sprites by texture before rendering so that when there are many sprites with the same texture that texture all of those sprites will be rendered at the same time, thereby improving performance.

**D3DX10\_SPRITE\_SORT\_DEPTH\_BACK\_TO\_FRONT**

Sort the sprites from back to front to that those farther away from the camera will be drawn first.

**D3DX10\_SPRITE\_SORT\_DEPTH\_FRONT\_TO\_BACK**

Sort the sprites from front to back so that those closer to the camera will be drawn first.

**D3DX10\_SPRITE\_SAVE\_STATE**

Saves the state so that when [**ID3DX10Sprite::End**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10sprite-end) is called, it will restore the state to the way it was before [**ID3DX10Sprite::Begin**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10sprite-begin) was called.

**D3DX10\_SPRITE\_ADDREF\_TEXTURES**

Calls AddRef on all of the textures when they are passed into [**ID3DX10Sprite::DrawSpritesBuffered**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10sprite-drawspritesbuffered).

## Remarks

After a front-to-back or back-to-front sort is done, it will automatically do a secondary sort by texture. This is helpful for when there are many sprites with the same texture all on the same plane, such as when drawing the user interface in a game.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-enums)

