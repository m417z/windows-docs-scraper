# D3DLOCKED\_RECT structure

Describes a locked rectangular region.

## Members

**Pitch**

Type: **[**INT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of bytes in one row of the surface.

**pBits**

Type: **void\***

Pointer to the locked bits. If a [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) was provided to the [**LockRect**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-lockrect) call, pBits will be appropriately offset from the start of the surface.

## Remarks

The pitch for DXTn formats is different from what was returned in DirectX 7. It now refers to the number of bytes in a row of blocks. For example, if you have a width of 16, then you will have a pitch of 4 blocks (4\*8 for DXT1, 4\*16 for DXT2-5.)

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**IDirect3DCubeTexture9::LockRect**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dcubetexture9-lockrect)

[**IDirect3DSurface9::LockRect**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-lockrect)

[**IDirect3DTexture9::LockRect**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dtexture9-lockrect)

