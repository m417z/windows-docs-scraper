# DD_CREATESURFACEDATA structure

## Description

The DD_CREATESURFACEDATA structure contains information necessary to create a surface--in the case of [CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface), a command or vertex buffer.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurfaceDesc`

Points to the [DDSURFACEDESC](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structure describing the surface or buffer that the driver should create.

### `lplpSList`

Points to a list of [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structures describing the surface objects created by the driver. On Microsoft Windows 2000 and later, there is usually only one entry in this array. However, if the driver supports the Windows 98/Me-style surface creation techniques using [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) with GUID_NTPrivateDriverCaps, and the driver sets the DDHAL_PRIVATECAP_ATOMICSURFACECREATION flag, the member contains a list of surfaces (usually more than one).

### `dwSCnt`

Specifies the number of surfaces in the list to which **lplpSList** points. This value is usually 1 on Windows 2000 and later. However, if the driver support the Windows 98/Me-style surface creation techniques using [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) with GUID_NTPrivateDriverCaps, the member contains the actual number of surfaces in the list (usually more than one).

### `ddRVal`

Specifies the location in which the driver writes the return value of either the [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)) or [CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `CreateSurface`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[CreateD3DBuffer](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurface)

[DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85))

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)