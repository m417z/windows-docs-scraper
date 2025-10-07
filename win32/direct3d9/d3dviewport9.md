# D3DVIEWPORT9 structure

Defines the window dimensions of a render-target surface onto which a 3D volume projects.

## Members

**X**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pixel coordinate of the upper-left corner of the viewport on the render-target surface. Unless you want to render to a subset of the surface, this member can be set to 0.

**Y**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pixel coordinate of the upper-left corner of the viewport on the render-target surface. Unless you want to render to a subset of the surface, this member can be set to 0.

**Width**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width dimension of the clip volume, in pixels. Unless you are rendering only to a subset of the surface, this member should be set to the width dimension of the render-target surface.

**Height**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height dimension of the clip volume, in pixels. Unless you are rendering only to a subset of the surface, this member should be set to the height dimension of the render-target surface.

**MinZ**

Type: **float**

Together with MaxZ, value describing the range of depth values into which a scene is to be rendered, the minimum and maximum values of the clip volume. Most applications set this value to 0.0. Clipping is performed after applying the projection matrix.

**MaxZ**

Type: **float**

Together with MinZ, value describing the range of depth values into which a scene is to be rendered, the minimum and maximum values of the clip volume. Most applications set this value to 1.0. Clipping is performed after applying the projection matrix.

## Remarks

The X, Y, Width, and Height members describe the position and dimensions of the viewport on the render-target surface. Usually, applications render to the entire target surface; when rendering on a 640 x 480 surface, these members should be 0, 0, 640, and 480, respectively. The MinZ and MaxZ are typically set to 0.0 and 1.0 but can be set to other values to achieve specific effects. For example, you might set them both to 0.0 to force the system to render objects to the foreground of a scene, or both to 1.0 to force the objects into the background.

When the viewport parameters for a device change (because of a call to the [**SetViewport**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setviewport) method), the driver builds a new transformation matrix.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetViewport**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getviewport)

[**SetViewport**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setviewport)

