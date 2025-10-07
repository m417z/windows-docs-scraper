# D3DBLEND enumeration

Defines the supported blend mode.

## Constants

**D3DBLEND\_ZERO**

Blend factor is (0, 0, 0, 0).

**D3DBLEND\_ONE**

Blend factor is (1, 1, 1, 1).

**D3DBLEND\_SRCCOLOR**

Blend factor is (Rₛ, Gₛ, Bₛ, Aₛ).

**D3DBLEND\_INVSRCCOLOR**

Blend factor is (1 - Rₛ, 1 - Gₛ, 1 - Bₛ, 1 - Aₛ).

**D3DBLEND\_SRCALPHA**

Blend factor is (Aₛ, Aₛ, Aₛ, Aₛ).

**D3DBLEND\_INVSRCALPHA**

Blend factor is ( 1 - Aₛ, 1 - Aₛ, 1 - Aₛ, 1 - Aₛ).

**D3DBLEND\_DESTALPHA**

Blend factor is (Ad Ad Ad Ad).

**D3DBLEND\_INVDESTALPHA**

Blend factor is (1 - Ad 1 - Ad 1 - Ad 1 - Ad).

**D3DBLEND\_DESTCOLOR**

Blend factor is (Rd, Gd, Bd, Ad).

**D3DBLEND\_INVDESTCOLOR**

Blend factor is (1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad).

**D3DBLEND\_SRCALPHASAT**

Blend factor is (f, f, f, 1); where f = min(Aₛ, 1 - Ad).

**D3DBLEND\_BOTHSRCALPHA**

**Obsolete**. Starting with DirectX 6, you can achieve the same effect by setting the source and destination blend factors to D3DBLEND\_SRCALPHA and D3DBLEND\_INVSRCALPHA in separate calls.

**D3DBLEND\_BOTHINVSRCALPHA**

**Obsolete**. Source blend factor is (1 - Aₛ, 1 - Aₛ, 1 - Aₛ, 1 - Aₛ), and destination blend factor is (Aₛ, Aₛ, Aₛ, Aₛ); the destination blend selection is overridden. This blend mode is supported only for the D3DRS\_SRCBLEND render state.

**D3DBLEND\_BLENDFACTOR**

Constant color blending factor used by the frame-buffer blender. This blend mode is supported only if D3DPBLENDCAPS\_BLENDFACTOR is set in the **SrcBlendCaps** or **DestBlendCaps** members of [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9).

**D3DBLEND\_INVBLENDFACTOR**

Inverted constant color-blending factor used by the frame-buffer blender. This blend mode is supported only if the D3DPBLENDCAPS\_BLENDFACTOR bit is set in the **SrcBlendCaps** or **DestBlendCaps** members of [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9).

**D3DBLEND\_SRCCOLOR2**

Blend factor is (PSOutColor\[1\]r, PSOutColor\[1\]g, PSOutColor\[1\]b, not used). See [Render Target Blending](https://learn.microsoft.com/windows/win32/direct3d9/d3dblend#render-target-blending).

Differences between Direct3D 9 and Direct3D 9Ex:

- This flag is available in Direct3D 9Ex only.

**D3DBLEND\_INVSRCCOLOR2**

Blend factor is (1 - PSOutColor\[1\]r, 1 - PSOutColor\[1\]g, 1 - PSOutColor\[1\]b, not used)). See [Render Target Blending](https://learn.microsoft.com/windows/win32/direct3d9/d3dblend#render-target-blending).

Differences between Direct3D 9 and Direct3D 9Ex:

- This flag is available in Direct3D 9Ex only.

**D3DBLEND\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

In the preceding member descriptions, the RGBA values of the source and destination are indicated by the s and d subscripts.

The values in this enumerated type are used by the following render states:

- D3DRS\_DESTBLEND
- D3DRS\_SRCBLEND
- D3DRS\_DESTBLENDALPHA
- D3DRS\_SRCBLENDALPHA

See [**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

### Render Target Blending

Direct3D 9Ex has improved text rendering capabilities. Rendering clear-type fonts would normally require two passes. To eliminate the second pass, a pixel shader can be used to output two colors, which we can call PSOutColor\[0\] and PSOutColor\[1\]. The first color would contain the standard 3 color components (RGB). The second color would contain 3 alpha components (one for each component of the first color).

These new blending modes are only used for text rendering on the first render target.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

