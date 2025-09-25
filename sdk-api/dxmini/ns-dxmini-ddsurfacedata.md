# DDSURFACEDATA structure

## Description

The DDSURFACEDATA structure is used by DirectDraw to represent a surface to the kernel-mode miniport driver.

## Members

### `ddsCaps`

Points to a [DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85)) structure that contains the creation capabilities used to describe the surface.

### `dwSurfaceOffset`

Specifies the byte offset from the beginning of the frame buffer to the start of the surface. This field is used only by the miniport driver.

### `fpLockPtr`

Points to the start of the surface.

### `dwWidth`

Specifies the surface width, in pixels.

### `dwHeight`

Specifies the surface height, in pixels.

### `lPitch`

Specifies the surface pitch, in bytes.

### `dwOverlayFlags`

Indicates a set of flags that specify the current user-mode DDOVER_*Xxx* flags set by [DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay). This member is a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDOVER_ADDDIRTYRECT | Add a dirty rectangle to an emulated overlaid surface. |
| DDOVER_ALPHADEST | Use either the alpha information in pixel format or the alpha channel surface attached to the destination surface as the alpha channel for this overlay. |
| DDOVER_ALPHADESTCONSTOVERRIDE | Use the **dwAlphaDestConst** member of the DDOVERLAYFX structure as the destination alpha channel for this overlay. The DDOVERLAYFX structure is defined in *ddraw.h*. |
| DDOVER_ALPHADESTNEG | The destination surface becomes more transparent as the alpha value increases (0 is opaque). |
| DDOVER_ALPHADESTSURFACEOVERRIDE | Use the **lpDDSAlphaDest** member of the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the alpha channel destination for this overlay. |
| DDOVER_ALPHAEDGEBLEND | Use the **dwAlphaEdgeBlend** member of the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the alpha channel for the edges of the image that border the color key colors. |
| DDOVER_ALPHASRC | Use either the alpha information in pixel format or the alpha channel surface attached to the source surface as the source alpha channel for this overlay. |
| DDOVER_ALPHASRCCONSTOVERRIDE | Use the **dwAlphaSrcConst** member of the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the source alpha channel for this overlay. |
| DDOVER_ALPHASRCNEG | The source surface becomes more transparent as the alpha value increases (0 is opaque). |
| DDOVER_ALPHASRCSURFACEOVERRIDE | Use the **lpDDSAlphaSrc** member of the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the alpha channel source for this overlay. |
| DDOVER_AUTOFLIP | Automatically flip to the next surface in the flip chain each time a hardware video port VSYNC occurs. |
| DDOVER_BOB | Display each field of the interlaced video stream individually without causing any artifacts. |
| DDOVER_BOBHARDWARE | Bob is performed using hardware rather than software or being emulated. |
| DDOVER_DDFX | Use the overlay FX flags to define special overlay effects. |
| DDOVER_HIDE | Turn this overlay off. |
| DDOVER_INTERLEAVED | The surface memory is composed of interleaved fields. |
| DDOVER_KEYDEST | Use the color key associated with the destination surface. |
| DDOVER_KEYDESTOVERRIDE | Use the **dckDestColorkey** member of the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the color key for the destination surface. |
| DDOVER_KEYSRC | Use the color key associated with the source surface. |
| DDOVER_KEYSRCOVERRIDE | Use the **dckSrcColorkey** member of the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the color key for the source surface. |
| DDOVER_OVERRIDEBOBWEAVE | Bob and weave decisions should not be overridden by other interfaces. If this flag is set, DirectDraw does not allow a kernel-mode driver to use the kernel-mode video transport functionality to switch the hardware between bob and weave mode. |
| DDOVER_REFRESHALL | Redraw the entire surface on an emulated overlaid surface. |
| DDOVER_REFRESHDIRTYRECTS | Redraw all dirty rectangles on an emulated overlaid surface. |
| DDOVER_SHOW | Turn this overlay on. |

### `dwOverlayOffset`

Specifies the byte offset from the beginning of the frame buffer to the start of the overlay. This field is used only by the miniport driver.

### `dwOverlaySrcWidth`

Specifies the overlay source width, in pixels. This field is used only by the miniport driver.

### `dwOverlaySrcHeight`

Specifies the overlay source height, in pixels. This field is used only by the miniport driver.

### `dwOverlayDestWidth`

Specifies the overlay destination width, in pixels. This field is used only by the miniport driver.

### `dwOverlayDestHeight`

Specifies the overlay destination height, in pixels. This field is used only by the miniport driver.

### `dwVideoPortId`

If this surface is being fed by a [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object, this field indicates the ID of the VPE object, an integer in the range (0 - (maximum number of hardware video ports -1 )); otherwise, this field is -1.

### `dwFormatFlags`

Specifies a set of pixel-format control flags. This member is a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDPF_ALPHA | The pixel format describes an alpha-only surface. |
| DDPF_ALPHAPIXELS | The surface has alpha channel information in the pixel format. |
| DDPF_ALPHAPREMULT | The color components in the pixel are premultiplied by the alpha value in the pixel. If this flag is set, the DDPF_ALPHAPIXELS flag must also be set. If this flag is not set but the DDPF_ALPHAPIXELS flag is set, the color components in the pixel format are not premultiplied by alpha. In this case, the color components must be multiplied by the alpha value at the time that an alpha-blending operation is performed. |
| DDPF_BUMPDUDV | The bump map dUdV data in the pixel format is valid. |
| DDPF_BUMPLUMINANCE | The luminance data in pixel format is valid. This flag is used when hanging luminance off bumpmap surfaces. The bitmask for the luminance portion of the pixel is then indicated by the **dwBumpLuminanceBitCount** member of the [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure. |
| DDPF_COMPRESSED | The surface will accept pixel data in the specified format and compress it during the write operation. |
| DDPF_FOURCC | The [FOURCC](https://learn.microsoft.com/windows-hardware/drivers/) code is valid. |
| DDPF_LUMINANCE | The luminance data in the pixel format is valid. This flag is used for luminance only or luminance plus alpha surfaces; the bit depth is then indicated by the **dwLuminanceBitCount** member of the [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure. |
| DDPF_PALETTEINDEXED1 | The surface is 1--bit color indexed. |
| DDPF_PALETTEINDEXED2 | The surface is 2--bit color indexed. |
| DDPF_PALETTEINDEXED4 | The surface is 4--bit color indexed. |
| DDPF_PALETTEINDEXED8 | The surface is 8-bit color indexed. |
| DDPF_PALETTEINDEXEDTO8 | The surface is 1-, 2-, or 4-bit color indexed to an 8-bit palette. |
| DDPF_RGB | The RGB data in the pixel format structure is valid. |
| DDPF_RGBTOYUV | The surface will accept RGB data and translate it during the write operation to YUV data. The format of the data to be written will be contained in the pixel format structure. The DDPF_RGB flag will be set. |
| DDPF_STENCILBUFFER | The surface contains stencil information along with Z information. |
| DDPF_YUV | The YUV data in the pixel format structure is valid. |
| DDPF_ZBUFFER | The pixel format describes a z-buffer-only surface. |
| DDPF_ZPIXELS | The surface is in RGBZ format. |

### `dwFormatFourCC`

Specifies the [FOURCC](https://learn.microsoft.com/windows-hardware/drivers/) code.

### `dwFormatBitCount`

Specifies the number of bits per pixel (4, 8, 16, 24, or 32).

### `dwRBitMask`

Specifies the red bitmask.

### `dwGBitMask`

Specifies the green bitmask.

### `dwBBitMask`

Specifies the blue bitmask.

### `dwDriverReserved1`

Reserved for the HAL/Miniport

### `dwDriverReserved2`

Reserved for the HAL/Miniport

### `dwDriverReserved3`

Reserved for the HAL/Miniport

### `dwDriverReserved4`

Are reserved for use by the miniport driver.

## See also

[DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat)

[DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85))

[DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay)