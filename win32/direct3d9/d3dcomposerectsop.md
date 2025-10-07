# D3DCOMPOSERECTSOP enumeration

Specifies how to combine the glyph data from the source and destination surfaces in a call to [**ComposeRects**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-composerects).

## Constants

**D3DCOMPOSERECTS\_COPY**

Copy the source to the destination.

**D3DCOMPOSERECTS\_OR**

Bitwise OR the source and the destination.

**D3DCOMPOSERECTS\_AND**

Bitwise AND the source and the destination.

**D3DCOMPOSERECTS\_NEG**

Copy the negated source to the destination (Dst & ~Src).

**D3DCOMPOSERECTS\_FORCE\_DWORD**

Reserved. Used to force enumeration to 32-bits in size.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

