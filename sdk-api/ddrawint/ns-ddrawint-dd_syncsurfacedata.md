# DD_SYNCSURFACEDATA structure

## Description

The DD_SYNCSURFACEDATA structure contains the surface information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpDDSurface`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the surface with which to sync.

### `dwSurfaceOffset`

Contains the byte offset from the start of the frame buffer to the start of the surface. This value is used only by the video miniport driver. This member must contain data that is filled in by the driver.

### `fpLockPtr`

Contains the pointer value to be returned by the [DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock) call for accessing the surface. This value is used by a kernel-mode client. This member can be modified by the driver, but does not need to be.

### `lPitch`

Contains the pitch in bytes passed to the client during a [DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock) call. This member can be modified by the driver, but does not need to be.

### `dwOverlayOffset`

Contains the byte offset from the start of the frame buffer to the start of the overlay. This value is used only by the video miniport driver and may be different than the **dwSurfaceOffset** member if cropping is involved or if the overlay origin is not the top left of the surface. This member must contain data that is filled in by the driver.

### `dwDriverReserved1`

Reserved for use by the display driver.

### `dwDriverReserved2`

Reserved for use by the display driver.

### `dwDriverReserved3`

Reserved for use by the display driver.

### `dwDriverReserved4`

Reserved for use by the display driver. Windows 2000 and later only.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdSyncSurfaceData](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_kernelcb_syncsurface) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock)

[DdSyncSurfaceData](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_kernelcb_syncsurface)