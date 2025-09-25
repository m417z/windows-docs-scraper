# DD_BLTDATA structure

## Description

The DD_BLTDATA structure contains the information relevant to the driver for doing bit block transfers.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDDestSurface`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the surface on which to blit.

### `rDest`

######

######

######

### `lpDDSrcSurface`

Points to a DD_SURFACE_LOCAL structure that describes the source surface.

### `rSrc`

######

######

######

### `dwFlags`

Indicates a set of flags that specify the type of blit operation to perform and what associated structure members have valid data that the driver should use. This member is a bitwise OR of any of the following flags:

| Flag | Meaning |
| --- | --- |
| DDBLT_ASYNC | Perform this blit asynchronously through the FIFO in the order received. If no room exists in the hardware FIFO, the driver should fail the call and return immediately. |
| DDBLT_COLORFILL | Use the **dwFillColor** member in the DDBLTFX structure (defined in the Microsoft DirectDraw SDK documentation) as the RGB color with which to fill the destination rectangle on the destination surface. |
| DDBLT_DDFX | Use the **dwDDFX** member in the DDBLTFX structure (defined in the DirectDraw SDK documentation) to determine the effects to use for the blit. |
| DDBLT_DDROPS | This flag is reserved for system use and should be ignored by the driver. The driver should also ignore the **dwDDROPS** member of the DDBLTFX structure. |
| DDBLT_EXTENDED_FLAGS | **Microsoft DirectX 9.0 and later versions only.**<br><br>Set by the runtime to direct the driver to reinterpret certain flags in **dwFlags** from their meanings in DirectX 8.1 and earlier versions. The runtime combines DDBLT_EXTENDED_FLAGS with DDBLT_*Xxx* flags using a bitwise OR to create DDBLT_EXTENDED_*Xxx* flags. |
| DDBLT_EXTENDED_LINEAR_CONTENT | **Microsoft DirectX 9.0 and later versions only.**<br><br>Created through the bitwise OR combination of DDBLT_EXTENDED_FLAGS and the 0x00000004 bit.<br><br>Indicates that the source surface contains content in a linear color space. The driver can then perform gamma 2.2 correction (sRGB) to the desktop color space as part of the blt. |
| DDBLT_EXTENDED_PRESENTATION_STRETCHFACTOR | **Microsoft DirectX 9.0 and later versions only.**<br><br>**NT-based operating systems only.**<br><br>Created through the bitwise OR combination of DDBLT_EXTENDED_FLAGS and the 0x00000010 bit.<br><br>Set if the runtime subsequently uses the DDBLT_PRESENTATION and DDBLT_LAST_PRESENTATION flags to request a series of stretch-blit operations because of a **Present** call by an application.<br><br>Notifies the driver about the entire unclipped source and destination rectangular areas before the driver receives actual sub-rectangular areas for blits. In this way, the driver can calculate and record the stretch factor for all subsequent blits up to and including the blit with the DDBLT_LAST_PRESENTATION flag set. However, when the driver receives a blit with the DDBLT_EXTENDED_PRESENTATION_STRETCHFACTOR flag set, the driver must not use these unclipped rectangular areas to do any actual blitting.<br><br>After the driver finishes the final blit with the DDBLT_LAST_PRESENTATION flag set, the driver should clear the stretch-factor record to prevent interference with any subsequent blits<br><br>. |
| DDBLT_KEYDESTOVERRIDE | Use the **dckDestColorkey** member in the DDBLTFX structure (defined in the DirectDraw SDK documentation) as the color key for the destination surface. If an override is not being set, then **dckDestColorkey** does not contain the color key. The driver should test the surface itself. |
| DDBLT_KEYSRCOVERRIDE | Use the **dckSrcColorkey** member in the DDBLTFX structure (defined in the DirectDraw SDK documentation) as the color key for the source surface. If an override is not being set, then **dckDestColorkey** does not contain the color key. The driver should test the surface itself. |
| DDBLT_LAST_PRESENTATION | **DirectX 8.0 and later versions only.**<br><br>Set if the runtime requests a final blit operation because of a **Present** call by an application. |
| DDBLT_PRESENTATION | **DirectX 8.0 and later versions only.**<br><br>Set if the runtime requests a blit operation because of a **Present** call by an application. |
| DDBLT_ROP | Use the **dwROP** member in the DDBLTFX structure (defined in the DirectDraw SDK documentation) for the raster operation for this blit. Currently, the only [ROP](https://learn.microsoft.com/windows-hardware/drivers/) passed to the driver is SRCCOPY. This ROP is the same as that defined in the Win32 API. See the Microsoft Windows SDK documentation for details. |
| DDBLT_ROTATIONANGLE | This flag is not supported on Windows 2000 and later and should be ignored by the driver. |
| DDBLT_WAIT | Do not return immediately with the DDERR_WASSTILLDRAWING message if the blitter is busy--wait until the blit can be set up or another error occurs. |

### `dwROPFlags`

Unused on Windows 2000 and later and should be ignored by the driver.

### `bltFX`

#########

######

#######

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdBlt](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_blt) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `Blt`

Used by the DirectDraw API and should not be filled in by the driver.

### `IsClipped`

Indicates whether this is a clipped blit. On Windows 2000 and later, this member is always **FALSE**, indicating that the blit is unclipped.

### `rOrigDest`

**Unused for Windows 2000 and later.** Specifies a RECTL structure that defines the unclipped destination rectangle. This member is valid only if **IsClipped** is **TRUE**.

### `rOrigSrc`

**Unused for Windows 2000 and later.** Specifies a RECTL structure that defines the unclipped source rectangle. This member is valid only if **IsClipped** is **TRUE**.

### `dwRectCnt`

**Unused for Windows 2000 and later.**Specifies the number of destination rectangles to which **prDestRects** points. This member is valid only if **IsClipped** is **TRUE**.

### `prDestRects`

**Unused for Windows 2000 and later.** Points to an array of RECTL structures that describe of destination rectangles. This member is valid only if **IsClipped** is **TRUE**.

### `dwAFlags`

Unused and should be ignored by the driver.

### `ddargbScaleFactors`

ARGB scaling factors (AlphaBlt)

## Remarks

For more information about the DDBLT_PRESENTATION and DDBLT_LAST_PRESENTATION flags, see [Presentation](https://learn.microsoft.com/windows-hardware/drivers/display/presentation).

## See also

[DdBlt](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_blt)