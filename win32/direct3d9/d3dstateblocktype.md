# D3DSTATEBLOCKTYPE enumeration

Predefined sets of pipeline state used by state blocks (see [State Blocks Save and Restore State (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/state-blocks-save-and-restore-state)).

## Constants

**D3DSBT\_ALL**

Capture the current [device state](https://learn.microsoft.com/windows/win32/direct3d9/saving-all-device-states-with-a-stateblock).

**D3DSBT\_PIXELSTATE**

Capture the current [pixel state](https://learn.microsoft.com/windows/win32/direct3d9/saving-pixel-states-with-a-stateblock).

**D3DSBT\_VERTEXSTATE**

Capture the current [vertex state](https://learn.microsoft.com/windows/win32/direct3d9/saving-vertex-states-with-a-stateblock).

**D3DSBT\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. Do not use this value.

## Remarks

As the following diagram shows, vertex and pixel state are both subsets of device state.

![diagram of device state, with vertex state and pixel state as subsets](https://learn.microsoft.com/windows/win32/direct3d9/images/statesets.png)

There are only a few states that are considered both vertex and pixel state. These states are:

- Render state: D3DRS\_FOGDENSITY
- Render state: D3DRS\_FOGSTART
- Render state: D3DRS\_FOGEND
- Texture state: D3DTSS\_TEXCOORDINDEX
- Texture state: D3DTSS\_TEXTURETRANSFORMFLAGS

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**IDirect3DDevice9::CreateStateBlock**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createstateblock)

**IDirect3DDevice9::CreateStateBlock**

