# DD_CREATESURFACEEXDATA structure

## Description

The DD_CREATESURFACEEXDATA structure contains information required for the driver to create a surface and associate with it a supplied texture handle.

## Members

### `dwFlags`

Specifies a set of flags for the **D3dCreateSurfaceEx** function that are currently not used and always zero.

### `lpDDLcl`

Specifies a handle to the DirectDraw object created by the application. This is the scope within which the **lpDDSLcl** handles exist. A [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure describes the driver.

### `lpDDSLcl`

Specifies a handle to the DirectDraw surface to be created for Direct3D. These handles are unique within each different DD_DIRECTDRAW_LOCAL structure. A [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure represents the created surface object.

### `ddRVal`

Specifies the location where the driver writes the return value of the [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex) callback. A return code of D3D_OK indicates success. For more information, see [Return Codes for Direct3D Driver Callbacks](https://learn.microsoft.com/windows-hardware/drivers/display/return-codes-for-direct3d-driver-callbacks).

## See also

[D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex)

[DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local)

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local)