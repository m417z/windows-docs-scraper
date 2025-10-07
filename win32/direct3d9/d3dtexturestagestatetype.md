# D3DTEXTURESTAGESTATETYPE enumeration

Texture stage states define multi-blender texture operations. Some sampler states set up vertex processing, and some set up pixel processing. Texture stage states can be saved and restored using stateblocks (see [State Blocks Save and Restore State (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/state-blocks-save-and-restore-state)).

## Constants

**D3DTSS\_COLOROP**

Texture-stage state is a texture color blending operation identified by one member of the [**D3DTEXTUREOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtextureop) enumerated type. The default value for the first texture stage (stage 0) is D3DTOP\_MODULATE; for all other stages the default is D3DTOP\_DISABLE.

**D3DTSS\_COLORARG1**

Texture-stage state is the first color argument for the stage, identified by one of the [D3DTA](https://learn.microsoft.com/windows/win32/direct3d9/d3dta). The default argument is D3DTA\_TEXTURE.

Specify D3DTA\_TEMP to select a temporary register color for read or write. D3DTA\_TEMP is supported if the D3DPMISCCAPS\_TSSARGTEMP device capability is present. The default value for the register is (0.0, 0.0, 0.0, 0.0).

**D3DTSS\_COLORARG2**

Texture-stage state is the second color argument for the stage, identified by [D3DTA](https://learn.microsoft.com/windows/win32/direct3d9/d3dta). The default argument is D3DTA\_CURRENT. Specify D3DTA\_TEMP to select a temporary register color for read or write. D3DTA\_TEMP is supported if the D3DPMISCCAPS\_TSSARGTEMP device capability is present. The default value for the register is (0.0, 0.0, 0.0, 0.0)

**D3DTSS\_ALPHAOP**

Texture-stage state is a texture alpha blending operation identified by one member of the [**D3DTEXTUREOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtextureop) enumerated type. The default value for the first texture stage (stage 0) is D3DTOP\_SELECTARG1, and for all other stages the default is D3DTOP\_DISABLE.

**D3DTSS\_ALPHAARG1**

Texture-stage state is the first alpha argument for the stage, identified by [D3DTA](https://learn.microsoft.com/windows/win32/direct3d9/d3dta). The default argument is D3DTA\_TEXTURE. If no texture is set for this stage, the default argument is D3DTA\_DIFFUSE. Specify D3DTA\_TEMP to select a temporary register color for read or write. D3DTA\_TEMP is supported if the D3DPMISCCAPS\_TSSARGTEMP device capability is present. The default value for the register is (0.0, 0.0, 0.0, 0.0).

**D3DTSS\_ALPHAARG2**

Texture-stage state is the second alpha argument for the stage, identified by [D3DTA](https://learn.microsoft.com/windows/win32/direct3d9/d3dta). The default argument is D3DTA\_CURRENT. Specify D3DTA\_TEMP to select a temporary register color for read or write. D3DTA\_TEMP is supported if the D3DPMISCCAPS\_TSSARGTEMP device capability is present. The default value for the register is (0.0, 0.0, 0.0, 0.0).

**D3DTSS\_BUMPENVMAT00**

Texture-stage state is a floating-point value for the \[0\]\[0\] coefficient in a bump-mapping matrix. The default value is 0.0.

**D3DTSS\_BUMPENVMAT01**

Texture-stage state is a floating-point value for the \[0\]\[1\] coefficient in a bump-mapping matrix. The default value is 0.0.

**D3DTSS\_BUMPENVMAT10**

Texture-stage state is a floating-point value for the \[1\]\[0\] coefficient in a bump-mapping matrix. The default value is 0.0.

**D3DTSS\_BUMPENVMAT11**

Texture-stage state is a floating-point value for the \[1\]\[1\] coefficient in a bump-mapping matrix. The default value is 0.0.

**D3DTSS\_TEXCOORDINDEX**

Index of the texture coordinate set to use with this texture stage. You can specify up to eight sets of texture coordinates per vertex. If a vertex does not include a set of texture coordinates at the specified index, the system defaults to the u and v coordinates (0,0).

When rendering using vertex shaders, each stage's texture coordinate index must be set to its default value. The default index for each stage is equal to the stage index. Set this state to the zero-based index of the coordinate set for each vertex that this texture stage uses.

Additionally, applications can include, as logical OR with the index being set, one of the constants to request that Direct3D automatically generate the input texture coordinates for a texture transformation. For a list of all the constants, see [D3DTSS\_TCI](https://learn.microsoft.com/windows/win32/direct3d9/d3dtss-tci).

With the exception of D3DTSS\_TCI\_PASSTHRU, which resolves to zero, if any of the following values is included with the index being set, the system uses the index strictly to determine texture wrapping mode. These flags are most useful when performing environment mapping.

**D3DTSS\_BUMPENVLSCALE**

Floating-point scale value for bump-map luminance. The default value is 0.0.

**D3DTSS\_BUMPENVLOFFSET**

Floating-point offset value for bump-map luminance. The default value is 0.0.

**D3DTSS\_TEXTURETRANSFORMFLAGS**

Member of the [**D3DTEXTURETRANSFORMFLAGS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtexturetransformflags) enumerated type that controls the transformation of texture coordinates for this texture stage. The default value is D3DTTFF\_DISABLE.

**D3DTSS\_COLORARG0**

Settings for the third color operand for triadic operations (multiply, add, and linearly interpolate), identified by [D3DTA](https://learn.microsoft.com/windows/win32/direct3d9/d3dta). This setting is supported if the D3DTEXOPCAPS\_MULTIPLYADD or D3DTEXOPCAPS\_LERP device capabilities are present. The default argument is D3DTA\_CURRENT. Specify D3DTA\_TEMP to select a temporary register color for read or write. D3DTA\_TEMP is supported if the D3DPMISCCAPS\_TSSARGTEMP device capability is present. The default value for the register is (0.0, 0.0, 0.0, 0.0).

**D3DTSS\_ALPHAARG0**

Settings for the alpha channel selector operand for triadic operations (multiply, add, and linearly interpolate), identified by [D3DTA](https://learn.microsoft.com/windows/win32/direct3d9/d3dta). This setting is supported if the D3DTEXOPCAPS\_MULTIPLYADD or D3DTEXOPCAPS\_LERP device capabilities are present. The default argument is D3DTA\_CURRENT. Specify D3DTA\_TEMP to select a temporary register color for read or write. D3DTA\_TEMP is supported if the D3DPMISCCAPS\_TSSARGTEMP device capability is present. The default argument is (0.0, 0.0, 0.0, 0.0).

**D3DTSS\_RESULTARG**

Setting to select destination register for the result of this stage, identified by [D3DTA](https://learn.microsoft.com/windows/win32/direct3d9/d3dta). This value can be set to D3DTA\_CURRENT (the default value) or to D3DTA\_TEMP, which is a single temporary register that can be read into subsequent stages as an input argument. The final color passed to the fog blender and frame buffer is taken from D3DTA\_CURRENT, so the last active texture stage state must be set to write to current. This setting is supported if the D3DPMISCCAPS\_TSSARGTEMP device capability is present.

**D3DTSS\_CONSTANT**

Per-stage constant color. To see if a device supports a per-stage constant color, see the D3DPMISCCAPS\_PERSTAGECONSTANT constant in [D3DPMISCCAPS](https://learn.microsoft.com/windows/win32/direct3d9/d3dpmisccaps). D3DTSS\_CONSTANT is used by D3DTA\_CONSTANT. See [D3DTA](https://learn.microsoft.com/windows/win32/direct3d9/d3dta).

**D3DTSS\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Members of this enumerated type are used with the [**IDirect3DDevice9::GetTextureStageState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-gettexturestagestate) and [**IDirect3DDevice9::SetTextureStageState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexturestagestate) methods to retrieve and set texture state values.

The valid range of values for the D3DTSS\_BUMPENVMAT00, D3DTSS\_BUMPENVMAT01, D3DTSS\_BUMPENVMAT10, and D3DTSS\_BUMPENVMAT11 bump-mapping matrix coefficients is greater than or equal to -8.0 and less than 8.0. This range, expressed in mathematical notation is (-8.0,8.0).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**IDirect3DDevice9::GetTextureStageState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-gettexturestagestate)

[**IDirect3DDevice9::SetTextureStageState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexturestagestate)

