# _DD_MULTISAMPLEQUALITYLEVELSDATA structure

## Description

 DirectX 9.0 and later versions only.

DD_MULTISAMPLEQUALITYLEVELSDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETMULTISAMPLEQUALITYLEVELS.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data.

### `Format`

Uses a value from the D3DFORMAT enumeration to specify the surface format of the multiple-sampled render target.

### `bFlip`

Indicates the type of resolution. Set to **TRUE** (1) for flip-style resolution and to **FALSE** (0) for blt-style resolution.

### `MSType`

Uses a value from the D3DMULTISAMPLE_TYPE enumeration to specify the level of full-scene multisampling. If the display device supports maskable multisampling (more than one sample for a multiple-sample render-target format plus antialias support), the driver for the device must provide the number of quality levels for the D3DMULTISAMPLE_NONMASKABLE (1) enumerated value.

### `QualityLevels`

Receives the number of multiple-sample quality levels that the driver supports for the given render-target format.

## Remarks

The driver assigns an integer from 1 to 8 to the **QualityLevels** member. If the driver fails, ignores this D3DGDI2_TYPE_GETMULTISAMPLEQUALITYLEVELS query, or returns a value that is out of range, but otherwise reports that it supports multisampling, then the runtime determines that the number of quality levels is 1.

When the runtime calls a driver's [DdCanCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549213(v=vs.85)), [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)), or [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurfaceex) functions to create a surface, the runtime encodes the number of multiple-sample quality levels into three bits (the DDSCAPS3_MULTISAMPLE_QUALITY_MASK mask) of the **dwCaps3** member of a [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure.

For more information about D3DFORMAT and D3DMULTISAMPLE_TYPE, see the DirectX SDK documentation.

## See also

[D3dCreateSurfaceEx](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurfaceex)

[DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85))

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)

[DdCanCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549213(v=vs.85))

[DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85))