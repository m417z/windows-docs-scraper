# DD_STEREOMODE structure

## Description

The DD_STEREOMODE structure is used by the runtime with GUID_DDStereoMode in a **DdGetDriverInfo** call to query whether the driver supports stereo for a given video display mode.

## Members

### `dwSize`

Specifies the size in bytes of the DD_STEREOMODE structure.

### `dwHeight`

Specifies the height in scan lines of the display mode. Has the value D3DGDI2_MAGIC if this structure is, in fact, a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) call.

### `dwWidth`

Specifies the width in pixels of the display mode.

### `dwBpp`

Specifies the bits per pixel of the display mode.

### `dwRefreshRate`

Specifies the refresh rate in hertz of the display mode.

### `bSupported`

Driver sets to **TRUE** if stereo is supported with the specified display mode, or **FALSE** otherwise.

## Remarks

To check each display mode to see if the driver supports stereo with that mode, the runtime calls the driver's [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function. In this call, the runtime specifies GUID_DDStereoMode in the **guidInfo** member of the [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) structure to which the *lpGetDriverInfo* parameter points. The runtime also provides a pointer to a DD_STEREOMODE structure in the **lpvData** member of DD_GETDRIVERINFODATA. The driver returns DD_OK if it supports GUID_DDStereoMode and sets the **bSupported** member of DD_STEREOMODE to **TRUE** if it supports stereo with the specified display mode.

GUID_DDStereoMode provides a way to turn OFF stereo per-mode, since it is expected that a driver that can do stereo can do stereo in any mode.

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)