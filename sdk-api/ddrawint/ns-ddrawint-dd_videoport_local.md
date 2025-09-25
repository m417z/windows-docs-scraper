# DD_VIDEOPORT_LOCAL structure

## Description

The DD_VIDEOPORT_LOCAL structure contains [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/)-related data that is unique to an individual Microsoft DirectDraw VPE object.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current DirectDraw process only.

### `ddvpDesc`

Specifies a [DDVIDEOPORTDESC](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportdesc) structure that describes the VPE object.

### `ddvpInfo`

Specifies a [DDVIDEOPORTINFO](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportinfo) structure that describes the transfer of video data to a surface.

### `lpSurface`

Points to a [DD_SURFACE_INT](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_int) structure for the surface receiving the video data.

### `lpVBISurface`

Points to a DD_SURFACE_INT structure for the surface receiving the [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data.

### `dwNumAutoflip`

Specifies the number of current autoflip surfaces.

### `dwNumVBIAutoflip`

Specifies the number of VBI surfaces currently being autoflipped.

### `dwReserved1`

Reserved for use by the display driver.

### `dwReserved2`

Reserved for use by the display driver.

### `dwReserved3`

Reserved for use by the display driver.

## Remarks

This structure is initialized and filled in by DirectDraw. Except for the **dwReserved1**, **dwReserved2**, and **dwReserved3** members, the driver must not modify any other members of the DD_VIDEOPORT_LOCAL structure.