## Description

Represents the capabilities of the hardware exposed through the Direct3D object.

## Members

### `DeviceType`

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Member of the [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype) enumerated type, which identifies what type of resources are used for processing vertices.

### `AdapterOrdinal`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Adapter on which this Direct3D device was created. This ordinal is valid only to pass to methods of the [IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9) interface that created this Direct3D device. The **IDirect3D9** interface can always be retrieved by calling [GetDirect3D](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getdirect3d).

### `Caps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The following driver-specific capability.

| Value | Meaning |
| --- | --- |
| **D3DCAPS_READ_SCANLINE** | Display hardware is capable of returning the current scan line. |
| **D3DCAPS_OVERLAY** | The display driver supports an overlay DDI that allows for verification of overlay capabilities. For more information about the overlay DDI, see [Overlay DDI](https://www.microsoft.com/?ref=go).<br><br>|  | | --- | | Differences between Direct3D 9 and Direct3D 9Ex:<br><br>This flag is available in Direct3D 9Ex only. | |

### `Caps2`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Driver-specific capabilities identified in [D3DCAPS2](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcaps2).

### `Caps3`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Driver-specific capabilities identified in [D3DCAPS3](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcaps3).

### `PresentationIntervals`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bit mask of values representing what presentation swap intervals are available.

| Value | Meaning |
| --- | --- |
| **D3DPRESENT_INTERVAL_IMMEDIATE** | The driver supports an immediate presentation swap interval. |
| **D3DPRESENT_INTERVAL_ONE** | The driver supports a presentation swap interval of every screen refresh. |
| **D3DPRESENT_INTERVAL_TWO** | The driver supports a presentation swap interval of every second screen refresh. |
| **D3DPRESENT_INTERVAL_THREE** | The driver supports a presentation swap interval of every third screen refresh. |
| **D3DPRESENT_INTERVAL_FOUR** | The driver supports a presentation swap interval of every fourth screen refresh. |

### `CursorCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bit mask indicating what hardware support is available for cursors. Direct3D 9 does not define alpha-blending cursor capabilities.

| Value | Meaning |
| --- | --- |
| **D3DCURSORCAPS_COLOR** | A full-color cursor is supported in hardware. Specifically, this flag indicates that the driver supports at least a hardware color cursor in high-resolution modes (with scan lines greater than or equal to 400). |
| **D3DCURSORCAPS_LOWRES** | A full-color cursor is supported in hardware. Specifically, this flag indicates that the driver supports a hardware color cursor in both high-resolution and low-resolution modes (with scan lines less than 400). |

### `DevCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags identifying the capabilities of the device.

| Value | Meaning |
| --- | --- |
| **D3DDEVCAPS_CANBLTSYSTONONLOCAL** | Device supports blits from system-memory textures to nonlocal video-memory textures. |
| **D3DDEVCAPS_CANRENDERAFTERFLIP** | Device can queue rendering commands after a page flip. Applications do not change their behavior if this flag is set; this capability means that the device is relatively fast. |
| **D3DDEVCAPS_DRAWPRIMITIVES2** | Device can support at least a DirectX 5-compliant driver. |
| **D3DDEVCAPS_DRAWPRIMITIVES2EX** | Device can support at least a DirectX 7-compliant driver. |
| **D3DDEVCAPS_DRAWPRIMTLVERTEX** | Device exports an [IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive)-aware hal. |
| **D3DDEVCAPS_EXECUTESYSTEMMEMORY** | Device can use execute buffers from system memory. |
| **D3DDEVCAPS_EXECUTEVIDEOMEMORY** | Device can use execute buffers from video memory. |
| **D3DDEVCAPS_HWRASTERIZATION** | Device has hardware acceleration for scene rasterization. |
| **D3DDEVCAPS_HWTRANSFORMANDLIGHT** | Device can support transformation and lighting in hardware. |
| **D3DDEVCAPS_NPATCHES** | Device supports N patches. |
| **D3DDEVCAPS_PUREDEVICE** | Device can support rasterization, transform, lighting, and shading in hardware. |
| **D3DDEVCAPS_QUINTICRTPATCHES** | Device supports quintic Bézier curves and B-splines. |
| **D3DDEVCAPS_RTPATCHES** | Device supports rectangular and triangular patches. |
| **D3DDEVCAPS_RTPATCHHANDLEZERO** | When this device capability is set, the hardware architecture does not require caching of any information, and uncached patches (handle zero) will be drawn as efficiently as cached ones. Note that setting D3DDEVCAPS_RTPATCHHANDLEZERO does not mean that a patch with handle zero can be drawn. A handle-zero patch can always be drawn whether this cap is set or not. |
| **D3DDEVCAPS_SEPARATETEXTUREMEMORIES** | Device is texturing from separate memory pools. |
| **D3DDEVCAPS_TEXTURENONLOCALVIDMEM** | Device can retrieve textures from non-local video memory. |
| **D3DDEVCAPS_TEXTURESYSTEMMEMORY** | Device can retrieve textures from system memory. |
| **D3DDEVCAPS_TEXTUREVIDEOMEMORY** | Device can retrieve textures from device memory. |
| **D3DDEVCAPS_TLVERTEXSYSTEMMEMORY** | Device can use buffers from system memory for transformed and lit vertices. |
| **D3DDEVCAPS_TLVERTEXVIDEOMEMORY** | Device can use buffers from video memory for transformed and lit vertices. |

### `PrimitiveMiscCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Miscellaneous driver primitive capabilities. See [D3DPMISCCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpmisccaps).

### `RasterCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Information on raster-drawing capabilities. This member can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **D3DPRASTERCAPS_ANISOTROPY** | Device supports anisotropic filtering. |
| **D3DPRASTERCAPS_COLORPERSPECTIVE** | Device iterates colors perspective correctly. |
| **D3DPRASTERCAPS_DITHER** | Device can dither to improve color resolution. |
| **D3DPRASTERCAPS_DEPTHBIAS** | Device supports legacy depth bias. For true depth bias, see D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS. |
| **D3DPRASTERCAPS_FOGRANGE** | Device supports range-based fog. In range-based fog, the distance of an object from the viewer is used to compute fog effects, not the depth of the object (that is, the z-coordinate) in the scene. |
| **D3DPRASTERCAPS_FOGTABLE** | Device calculates the fog value by referring to a lookup table containing fog values that are indexed to the depth of a given pixel. |
| **D3DPRASTERCAPS_FOGVERTEX** | Device calculates the fog value during the lighting operation and interpolates the fog value during rasterization. |
| **D3DPRASTERCAPS_MIPMAPLODBIAS** | Device supports level-of-detail bias adjustments. These bias adjustments enable an application to make a mipmap appear crisper or less sharp than it normally would. For more information about level-of-detail bias in mipmaps, see D3DSAMP_MIPMAPLODBIAS. |
| **D3DPRASTERCAPS_MULTISAMPLE_TOGGLE** | Device supports toggling multisampling on and off between [IDirect3DDevice9::BeginScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-beginscene) and [IDirect3DDevice9::EndScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endscene) (using D3DRS_MULTISAMPLEANTIALIAS). |
| **D3DPRASTERCAPS_SCISSORTEST** | Device supports scissor test. See [Scissor Test (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/scissor-test). |
| **D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS** | Device performs true slope-scale based depth bias. This is in contrast to the legacy style depth bias. |
| **D3DPRASTERCAPS_WBUFFER** | Device supports depth buffering using w. |
| **D3DPRASTERCAPS_WFOG** | Device supports w-based fog. W-based fog is used when a perspective projection matrix is specified, but affine projections still use z-based fog. The system considers a projection matrix that contains a nonzero value in the [3][4] element to be a perspective projection matrix. |
| **D3DPRASTERCAPS_ZBUFFERLESSHSR** | Device can perform hidden-surface removal (HSR) without requiring the application to sort polygons and without requiring the allocation of a depth-buffer. This leaves more video memory for textures. The method used to perform HSR is hardware-dependent and is transparent to the application.<br><br>Z-bufferless HSR is performed if no depth-buffer surface is associated with the rendering-target surface and the depth-buffer comparison test is enabled (that is, when the state value associated with the [D3DRS_ZENABLE](https://learn.microsoft.com/windows/desktop/direct3d9/d3drenderstatetype) enumeration constant is set to **TRUE**). |
| **D3DPRASTERCAPS_ZFOG** | Device supports z-based fog. |
| **D3DPRASTERCAPS_ZTEST** | Device can perform z-test operations. This effectively renders a primitive and indicates whether any z pixels have been rendered. |

### `ZCmpCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Z-buffer comparison capabilities. This member can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **D3DPCMPCAPS_ALWAYS** | Always pass the z-test. |
| **D3DPCMPCAPS_EQUAL** | Pass the z-test if the new z equals the current z. |
| **D3DPCMPCAPS_GREATER** | Pass the z-test if the new z is greater than the current z. |
| **D3DPCMPCAPS_GREATEREQUAL** | Pass the z-test if the new z is greater than or equal to the current z. |
| **D3DPCMPCAPS_LESS** | Pass the z-test if the new z is less than the current z. |
| **D3DPCMPCAPS_LESSEQUAL** | Pass the z-test if the new z is less than or equal to the current z. |
| **D3DPCMPCAPS_NEVER** | Always fail the z-test. |
| **D3DPCMPCAPS_NOTEQUAL** | Pass the z-test if the new z does not equal the current z. |

### `SrcBlendCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Source-blending capabilities. This member can be one or more of the following flags. (The RGBA values of the source and destination are indicated by the subscripts s and d.)

| Value | Meaning |
| --- | --- |
| **D3DPBLENDCAPS_BLENDFACTOR** | The driver supports both D3DBLEND_BLENDFACTOR and D3DBLEND_INVBLENDFACTOR. See [D3DBLEND](https://learn.microsoft.com/windows/desktop/direct3d9/d3dblend). |
| **D3DPBLENDCAPS_BOTHINVSRCALPHA** | Source blend factor is (1 - Aₛ, 1 - Aₛ, 1 - Aₛ, 1 - Aₛ) and destination blend factor is (Aₛ, Aₛ, Aₛ, Aₛ); the destination blend selection is overridden. |
| **D3DPBLENDCAPS_BOTHSRCALPHA** | The driver supports the D3DBLEND_BOTHSRCALPHA blend mode. (This blend mode is obsolete. For more information, see D3DBLEND.) |
| **D3DPBLENDCAPS_DESTALPHA** | Blend factor is (Ad, Ad, Ad, Ad). |
| **D3DPBLENDCAPS_DESTCOLOR** | Blend factor is (Rd, Gd, Bd, Ad). |
| **D3DPBLENDCAPS_INVDESTALPHA** | Blend factor is (1 - Ad, 1 - Ad, 1 - Ad, 1 - Ad). |
| **D3DPBLENDCAPS_INVDESTCOLOR** | Blend factor is (1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad). |
| **D3DPBLENDCAPS_INVSRCALPHA** | Blend factor is (1 - Aₛ, 1 - Aₛ, 1 - Aₛ, 1 - Aₛ). |
| **D3DPBLENDCAPS_INVSRCCOLOR** | Blend factor is (1 - Rₛ, 1 - Gₛ, 1 - Bₛ, 1 - Aₛ). |
| **D3DPBLENDCAPS_INVSRCCOLOR2** | Blend factor is (1 - PSOutColor[1]r, 1 - PSOutColor[1]g, 1 - PSOutColor[1]b, not used)). See [Render Target Blending](https://learn.microsoft.com/windows/desktop/direct3d9/d3dblend).<br><br>|  | | --- | | Differences between Direct3D 9 and Direct3D 9Ex:<br><br>This flag is available in Direct3D 9Ex only. | |
| **D3DPBLENDCAPS_ONE** | Blend factor is (1, 1, 1, 1). |
| **D3DPBLENDCAPS_SRCALPHA** | Blend factor is (Aₛ, Aₛ, Aₛ, Aₛ). |
| **D3DPBLENDCAPS_SRCALPHASAT** | Blend factor is (f, f, f, 1); f = min(Aₛ, 1 - Ad). |
| **D3DPBLENDCAPS_SRCCOLOR** | Blend factor is (Rₛ, Gₛ, Bₛ, Aₛ). |
| **D3DPBLENDCAPS_SRCCOLOR2** | Blend factor is (PSOutColor[1]r, PSOutColor[1]g, PSOutColor[1]b, not used). See [Render Target Blending](https://learn.microsoft.com/windows/desktop/direct3d9/d3dblend).<br><br>|  | | --- | | Differences between Direct3D 9 and Direct3D 9Ex:<br><br>This flag is available in Direct3D 9Ex only. | |
| **D3DPBLENDCAPS_ZERO** | Blend factor is (0, 0, 0, 0). |

### `DestBlendCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Destination-blending capabilities. This member can be the same capabilities that are defined for the SrcBlendCaps member.

### `AlphaCmpCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Alpha-test comparison capabilities. This member can include the same capability flags defined for the ZCmpCaps member. If this member contains only the D3DPCMPCAPS_ALWAYS capability or only the D3DPCMPCAPS_NEVER capability, the driver does not support alpha tests. Otherwise, the flags identify the individual comparisons that are supported for alpha testing.

### `ShadeCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shading operations capabilities. It is assumed, in general, that if a device supports a given command at all, it supports the D3DSHADE_FLAT mode (as specified in the [D3DSHADEMODE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dshademode) enumerated type). This flag specifies whether the driver can also support Gouraud shading and whether alpha color components are supported. When alpha components are not supported, the alpha value of colors generated is implicitly 255. This is the maximum possible alpha (that is, the alpha component is at full intensity).

The color, specular highlights, fog, and alpha interpolants of a triangle each have capability flags that an application can use to find out how they are implemented by the device driver.

This member can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **D3DPSHADECAPS_ALPHAGOURAUDBLEND** | Device can support an alpha component for Gouraud-blended transparency (the D3DSHADE_GOURAUD state for the D3DSHADEMODE enumerated type). In this mode, the alpha color component of a primitive is provided at vertices and interpolated across a face along with the other color components. |
| **D3DPSHADECAPS_COLORGOURAUDRGB** | Device can support colored Gouraud shading. In this mode, the per-vertex color components (red, green, and blue) are interpolated across a triangle face. |
| **D3DPSHADECAPS_FOGGOURAUD** | Device can support fog in the Gouraud shading mode. |
| **D3DPSHADECAPS_SPECULARGOURAUDRGB** | Device supports Gouraud shading of specular highlights. |

### `TextureCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Miscellaneous texture-mapping capabilities. This member can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **D3DPTEXTURECAPS_ALPHA** | Alpha in texture pixels is supported. |
| **D3DPTEXTURECAPS_ALPHAPALETTE** | Device can draw alpha from texture palettes. |
| **D3DPTEXTURECAPS_CUBEMAP** | Supports cube textures. |
| **D3DPTEXTURECAPS_CUBEMAP_POW2** | Device requires that cube texture maps have dimensions specified as powers of two. |
| **D3DPTEXTURECAPS_MIPCUBEMAP** | Device supports mipmapped cube textures. |
| **D3DPTEXTURECAPS_MIPMAP** | Device supports mipmapped textures. |
| **D3DPTEXTURECAPS_MIPVOLUMEMAP** | Device supports mipmapped volume textures. |
| **D3DPTEXTURECAPS_NONPOW2CONDITIONAL** | D3DPTEXTURECAPS_POW2 is also set, conditionally supports the use of 2D textures with dimensions that are not powers of two. A device that exposes this capability can use such a texture if all of the following requirements are met.<br><br>* The texture addressing mode for the texture stage is set to D3DTADDRESS_CLAMP.<br>* Texture wrapping for the texture stage is disabled ([D3DRS_WRAP](https://learn.microsoft.com/windows/desktop/direct3d9/d3drenderstatetype) n set to 0).<br>* Mipmapping is not in use (use magnification filter only).<br>* Texture formats must not be [D3DFMT_DXT1](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) through D3DFMT_DXT5.<br><br>If this flag is not set, and D3DPTEXTURECAPS_POW2 is also not set, then unconditional support is provided for 2D textures with dimensions that are not powers of two.<br><br>A texture that is not a power of two cannot be set at a stage that will be read based on a shader computation (such as the [bem - ps](https://learn.microsoft.com/windows/desktop/direct3dhlsl/bem---ps) and [texm3x3 - ps](https://learn.microsoft.com/windows/desktop/direct3dhlsl/texm3x3---ps) instructions in pixel shaders versions 1_0 to 1_3). For example, these textures can be used to store bumps that will be fed into texture reads, but not the environment maps that are used in [texbem - ps](https://learn.microsoft.com/windows/desktop/direct3dhlsl/texbem---ps), [texbeml - ps](https://learn.microsoft.com/windows/desktop/direct3dhlsl/texbeml---ps), and [texm3x3spec - ps](https://learn.microsoft.com/windows/desktop/direct3dhlsl/texm3x3spec---ps). This means that a texture with dimensions that are not powers of two cannot be addressed or sampled using texture coordinates computed within the shader. This type of operation is known as a dependent read and cannot be performed on these types of textures. |
| **D3DPTEXTURECAPS_NOPROJECTEDBUMPENV** | Device does not support a projected bump-environment lookup operation in programmable and fixed function shaders. |
| **D3DPTEXTURECAPS_PERSPECTIVE** | Perspective correction texturing is supported. |
| **D3DPTEXTURECAPS_POW2** | If D3DPTEXTURECAPS_NONPOW2CONDITIONAL is not set, all textures must have widths and heights specified as powers of two. This requirement does not apply to either cube textures or volume textures.<br><br>If D3DPTEXTURECAPS_NONPOW2CONDITIONAL is also set, conditionally supports the use of 2D textures with dimensions that are not powers of two. See D3DPTEXTURECAPS_NONPOW2CONDITIONAL description.<br><br>If this flag is not set, and D3DPTEXTURECAPS_NONPOW2CONDITIONAL is also not set, then unconditional support is provided for 2D textures with dimensions that are not powers of two. |
| **D3DPTEXTURECAPS_PROJECTED** | Supports the D3DTTFF_PROJECTED texture transformation flag. When applied, the device divides transformed texture coordinates by the last texture coordinate. If this capability is present, then the projective divide occurs per pixel. If this capability is not present, but the projective divide needs to occur anyway, then it is performed on a per-vertex basis by the Direct3D runtime. |
| **D3DPTEXTURECAPS_SQUAREONLY** | All textures must be square. |
| **D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE** | Texture indices are not scaled by the texture size prior to interpolation. |
| **D3DPTEXTURECAPS_VOLUMEMAP** | Device supports volume textures. |
| **D3DPTEXTURECAPS_VOLUMEMAP_POW2** | Device requires that volume texture maps have dimensions specified as powers of two. |

### `TextureFilterCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture-filtering capabilities for a texture. Per-stage filtering capabilities reflect which filtering modes are supported for texture stages when performing multiple-texture blending. This member can be any combination of the per-stage texture-filtering flags defined in [D3DPTFILTERCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dptfiltercaps).

### `CubeTextureFilterCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture-filtering capabilities for a cube texture. Per-stage filtering capabilities reflect which filtering modes are supported for texture stages when performing multiple-texture blending. This member can be any combination of the per-stage texture-filtering flags defined in [D3DPTFILTERCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dptfiltercaps).

### `VolumeTextureFilterCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture-filtering capabilities for a volume texture. Per-stage filtering capabilities reflect which filtering modes are supported for texture stages when performing multiple-texture blending. This member can be any combination of the per-stage texture-filtering flags defined in [D3DPTFILTERCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dptfiltercaps).

### `TextureAddressCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture-addressing capabilities for texture objects. This member can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **D3DPTADDRESSCAPS_BORDER** | Device supports setting coordinates outside the range [0.0, 1.0] to the border color, as specified by the D3DSAMP_BORDERCOLOR texture-stage state. |
| **D3DPTADDRESSCAPS_CLAMP** | Device can clamp textures to addresses. |
| **D3DPTADDRESSCAPS_INDEPENDENTUV** | Device can separate the texture-addressing modes of the u and v coordinates of the texture. This ability corresponds to the D3DSAMP_ADDRESSU and D3DSAMP_ADDRESSV render-state values. |
| **D3DPTADDRESSCAPS_MIRROR** | Device can mirror textures to addresses. |
| **D3DPTADDRESSCAPS_MIRRORONCE** | Device can take the absolute value of the texture coordinate (thus, mirroring around 0) and then clamp to the maximum value. |
| **D3DPTADDRESSCAPS_WRAP** | Device can wrap textures to addresses. |

### `VolumeTextureAddressCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture-addressing capabilities for a volume texture. This member can be one or more of the flags defined for the TextureAddressCaps member.

### `LineCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Defines the capabilities for line-drawing primitives.

| Value | Meaning |
| --- | --- |
| **D3DLINECAPS_ALPHACMP** | Supports alpha-test comparisons. |
| **D3DLINECAPS_ANTIALIAS** | Antialiased lines are supported. |
| **D3DLINECAPS_BLEND** | Supports source-blending. |
| **D3DLINECAPS_FOG** | Supports fog. |
| **D3DLINECAPS_TEXTURE** | Supports texture-mapping. |
| **D3DLINECAPS_ZTEST** | Supports z-buffer comparisons. |

### `MaxTextureWidth`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum texture width for this device.

### `MaxTextureHeight`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum texture height for this device.

### `MaxVolumeExtent`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum value for any of the three dimensions (width, height, and depth) of a volume texture.

### `MaxTextureRepeat`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This number represents the maximum range of the integer bits of the post-normalized texture coordinates. A texture coordinate is stored as a 32-bit signed integer using 27 bits to store the integer part and 5 bits for the floating point fraction. The maximum integer index, 2²⁷, is used to determine the maximum texture coordinate, depending on how the hardware does texture-coordinate scaling.

Some hardware reports the cap D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE. For this case, the device defers scaling texture coordinates by the texture size until after interpolation and application of the texture address mode, so the number of times a texture can be wrapped is given by the integer value in MaxTextureRepeat.

Less desirably, on some hardware D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE is not set and the device scales the texture coordinates by the texture size (using the highest level of detail) prior to interpolation. This limits the number of times a texture can be wrapped to MaxTextureRepeat / texture size.

For example, assume that MaxTextureRepeat is equal to 32k and the size of the texture is 4k. If the hardware sets D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE, then the number of times a texture can be wrapped is equal to MaxTextureRepeat, which is 32k in this example. Otherwise, the number of times a texture can be wrapped is equal to MaxTextureRepeat divided by texture size, which is 32k/4k in this example.

### `MaxTextureAspectRatio`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum texture aspect ratio supported by the hardware, typically a power of 2.

### `MaxAnisotropy`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum valid value for the D3DSAMP_MAXANISOTROPY texture-stage state.

### `MaxVertexW`

Type: **float**

Maximum W-based depth value that the device supports.

### `GuardBandLeft`

Type: **float**

Screen-space coordinate of the guard-band clipping region. Coordinates inside this rectangle but outside the viewport rectangle are automatically clipped.

### `GuardBandTop`

Type: **float**

Screen-space coordinate of the guard-band clipping region. Coordinates inside this rectangle but outside the viewport rectangle are automatically clipped.

### `GuardBandRight`

Type: **float**

Screen-space coordinate of the guard-band clipping region. Coordinates inside this rectangle but outside the viewport rectangle are automatically clipped.

### `GuardBandBottom`

Type: **float**

Screen-space coordinate of the guard-band clipping region. Coordinates inside this rectangle but outside the viewport rectangle are automatically clipped.

### `ExtentsAdjust`

Type: **float**

Number of pixels to adjust the extents rectangle outward to accommodate antialiasing kernels.

### `StencilCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags specifying supported stencil-buffer operations. Stencil operations are assumed to be valid for all three stencil-buffer operation render states (D3DRS_STENCILFAIL, D3DRS_STENCILPASS, and D3DRS_STENCILZFAIL).

For more information, see [D3DSTENCILCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dstencilcaps).

### `FVFCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flexible vertex format capabilities.

| Value | Meaning |
| --- | --- |
| **D3DFVFCAPS_DONOTSTRIPELEMENTS** | It is preferable that vertex elements not be stripped. That is, if the vertex format contains elements that are not used with the current render states, there is no need to regenerate the vertices. If this capability flag is not present, stripping extraneous elements from the vertex format provides better performance. |
| **D3DFVFCAPS_PSIZE** | Point size is determined by either the render state or the vertex data. If an FVF is used, point size can come from point size data in the vertex declaration. Otherwise, point size is determined by the render state D3DRS_POINTSIZE. If the application provides point size in both (the render state and the vertex declaration), the vertex data overrides the render-state data. |
| **D3DFVFCAPS_TEXCOORDCOUNTMASK** | Masks the low WORD of FVFCaps. These bits, cast to the WORD data type, describe the total number of texture coordinate sets that the device can simultaneously use for multiple texture blending. (You can use up to eight texture coordinate sets for any vertex, but the device can blend using only the specified number of texture coordinate sets.) |

### `TextureOpCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of flags describing the texture operations supported by this device. The following flags are defined.

| Value | Meaning |
| --- | --- |
| **D3DTEXOPCAPS_ADD** | The D3DTOP_ADD texture-blending operation is supported. |
| **D3DTEXOPCAPS_ADDSIGNED** | The D3DTOP_ADDSIGNED texture-blending operation is supported. |
| **D3DTEXOPCAPS_ADDSIGNED2X** | The D3DTOP_ADDSIGNED2X texture-blending operation is supported. |
| **D3DTEXOPCAPS_ADDSMOOTH** | The D3DTOP_ADDSMOOTH texture-blending operation is supported. |
| **D3DTEXOPCAPS_BLENDCURRENTALPHA** | The D3DTOP_BLENDCURRENTALPHA texture-blending operation is supported. |
| **D3DTEXOPCAPS_BLENDDIFFUSEALPHA** | The D3DTOP_BLENDDIFFUSEALPHA texture-blending operation is supported. |
| **D3DTEXOPCAPS_BLENDFACTORALPHA** | The D3DTOP_BLENDFACTORALPHA texture-blending operation is supported. |
| **D3DTEXOPCAPS_BLENDTEXTUREALPHA** | The D3DTOP_BLENDTEXTUREALPHA texture-blending operation is supported. |
| **D3DTEXOPCAPS_BLENDTEXTUREALPHAPM** | The D3DTOP_BLENDTEXTUREALPHAPM texture-blending operation is supported. |
| **D3DTEXOPCAPS_BUMPENVMAP** | The D3DTOP_BUMPENVMAP texture-blending operation is supported. |
| **D3DTEXOPCAPS_BUMPENVMAPLUMINANCE** | The D3DTOP_BUMPENVMAPLUMINANCE texture-blending operation is supported. |
| **D3DTEXOPCAPS_DISABLE** | The D3DTOP_DISABLE texture-blending operation is supported. |
| **D3DTEXOPCAPS_DOTPRODUCT3** | The D3DTOP_DOTPRODUCT3 texture-blending operation is supported. |
| **D3DTEXOPCAPS_LERP** | The D3DTOP_LERP texture-blending operation is supported. |
| **D3DTEXOPCAPS_MODULATE** | The D3DTOP_MODULATE texture-blending operation is supported. |
| **D3DTEXOPCAPS_MODULATE2X** | The D3DTOP_MODULATE2X texture-blending operation is supported. |
| **D3DTEXOPCAPS_MODULATE4X** | The D3DTOP_MODULATE4X texture-blending operation is supported. |
| **D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR** | The D3DTOP_MODULATEALPHA_ADDCOLOR texture-blending operation is supported. |
| **D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA** | The D3DTOP_MODULATECOLOR_ADDALPHA texture-blending operation is supported. |
| **D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR** | The D3DTOP_MODULATEINVALPHA_ADDCOLOR texture-blending operation is supported. |
| **D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA** | The D3DTOP_MODULATEINVCOLOR_ADDALPHA texture-blending operation is supported. |
| **D3DTEXOPCAPS_MULTIPLYADD** | The D3DTOP_MULTIPLYADD texture-blending operation is supported. |
| **D3DTEXOPCAPS_PREMODULATE** | The D3DTOP_PREMODULATE texture-blending operation is supported. |
| **D3DTEXOPCAPS_SELECTARG1** | The D3DTOP_SELECTARG1 texture-blending operation is supported. |
| **D3DTEXOPCAPS_SELECTARG2** | The D3DTOP_SELECTARG2 texture-blending operation is supported. |
| **D3DTEXOPCAPS_SUBTRACT** | The D3DTOP_SUBTRACT texture-blending operation is supported. |

### `MaxTextureBlendStages`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of texture-blending stages supported in the fixed function pipeline. This value is the number of blenders available. In the programmable pixel pipeline, this corresponds to the number of unique texture registers used by pixel shader instructions.

### `MaxSimultaneousTextures`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of textures that can be simultaneously bound to the fixed-function pipeline sampler stages. If the same texture is bound to two sampler stages, it counts as two textures.

This value has no meaning in the programmable pipeline where the number of sampler stages is determined by each pixel shader version. Each pixel shader version also determines the number of texture declaration instructions. See [Pixel Shaders](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-ps).

### `VertexProcessingCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Vertex processing capabilities. For a given physical device, this capability might vary across Direct3D devices depending on the parameters supplied to [CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice). See [D3DVTXPCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvtxpcaps).

### `MaxActiveLights`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of lights that can be active simultaneously. For a given physical device, this capability might vary across Direct3D devices depending on the parameters supplied to [CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice).

### `MaxUserClipPlanes`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of user-defined clipping planes supported. This member can be 0. For a given physical device, this capability may vary across Direct3D devices depending on the parameters supplied to [CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice).

### `MaxVertexBlendMatrices`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of matrices that this device can apply when performing multimatrix vertex blending. For a given physical device, this capability may vary across Direct3D devices depending on the parameters supplied to [CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice).

### `MaxVertexBlendMatrixIndex`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

DWORD value that specifies the maximum matrix index that can be indexed into using the per-vertex indices. The number of matrices is MaxVertexBlendMatrixIndex + 1, which is the size of the matrix palette. If normals are present in the vertex data that needs to be blended for lighting, then the number of matrices is half the number specified by this capability flag. If MaxVertexBlendMatrixIndex is set to zero, the driver does not support indexed vertex blending. If this value is not zero then the valid range of indices is zero through MaxVertexBlendMatrixIndex.

A zero value for MaxVertexBlendMatrixIndex indicates that the driver does not support indexed matrices.

When software vertex processing is used, 256 matrices could be used for indexed vertex blending, with or without normal blending.

For a given physical device, this capability may vary across Direct3D devices depending on the parameters supplied to [CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice).

### `MaxPointSize`

Type: **float**

Maximum size of a point primitive. If set to 1.0f then device does not support point size control. The range is greater than or equal to 1.0f.

### `MaxPrimitiveCount`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of primitives for each [DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive) call. There are two cases:

* If MaxPrimitiveCount is not equal to 0xffff, you can draw at most MaxPrimitiveCount primitives with each draw call.
* However, if MaxPrimitiveCount equals 0xffff, you can still draw at most MaxPrimitiveCount primitive, but you may also use no more than MaxPrimitiveCount unique vertices (since each primitive can potentially use three different vertices).

### `MaxVertexIndex`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum size of indices supported for hardware vertex processing. It is possible to create 32-bit index buffers; however, you will not be able to render with the index buffer unless this value is greater than 0x0000FFFF.

### `MaxStreams`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of concurrent data streams for [SetStreamSource](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setstreamsource). The valid range is 1 to 16. Note that if this value is 0, then the driver is not a Direct3D 9 driver.

### `MaxStreamStride`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum stride for [SetStreamSource](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setstreamsource).

### `VertexShaderVersion`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Two numbers that represent the vertex shader main and sub versions. For more information about the instructions supported for each vertex shader version, see [Version 1_x](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-vs-instructions-vs-1-1), [Version 2_0](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-vs-instructions-vs-2-0), [Version 2_0 Extended](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-vs-instructions-vs-2-x), or [Version 3_0](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-vs-instructions-vs-3-0).

### `MaxVertexShaderConst`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of vertex shader [Vertex Shader Registers](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-vs-registers) that are reserved for constants.

### `PixelShaderVersion`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Two numbers that represent the pixel shader main and sub versions. For more information about the instructions supported for each pixel shader version, see [Version 1_x](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-ps-instructions-ps-1-x), [Version 2_0](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-ps-instructions-ps-2-0), [Version 2_0 Extended](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-ps-instructions-ps-2-x), or [Version 3_0](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx9-graphics-reference-asm-ps-instructions-ps-3-0).

### `PixelShader1xMaxValue`

Type: **float**

Maximum value of pixel shader arithmetic component. This value indicates the internal range of values supported for pixel color blending operations. Within the range that they report to, implementations must allow data to pass through pixel processing unmodified (unclamped). Normally, the value of this member is an absolute value. For example, a 1.0 indicates that the range is -1.0 to 1, and an 8.0 indicates that the range is -8.0 to 8.0. The value must be >= 1.0 for any hardware that supports pixel shaders.

### `DevCaps2`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Device driver capabilities for adaptive tessellation. For more information, see [D3DDEVCAPS2](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevcaps2)

### `MaxNpatchTessellationLevel`

TBD

### `Reserved5`

TBD

### `MasterAdapterOrdinal`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This number indicates which device is the master for this subordinate. This number is taken from the same space as the adapter values.

For multihead support, one head will be denoted the master head, and all other heads on the same card will be denoted subordinate heads. If more than one multihead adapter is present in a system, the master and its subordinates from one multihead adapter are called a group.

### `AdapterOrdinalInGroup`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This number indicates the order in which heads are referenced by the API. The value for the master adapter is always 0. These values do not correspond to the adapter ordinals. They apply only to heads within a group.

### `NumberOfAdaptersInGroup`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of adapters in this adapter group (only if master). This will be 1 for conventional adapters. The value will be greater than 1 for the master adapter of a multihead card. The value will be 0 for a subordinate adapter of a multihead card. Each card can have at most one master, but may have many subordinates.

### `DeclTypes`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of one or more data types contained in a vertex declaration. See [D3DDTCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddtcaps).

### `NumSimultaneousRTs`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of simultaneous render targets. This number must be at least one.

### `StretchRectFilterCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of constants that describe the operations supported by [StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect). The flags that may be set in this field are:

| Constant | Description |
| --- | --- |
| D3DPTFILTERCAPS_MINFPOINT | Device supports point-sample filtering for minifying rectangles. This filter type is requested by calling [StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect) using D3DTEXF_POINT. |
| D3DPTFILTERCAPS_MAGFPOINT | Device supports point-sample filtering for magnifying rectangles. This filter type is requested by calling [StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect) using D3DTEXF_POINT. |
| D3DPTFILTERCAPS_MINFLINEAR | Device supports bilinear interpolation filtering for minifying rectangles. This filter type is requested by calling [StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect) using D3DTEXF_LINEAR. |
| D3DPTFILTERCAPS_MAGFLINEAR | Device supports bilinear interpolation filtering for magnifying rectangles. This filter type is requested by calling [StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect) using D3DTEXF_LINEAR. |

For more information, see [D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype) and **D3DTEXTUREFILTERTYPE**.

### `VS20Caps`

Type: **[D3DVSHADERCAPS2_0](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dvshadercaps2_0)**

Device supports vertex shader version 2_0 extended capability. See [D3DVSHADERCAPS2_0](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dvshadercaps2_0).

### `PS20Caps`

Type: **[D3DPSHADERCAPS2_0](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dpshadercaps2_0)**

Device supports pixel shader version 2_0 extended capability. See [D3DPSHADERCAPS2_0](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dpshadercaps2_0).

### `VertexTextureFilterCaps`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Device supports vertex shader texture filter capability. See [D3DPTFILTERCAPS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dptfiltercaps).

### `MaxVShaderInstructionsExecuted`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of vertex shader instructions that can be run when using flow control. The maximum number of instructions that can be programmed is MaxVertexShader30InstructionSlots.

### `MaxPShaderInstructionsExecuted`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of pixel shader instructions that can be run when using flow control. The maximum number of instructions that can be programmed is MaxPixelShader30InstructionSlots.

### `MaxVertexShader30InstructionSlots`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of vertex shader instruction slots supported. The maximum value that can be set on this cap is 32768. Devices that support vs_3_0 are required to support at least 512 instruction slots.

### `MaxPixelShader30InstructionSlots`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of pixel shader instruction slots supported. The maximum value that can be set on this cap is 32768. Devices that support ps_3_0 are required to support at least 512 instruction slots.

## Remarks

The MaxTextureBlendStages and MaxSimultaneousTextures members might seem similar, but they contain different information. The MaxTextureBlendStages member contains the total number of texture-blending stages supported by the current device, and the MaxSimultaneousTextures member describes how many of those stages can have textures bound to them by using the [SetTexture](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexture) method.

When the driver fills this structure, it can set values for execute-buffer capabilities, even when the interface being used to retrieve the capabilities (such as [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)) does not support execute buffers.

In general, performance problems may occur if you use a texture and then modify it during a scene. Ensure that no texture used in the current [BeginScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-beginscene) and [EndScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endscene) block is evicted unless absolutely necessary. In the case of extremely high texture usage within a scene, the results are undefined. This occurs when you modify a texture that you have used in the scene and there is no spare texture memory available. For such systems, the contents of the z-buffer become invalid at EndScene. Applications should not call [UpdateSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatesurface) to or from the back buffer on this type of hardware inside a BeginScene/EndScene pair. In addition, applications should not try to access the z-buffer if the D3DPRASTERCAPS_ZBUFFERLESSHSR capability flag is set. Finally, applications should not lock the back buffer or the z-buffer inside a BeginScene/EndScene pair.

The following flags concerning mipmapped textures are not supported in Direct3D 9.

* D3DPTFILTERCAPS_LINEAR
* D3DPTFILTERCAPS_LINEARMIPLINEAR
* D3DPTFILTERCAPS_LINEARMIPNEAREST
* D3DPTFILTERCAPS_MIPNEAREST
* D3DPTFILTERCAPS_NEAREST

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/desktop/direct3d9/dx9-graphics-reference-d3d-structures)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getdevicecaps)