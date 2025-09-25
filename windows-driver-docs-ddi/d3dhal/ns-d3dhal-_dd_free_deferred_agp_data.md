# _DD_FREE_DEFERRED_AGP_DATA structure

## Description

 DirectX 8.0 and later versions and NT-based operating systems only.

DD_FREE_DEFERRED_AGP_DATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for D3DGDI2_TYPE_DEFER_AGP_FREES and D3DGDI2_TYPE_FREE_DEFERRED_AGP notifications.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data.

### `dwProcessId`

Specifies the process identifier (PID) of the process destroying the [AGP memory](https://learn.microsoft.com/windows-hardware/drivers/display/agp-support) for surfaces.

## Remarks

The driver sometimes receives a **GetDriverInfo2** call with D3DGDI2_TYPE_DEFER_AGP_FREES notification type before a display mode change occurs. The runtime only sends this notification type if it is to be used to perform the display mode change. Drivers should check the process identifier (PID) of the process destroying the surface against the process that created the surface. If the PIDs are different, the driver probably should not destroy the user-mode mappings of the AGP memory because an application might still be using the memory.

The driver receives a **GetDriverInfo2** call with D3DGDI2_TYPE_FREE_DEFERRED_AGP notification type when all display devices within the process stop using surfaces, textures, vertex buffers, and index buffers that were locked at the time of the display mode change. This notification type informs the driver that it is now safe to destroy all the user-mode mappings of the AGP memory.

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)