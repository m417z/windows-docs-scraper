# DD_SURFACE_MORE structure

## Description

The DD_SURFACE_MORE structure contains additional local data for each individual DirectDrawSurface object.

## Members

### `dwMipMapCount`

Contains the number of mipmap levels in the chain.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure of the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object currently writing data to this surface.

### `dwOverlayFlags`

Specifies a set of flags that indicate the overlay flags most recently passed to [DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay). This member is a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDOVER_ADDDIRTYRECT | Add a dirty rectangle to an emulated overlaid surface. |
| DDOVER_ALPHADEST | Use the alpha information in the pixel format or the alpha channel surface attached to the destination surface as the alpha channel for the destination overlay. |
| DDOVER_ALPHADESTCONSTOVERRIDE | Use the **dwConstAlphaDest** member in the DDOVERLAYFX structure (defined in the Microsoft DirectDraw SDK documentation) as the destination alpha channel for this overlay. |
| DDOVER_ALPHADESTNEG | The NEG suffix indicates that the destination surface becomes more transparent as the alpha value increases. |
| DDOVER_ALPHADESTSURFACEOVERRIDE | Use the **lpDDSAlphaDest** member in the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the alpha channel destination for this overlay. |
| DDOVER_ALPHAEDGEBLEND | Use the **dwAlphaEdgeBlend** member in the DDOVERLAYFX structure as the alpha channel for the edges of the image that border the color key colors. |
| DDOVER_ALPHASRC | Use the alpha information in the pixel format or the alpha channel surface attached to the source surface as the source alpha channel for this overlay. |
| DDOVER_ALPHASRCCONSTOVERRIDE | Use the **dwConstAlphaSrc** member in the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the source alpha channel for this overlay. |
| DDOVER_ALPHASRCNEG | The NEG suffix indicates that the source surface becomes more transparent as the alpha value increases. |
| DDOVER_ALPHASRCSURFACEOVERRIDE | Use the **lpDDSAlphaSrc** member in the DDOVERLAYFX structure as the alpha channel source for this overlay. |
| DDOVER_AUTOFLIP | Autoflip the overlay whenever the VPE object autoflips. |
| DDOVER_BOB | Display each field of VPE object data individually without causing any jittery artifacts. |
| DDOVER_BOBHARDWARE | Bob is performed using hardware rather than software or emulated. |
| DDOVER_DDFX | Use the overlay FX flags to define special overlay FX. |
| DDOVER_HIDE | Turn this overlay off. |
| DDOVER_INTERLEAVED | Indicates that the surface memory is composed of interleaved fields. |
| DDOVER_KEYDEST | Use the color key associated with the destination surface. |
| DDOVER_KEYDESTOVERRIDE | Use the **dckDestColorkey** member in the DDOVERLAYFX structure (defined in the DirectDraw SDK documentation) as the color key for the destination surface. |
| DDOVER_KEYSRC | Use the color key associated with the source surface. |
| DDOVER_KEYSRCOVERRIDE | Use the **dckSrcColorkey** member in the DDOVERLAYFX structure as the color key for the source surface. |
| DDOVER_OVERRIDEBOBWEAVE | Bob and weave decisions should not be overridden by other interfaces. If this flag is set, DirectDraw does not allow a kernel-mode driver to use the kernel-mode video transport functionality to switch the hardware between bob and weave mode. |
| DDOVER_REFRESHALL | Redraw the entire surface on an emulated overlayed surface. |
| DDOVER_REFRESHDIRTYRECTS | Redraw all dirty rectangles on an emulated overlayed surface. |
| DDOVER_SHOW | Turn this overlay on. |

### `ddsCapsEx`

Specifies a DDSCAPSEX structure that is used to expose extended surface capabilities. A DDSCAPSEX structure is the same as a [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure without the **dwCaps** member.

### `dwSurfaceHandle`

Specifies a cookie for [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex) so that it can associate a texture handle with the surface.

## See also

[D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex)

[DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local)

[DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay)