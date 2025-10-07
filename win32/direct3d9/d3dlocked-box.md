# D3DLOCKED\_BOX structure

Describes a locked box (volume).

## Members

**RowPitch**

Type: **[**int**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Byte offset from the left edge of one row to the left edge of the next row.

**SlicePitch**

Type: **[**int**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Byte offset from the top-left of one slice to the top-left of the next deepest slice.

**pBits**

Type: **void\***

Pointer to the beginning of the volume box. If a [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox) was provided to the LockBox call, pBits will be appropriately offset from the start of the volume.

## Remarks

Volumes can be visualized as being organized into slices of width x height 2D surfaces stacked up to make a width x height x depth volume. For more information, see [Volume Texture Resources (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/volume-texture-resources).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**IDirect3DVolume9::LockBox**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dvolume9-lockbox)

[**IDirect3DVolumeTexture9::LockBox**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dvolumetexture9-lockbox)

