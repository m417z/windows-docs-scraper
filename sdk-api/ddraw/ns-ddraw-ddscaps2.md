## Description

The DDSCAPS2 structure defines additional capabilities of a Microsoft DirectDraw surface object.

## Members

### `dwCaps`

Specifies a set of flags representing the capabilities of the surface. The flags in this member are identical to those in the corresponding member of the [**DDSCAPS**](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddscaps) structure.

### `dwCaps2`

Specifies a set of flags that indicate additional surface capabilities. This member can contain one or more of the following capability flags. Each of these flags, except DDSCAPS2\_TEXTUREMANAGE, are set by the application when the application calls its **CreateSurface** method.

| Flag | Meaning |
| --- | --- |
| DDSCAPS2_ADDITIONALPRIMARY | **Microsoft DirectX 9.0 and later versions only.**<br><br>Indicates that subordinate heads of a multiple-head card are no longer in control of their video memory after surfaces are created for those subordinate heads with this bit set. Once such surfaces are destroyed, subordinate heads regain control of their memory. For more information, see [Managing Multiple-Head Memory](https://learn.microsoft.com/windows-hardware/drivers/display/managing-multiple-head-memory). |
| DDSCAPS2_COMMANDBUFFER | Marks a command buffer, used by Microsoft Direct3D to batch commands. |
| DDSCAPS2_CUBEMAP | This surface is a cubic environment map. When using this flag, also specify the face or faces of the cubic environment map to create. |
| DDSCAPS2_CUBEMAP_POSITIVEX | This flag is used with the DDSCAPS2_CUBEMAP flag to create the positive X face of a cubic environment map. |
| DDSCAPS2_CUBEMAP_NEGATIVEX | This flag is used with the DDSCAPS2_CUBEMAP flag to create the negative X face of a cubic environment map. |
| DDSCAPS2_CUBEMAP_POSITIVEY | This flag is used with the DDSCAPS2_CUBEMAP flag to create the positive Y face of a cubic environment map. |
| DDSCAPS2_CUBEMAP_NEGATIVEY | This flag is used with the DDSCAPS2_CUBEMAP flag to create the negative Y face of a cubic environment map. |
| DDSCAPS2_CUBEMAP_POSITIVEZ | This flag is used with the DDSCAPS2_CUBEMAP flag to create the positive Z face of a cubic environment map. |
| DDSCAPS2_CUBEMAP_NEGATIVEZ | This flag is used with the DDSCAPS2_CUBEMAP flag to create the negative Z face of a cubic environment map. |
| DDSCAPS2_CUBEMAP_ALLFACES | This flag is used with the DDSCAPS2_CUBEMAP flag to create all six faces of a cubic environment map. |
| DDSCAPS2_D3DTEXTUREMANAGE | The texture is always managed by Direct3D. |
| DDSCAPS2_DISCARDBACKBUFFER | **DirectX 8.0 and later versions only.**<br><br>Indicates that preservation of the back buffer is not required. It will be set on the primary surface and the back buffers if the application has set D3DSWAPEFFECT_DISCARD on the Present API. **DirectX 9.0 and later versions only.** Indicates that preservation of the depth-stencil surface is not required. |
| DDSCAPS2_DONOTPERSIST | The managed surface can be safely lost. |
| DDSCAPS2_ENABLEALPHACHANNEL | **DirectX 8.1 and later versions only.**<br><br>Indicates to create surfaces that are part of a primary flipping chain or that are on stand-alone back buffers. This flag turns on the alpha channel. For more information, see [Enabling Alpha Channels On Full-Screen Back Buffers](https://learn.microsoft.com/windows-hardware/drivers/display/enabling-alpha-channels-on-full-screen-back-buffers). |
| DDSCAPS2_EXTENDEDFORMATPRIMARY | **DirectX 9.0 and later versions only.**<br><br>Indicates to create a dummy primary surface for use with a nonstandard display mode. For more information, see [Switching Between Standard and Nonstandard Modes](https://learn.microsoft.com/windows-hardware/drivers/display/switching-between-standard-and-nonstandard-modes). |
| DDSCAPS2_HARDWAREDEINTERLACE | The driver must convert the interlaced signal to progressive frames. The DDSCAPS_VIDEOPORT and DDSCAPS_OVERLAY flags in this structure must also be set. |
| DDSCAPS2_HINTANTIALIASING | The application will use antialiasing. This flag is valid only if the DDSCAPS_3DDEVICE flag is also set. |
| DDSCAPS2_HINTDYNAMIC | The application will be updating the surface frequently. Surfaces with this flag set must also have the DDSCAPS_TEXTURE flag in this structure set. This flag cannot be used with the DDSCAPS2_HINTSTATIC or DDSCAPS2_OPAQUE flags. |
| DDSCAPS2_HINTSTATIC | The application will be updating the surface infrequently, but still requires access. Surfaces with this flag set must also have the DDSCAPS_TEXTURE flag in this structure set. This flag cannot be used with the DDSCAPS2_HINTDYNAMIC or DDSCAPS2_OPAQUE flags. |
| DDSCAPS2_INDEXBUFFER | **DirectX 8.0 and later versions only.**<br><br>Marks an index buffer, created and controlled by the application. |
| DDSCAPS2_MIPMAPSUBLEVEL | It enables easier use of **GetAttachedSurface**, rather than **EnumAttachedSurfaces**, for surface constructs such as cube maps, in which there is more than one mipmap surface attached to the root surface. This should be set on all nontop-level surfaces in a mipmapped cube map so that a call to **GetAttachedSurface** can distinguish between top-level faces and attached mipmap levels. This capability bit is ignored by **CreateSurface**. |
| DDSCAPS2_NOTUSERLOCKABLE | **DirectX 8.0 and later versions only.**<br><br>Set on the primary and the back buffers if the flipping chain is not lockable, or on any render target that is not lockable. This allows drivers to do behind the scenes optimization. Note that it is still possible to lock the surfaces so the driver must handle these cases, but such locks are infrequent and are not expected to be fast. The driver can also determine whether the depth/stencil buffer is lockable by the presence of this flag. |
| DDSCAPS2_NPATCHES | **DirectX 8.0 and later versions only.**<br><br>Indicates that the vertex buffer data can be used to render n-patches. |
| DDSCAPS2_OPAQUE | The application will never lock, blit, or update the surface for the rest of that surface's lifetime. The driver can compress or reorder the surface without ever having to decompress it. Surfaces with this flag set must also have the DDSCAPS_TEXTURE flag in this structure set. This flag cannot be used with the DDSCAPS2_HINTDYNAMIC or DDSCAPS2_HINTSTATIC flags. |
| DDSCAPS2_POINTS | **DirectX 8.0 and later versions only.**<br><br>Indicates that the vertex buffer data can be used to render points and point sprites. |
| DDSCAPS2_RTPATCHES | **DirectX 8.0 and later versions only.**<br><br>Indicates that the vertex buffer data can be used to render rt-patches. |
| DDSCAPS2_STEREOSURFACELEFT | This surface is part of a stereo flipping chain. When this flag is set during a **CreateSurface** call, a pair of stereo surfaces are created for each buffer in the primary flipping chain. You must create a complex flipping chain (with back buffers). You cannot create a single set of stereo surfaces. The **Flip** method requires back buffers, so at least 4 surfaces must be created.<br><br>In addition, when this flag is set in a [**DDSURFACEDESC**](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structure as the result of an **EnumDisplayModes** or **GetDisplayMode** call, it indicates support for stereo in that mode. |
| DDSCAPS2_TEXTUREMANAGE | The client indicates that this texture surface should be managed by the driver if possible; otherwise it is managed by Direct3D Immediate Mode. This flag can be used only for texture surfaces (DDSCAPS_TEXTURE flag set in the **dwCaps** member). For more information, see Automatic Texture Management in the Direct3D Immediate Mode documentation. |
| DDSCAPS2_VERTEXBUFFER | Marks an explicit vertex buffer, created and controlled by the application. |
| DDSCAPS2_VOLUME | **DirectX 8.0 and later versions only.**<br><br>This flag is set if the texture has depth in addition to width and height. |

### `dwCaps3`

**DirectX 8.0 and DirectX 8.1 versions only.**

Specifies the number of samples for a multisampled surface. This field holds one of the values of the enumerated type D3DMULTISAMPLE\_TYPE. If a surface is not multisampled, **dwCaps3** has the value D3DMULTISAMPLE\_NONE (0).

**DirectX 9.0 and later versions only.**

Specifies a set of bits that indicate additional surface capabilities. This member can be a bitwise OR of the following bits.

| Bits | Meaning |
| --- | --- |
| Bits in the DDSCAPS3_MULTISAMPLE_MASK mask (0x0000001FL). | The first five bits of **dwCaps3** indicate the number of samples for a multiple-sampled surface. The number of samples can be specified using one of the values of the enumerated type D3DMULTISAMPLE_TYPE. If a surface is not multisampled, this value is D3DMULTISAMPLE_NONE (0). |
| Bits in the DDSCAPS3_MULTISAMPLE_QUALITY_MASK mask (0x000000E0L). | The next three bits of **dwCaps3** indicate the quality level of rendering samples in a multiple-sampled surface. The quality level must be a number from 0 to 7 that represents a quality level from 1 to 8 respectively. Note that even if a surface is not multisampled (specified in the first five bits using D3DMULTISAMPLE_NONE) it can still have a greater-than-1 quality level (specified using a number greater than 0). |
| DDSCAPS3_RESERVED1 (0x00000100L) | Reserved |
| DDSCAPS3_VIDEO (0x00000200L) | Indicates that the render target contains video data. Note that several render targets can be created with this flag, and if two or more of these render targets belong to the same Direct3D context, then the driver determines that these render targets all display the same video stream regardless of whether the render target surfaces are attached to each other. |
| DDSCAPS3_LIGHTWEIGHTMIPMAP (0x00000400L) | Indicates whether this surface has lightweight mip levels |
| DDSCAPS3_AUTOGENMIPMAP (0x00000800L) | Indicates that the mip sublevels for this surface are automatically generated. |
| DDSCAPS3_DMAP (0x00001000L) | Indicates a displacement-map texture that can be sampled by the displacement-map sampler in the tessellation unit. |

### `DUMMYUNIONNAMEN`

N/A

### `DUMMYUNIONNAMEN.dwCaps4`

The low word is the depth for a volume texture.

### `DUMMYUNIONNAMEN.dwVolumeDepth`

Specifies the volume texture bit-depth.

## Remarks

This structure is used by the driver to report the types of surfaces the driver supports. It is also filled in by an application to specify the type of surface to be created.

## See also