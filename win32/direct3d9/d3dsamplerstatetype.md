# D3DSAMPLERSTATETYPE enumeration

Sampler states define texture sampling operations such as texture addressing and texture filtering. Some sampler states set-up vertex processing, and some set-up pixel processing. Sampler states can be saved and restored using stateblocks (see [State Blocks Save and Restore State (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/state-blocks-save-and-restore-state)).

## Constants

**D3DSAMP\_ADDRESSU**

Texture-address mode for the u coordinate. The default is D3DTADDRESS\_WRAP. For more information, see [**D3DTEXTUREADDRESS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtextureaddress).

**D3DSAMP\_ADDRESSV**

Texture-address mode for the v coordinate. The default is D3DTADDRESS\_WRAP. For more information, see [**D3DTEXTUREADDRESS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtextureaddress).

**D3DSAMP\_ADDRESSW**

Texture-address mode for the w coordinate. The default is D3DTADDRESS\_WRAP. For more information, see [**D3DTEXTUREADDRESS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtextureaddress).

**D3DSAMP\_BORDERCOLOR**

Border color or type [**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor). The default color is 0x00000000.

**D3DSAMP\_MAGFILTER**

Magnification filter of type [**D3DTEXTUREFILTERTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtexturefiltertype). The default value is D3DTEXF\_POINT.

**D3DSAMP\_MINFILTER**

Minification filter of type [**D3DTEXTUREFILTERTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtexturefiltertype). The default value is D3DTEXF\_POINT.

**D3DSAMP\_MIPFILTER**

Mipmap filter to use during minification. See [**D3DTEXTUREFILTERTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtexturefiltertype). The default value is D3DTEXF\_NONE.

**D3DSAMP\_MIPMAPLODBIAS**

Mipmap level-of-detail bias. The default value is zero.

**D3DSAMP\_MAXMIPLEVEL**

level-of-detail index of largest map to use. Values range from 0 to (n - 1) where 0 is the largest. The default value is zero.

**D3DSAMP\_MAXANISOTROPY**

DWORD maximum anisotropy. Values range from 1 to the value that is specified in the **MaxAnisotropy** member of the [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9) structure. The default value is 1.

**D3DSAMP\_SRGBTEXTURE**

Gamma correction value. The default value is 0, which means gamma is 1.0 and no correction is required. Otherwise, this value means that the sampler should assume gamma of 2.2 on the content and convert it to linear (gamma 1.0) before presenting it to the pixel shader.

**D3DSAMP\_ELEMENTINDEX**

When a multielement texture is assigned to the sampler, this indicates which element index to use. The default value is 0.

**D3DSAMP\_DMAPOFFSET**

Vertex offset in the presampled displacement map. This is a constant used by the tessellator, its default value is 0.

**D3DSAMP\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

