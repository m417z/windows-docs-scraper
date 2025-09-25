# _FORMATOP structure

## Description

The **FORMATOP** structure describes a surface format and operations that can be performed with such a surface.

## Members

### `Format` [in]

The [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the surface.

### `Operations` [out]

A valid bitwise **OR** of the following flags that indicate the operations that can be performed on surfaces with the pixel format that is specified in the **Format** member. Some of the following flags imply that other flags should be used. If a driver sets a flag that implies other flags, the driver is not required to set the implied flags, and the Direct3D runtime determines the use of the implied flags.

#### FORMATOP_TEXTURE (0x00000001L)

Surfaces of the specified pixel format can be used as MIP-mapped textures.

#### FORMATOP_VOLUMETEXTURE (0x00000002L)

Surfaces of this format can be used as volume textures. Note that this flag is independent of FORMATOP_TEXTURE. Therefore, a pixel format can be used for volume textures and not for conventional, MIP-mapped textures.

#### FORMATOP_CUBETEXTURE (0x00000004L)

Surfaces of this format can be used as cubic environment map textures. Note that this flag is independent of FORMATOP_TEXTURE. Therefore, a pixel format can be used for cubic environment map textures and not for conventional, MIP-mapped textures.

#### FORMATOP_OFFSCREEN_RENDERTARGET (0x00000008L)

Surfaces of this format can be used as offscreen render targets, regardless of the pixel format of the display mode, if the pixel format of the current display mode was reported with FORMATOP_DISPLAYMODE and FORMATOP_3DACCELERATION. If the pixel format of the current display mode did not have these flags set, no 3-D acceleration is available in this mode even if the render target is offscreen. The FORMATOP_OFFSCREEN_RENDERTARGET flag can be combined with FORMATOP_TEXTURE to indicate that the device can render to textures of the specified pixel format.

The FORMATOP_OFFSCREEN_RENDERTARGET flag also implies the FORMATOP_SAME_FORMAT_RENDERTARGET and FORMATOP_SAME_FORMAT_UP_TO_ALPHA_RENDERTARGET flags.

#### FORMATOP_SAME_FORMAT_RENDERTARGET (0x00000010L)

Surfaces of this format can be used as render targets but only when the pixel format of the surface matches the pixel format of the current display mode. This flag does not apply only to offscreen render targets but can be specified on the pixel formats of display modes to indicate rendering target capability. This flag can be combined with FORMATOP_TEXTURE to indicate that the device can render to textures of the specified pixel format.

The FORMATOP_SAME_FORMAT_RENDERTARGET flag also implies the FORMATOP_SAME_FORMAT_UP_TO_ALPHA_RENDERTARGET flag.

#### FORMATOP_ZSTENCIL (0x00000040L)

Surfaces of this format can be used as Z/stencil buffers but only if the depth of the Z/stencil surface matches the color depth of the rendering target to which the depth buffer is attached. Use the pixel stride when you are deciding on a match between Z/stencil and color buffer depth.

#### FORMATOP_ZSTENCIL_WITH_ARBITRARY_COLOR_DEPTH (0x00000080L)

Surfaces of this format can be used as Z/stencil buffers, regardless of the color depth of the render target to which the surface is attached.

The FORMATOP_ZSTENCIL_WITH_ARBITRARY_COLOR_DEPTH flag also implies the FORMATOP_ZSTENCIL flag.

#### FORMATOP_SAME_FORMAT_UP_TO_ALPHA_RENDERTARGET (0x00000100L)

Surfaces of this format can be used as render targets if the current display mode is the same depth and the alpha channel is ignored. For example, if the device can render to A8R8G8B8 when the display mode is X8R8G8B8, the format operation list entry for A8R8G8B8 should have this flag set.

#### FORMATOP_DISPLAYMODE (0x00000400L)

A display mode with this pixel format that is supported by the driver model (including Flip). This flag should not be set on alpha formats.

#### FORMATOP_3DACCELERATION (0x00000800L)

The graphics accelerator can support some level of Microsoft Direct3D acceleration when in a display mode with this pixel format, and the driver can create a context in this mode (for some render target format). This flag can be used only when reporting display mode formats (by specifying the FORMATOP_DISPLAYMODE). This flag should not be used to report offscreen render targets formats.

#### FORMATOP_PIXELSIZE (0x00001000L)

The driver filled in the bits per pixel for the format in the **PrivateFormatBitCount** member.

If the driver requires that managed surfaces and textures use a private format (a format that can be processed by the driver but not natively by the Direct3D runtime), the driver must specify FORMATOP_PIXELSIZE and the pixel size in **PrivateFormatBitCount**.

#### FORMATOP_CONVERT_TO_ARGB (0x00002000L)

Source surfaces of this format can be converted to any target surface with an RGB pixel format that has the FORMATOP_MEMBEROFGROUP_ARGB flag specified.

#### FORMATOP_OFFSCREENPLAIN (0x00004000L)

The driver can stretch to and from and color fill surfaces of this format.

#### FORMATOP_SRGBREAD (0x00008000L)

Surfaces of this format can be read from as [sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112)-formatted textures (that is, the sampler linearizes the looked-up data).

#### FORMATOP_BUMPMAP (0x00010000L)

Surfaces of this format can be used as bump environment map textures. Note that this flag is independent of FORMATOP_TEXTURE. Therefore, a pixel format can be used for bump environment map textures and not for conventional, MIP-mapped textures.

#### FORMATOP_DMAP (0x00020000L)

The displacement map sampler can sample surfaces of this format.

#### FORMATOP_NOFILTER (0x00040000L)

Surfaces of this format cannot be used with texture filtering.

#### FORMATOP_MEMBEROFGROUP_ARGB (0x00080000L)

Target surfaces of this format can be converted from any source surface with a pixel format that has the FORMATOP_CONVERT_TO_ARGB flag specified. The driver can specify FORMATOP_MEMBEROFGROUP_ARGB only for ARGB surfaces with at least 5 bits of color information for each channel. That is, the D3DDDIFMT_A1R5G5B5 format is valid, but the D3DDDIFMT_A4R4G4B4 format is invalid. If the driver specifies FORMATOP_MEMBEROFGROUP_ARGB with an invalid format, the Direct3D runtime prevents the Direct3D HAL from loading. Note that although this flag indicates ARGB formats, the runtime also allows the driver to specify surfaces with XRGB formats (for example, D3DDDIFMT_X1R5G5B5).

#### FORMATOP_SRGBWRITE (0x00100000L)

Surfaces of this format can be written to as [sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112)-formatted targets (that is, the pixel pipe delinearizes data on output to this format).

#### FORMATOP_NOALPHABLEND (0x00200000L)

Surfaces of this format cannot be used with alpha blending.

#### FORMATOP_AUTOGENMIPMAP (0x00400000L)

The sublevels of MIP-mapped textures with this format can be automatically generated. For the driver to receive calls to its [GenerateMipSubLevels](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_generatemipsublevels) function, this flag must be exposed.

#### FORMATOP_VERTEXTEXTURE (0x00800000L)

A vertex texture sampler can use surfaces of this format. That is, only surfaces of this format can be used as vertex textures.

#### FORMATOP_NOTEXCOORDWRAPNORMIP (0x01000000L)

Surfaces of this format can only be conditionally used for texture mapping of 2-D textures with dimensions that are not powers of 2. For more information, see the definitions for D3DPTEXTURECAPS_POW2 and D3DPTEXTURECAPS_NONPOW2CONDITIONAL in the [D3DPRIMCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dcaps/ns-d3dcaps-_d3dprimcaps) reference page.

#### FORMATOP_PLANAR (0x02000000L)

Surfaces of this format are planar versus packed. The Direct3D runtime must allocate a buffer if it calls the user-mode display driver's [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function on a surface with a planar format while the surface is lost and the typical calculation of pitch multiplied times height is not possible. Most formats are packed except for those that the Microsoft DirectX Video Acceleration uses (for example, YUV formats).

#### FORMATOP_OVERLAY (0x04000000L)

Surfaces of this format are used for overlay operations.

#### FORMATOP_CAPTURE (0x08000000L)

If the **VideoEncoder** member of the [D3DDDI_RESOURCEFLAGS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags2) structure is set, surfaces of this format can be used as capture buffers.

Supported starting with Windows 8.

#### FORMATOP_VIDEO_ENCODER (0x10000000L)

If the **VideoEncoder** member of the [D3DDDI_RESOURCEFLAGS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags2) structure is set, surfaces of this format can be used as video encoder input resources.

Supported starting with Windows 8.

#### FORMATOP_MULTIPLANE_OVERLAY (0x20000000L)

Surfaces of this format support a multiplane overlay.

Supported starting with Windows 8.

### `FlipMsTypes` [out]

A 32-bitmask for full-screen multiple sampling.

### `BltMsTypes` [out]

A 32-bitmask for windowed multiple sampling.

### `PrivateFormatBitCount` [out]

The bits per pixel of a pixel format that is private to the driver (that is, not one of the standard pixel formats that are defined by the [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration type).

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDI_RESOURCEFLAGS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags2)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)