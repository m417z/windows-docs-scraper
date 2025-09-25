# DD_UPDATEOVERLAYDATA structure

## Description

The DD_UPDATEOVERLAYDATA structure contains information necessary for updating an overlay surface.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDDestSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that represents the Microsoft DirectDraw surface to be overlaid. This value can be **NULL** if DDOVER_HIDE is specified in **dwFlags**.

### `rDest`

Specifies a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that contains the x, y, width, and height of the region on the destination surface to be overlaid.

### `lpDDSrcSurface`

Points to a DD_SURFACE_LOCAL structure that describes the overlay surface.

### `rSrc`

Specifies a RECTL structure that contains the x, y, width, and height of the region on the source surface to be used for the overlay.

### `dwFlags`

Specifies how the driver should handle the overlay. This member can be a combination of any of the following flags:

| Flag | Meaning |
| --- | --- |
| DDOVER_ADDDIRTYRECT | Should be ignored by the driver. |
| DDOVER_AUTOFLIP | The driver should autoflip the overlay whenever the hardware video port autoflips. Drivers that support [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) need only check this flag. |
| DDOVER_BOB | The driver should display each field of VPE object data individually without causing any jittery artifacts. This flag pertains to both VPE and decoders that want to do their own flipping in kernel mode using the kernel-mode video transport functionality. |
| DDOVER_BOBHARDWARE | Indicates that bob is performed by hardware rather than by software or emulation. Drivers that support VPE need only check this flag. |
| DDOVER_DDFX | The driver should show the overlay surface using the attributes specified by the **overlayFX** member. |
| DDOVER_HIDE | The driver should hide the overlay; that is, the driver should turn this overlay off. |
| DDOVER_INTERLEAVED | The overlay surface is composed of interleaved fields. Drivers that support VPE need only check this flag. |
| DDOVER_KEYDEST | The driver should use the color key associated with the destination surface. |
| DDOVER_KEYDESTOVERRIDE | The driver should use the **dckDestColorKey** member of the DDOVERLAYFX structure (described in the DirectDraw SDK documentation) as the destination color key instead of the color key associated with the destination surface. |
| DDOVER_KEYSRC | The driver should use the color key associated with the destination surface. |
| DDOVER_KEYSRCOVERRIDE | The driver should use the **dckSrcColorKey** member of the DDOVERLAYFX structure (described in the DirectDraw SDK documentation) as the source color key instead of the color key associated with the destination surface. |
| DDOVER_OVERRIDEBOBWEAVE | Bob/weave decisions should not be overridden by other interfaces. If the overlay mixer sets this flag, DirectDraw does not allow a kernel-mode driver to use the kernel-mode video transport functionality to switch the hardware between bob and weave mode. |
| DDOVER_REFRESHALL | Should be ignored by the driver. |
| DDOVER_REFRESHDIRTYRECTS | Should be ignored by the driver. |
| DDOVER_SHOW | The driver should show the overlay; that is, the driver should turn this overlay on. |

### `overlayFX`

Specifies a DDOVERLAYFX structure (described in the DirectDraw SDK documentation) that describes additional effects that the driver should use to update the overlay. The driver should use this structure only if one of DDOVER_DDFX, DDOVER_KEYDESTOVERRIDE, or DDOVER_KEYSRCOVERRIDE are set in the **dwFlags** member.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `UpdateOverlay`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay)