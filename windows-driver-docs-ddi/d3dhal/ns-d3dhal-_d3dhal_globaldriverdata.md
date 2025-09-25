# _D3DHAL_GLOBALDRIVERDATA structure

## Description

The D3DHAL_GLOBALDRIVERDATA structure specifies the 3D capabilities of the driver and its device.

## Members

### `dwSize`

Specifies the size in bytes of this D3DHAL_GLOBALDRIVERDATA structure.

### `hwCaps`

Specifies a [D3DDEVICEDESC_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3ddevicedesc_v1) structure where the driver should return its hardware capabilities.

### `dwNumVertices`

Reserved for system use and should be set to zero by the driver.

### `dwNumClipVertices`

Reserved for system use and should be set to zero by the driver.

### `dwNumTextureFormats`

Specifies the number of [DDSURFACEDESC](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550339(v=vs.85)) structures that **lpTextureFormats** points to.

### `lpTextureFormats`

Points to an array of DDSURFACEDESC structures where the driver should return the texture formats supported by the device.

## Remarks

The driver is responsible for allocating space for and setting all members of this structure. The driver returns a pointer to this structure in the **lpD3DGlobalDriverData** member of the [DD_HALINFO](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo) structure, which is passed to the driver's [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo) function during driver initialization.

## See also

[D3DDEVICEDESC_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3ddevicedesc_v1)

[DDSURFACEDESC](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550339(v=vs.85))

[DD_HALINFO](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo)