# D3DDISPLAYROTATION enumeration

Specifies how the monitor being used to display a full-screen application is rotated.

## Constants

**D3DDISPLAYROTATION\_IDENTITY**

Display is not rotated.

**D3DDISPLAYROTATION\_90**

Display is rotated 90 degrees.

**D3DDISPLAYROTATION\_180**

Display is rotated 180 degrees.

**D3DDISPLAYROTATION\_270**

Display is rotated 270 degrees.

## Remarks

This enumeration is used in [**IDirect3D9Ex::GetAdapterDisplayModeEx**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9ex-getadapterdisplaymodeex), [**IDirect3DDevice9Ex::GetDisplayModeEx**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-getdisplaymodeex), and [**IDirect3DSwapChain9Ex::GetDisplayModeEx**](https://learn.microsoft.com/windows/desktop/api/D3D9/nf-d3d9-idirect3dswapchain9ex-getdisplaymodeex).

Applications may choose to handle monitor rotation themselves by using the [D3DPRESENTFLAG\_NOAUTOROTATE](https://learn.microsoft.com/windows/win32/direct3d9/d3dpresentflag), in which case, the application will need to know how the monitor is rotated so that it may adjust its rendering accordingly.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

