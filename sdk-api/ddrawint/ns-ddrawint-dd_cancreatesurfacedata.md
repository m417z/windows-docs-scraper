# DD_CANCREATESURFACEDATA structure

## Description

The DD_CANCREATESURFACEDATA structure contains information necessary to indicate whether a surface--in the case of [CanCreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_cancreatesurface), a buffer--can be created.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurfaceDesc`

Points to a [DDSURFACEDESC](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structure that contains a description of the surface or buffer to be created. See the Remarks section for additional information about this member.

### `bIsDifferentPixelFormat`

Indicates whether the pixel format of the surface to be created differs from that of the primary surface. For the [CanCreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_cancreatesurface) D3DBuffer callback, this member is always set to **FALSE** because the driver is attempting to create a buffer that contains vertex data or commands, rather than pixel data.

### `ddRVal`

Specifies the location in which the driver writes the return value of either the [DdCanCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549213(v=vs.85)) or [CanCreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_cancreatesurface) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `CanCreateSurface`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## Remarks

The DirectDraw surface description pointed to by the **lpDDSurfaceDesc** member is actually a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure (rather than a DDSURFACEDESC structure) for DirectDraw 6.0 and later runtimes. Therefore, if you need information at surface-creation time from those members that are in the DDSURFACEDESC2 structure but not in the DDSURFACEDESC structure, you can simply cast the pointer to a DDSURFACEDESC structure to a pointer to a DDSURFACEDESC2 structure prior to use. The following example shows how the value of **dwTextureStage** (a member of the DDSURFACEDESC2 structure, but not also of the DDSURFACEDESC structure) can be obtained from a pointer to a DDSURFACEDESC structure.

```
DDSURFACEDESC2* pddsd = (DDSURFACEDESC2*)pccsd->lpDDSurfaceDesc;
DWORD dwStage = pddsd->dwTextureStage;
```

## See also

[CanCreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_cancreatesurface)

[DdCanCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549213(v=vs.85))