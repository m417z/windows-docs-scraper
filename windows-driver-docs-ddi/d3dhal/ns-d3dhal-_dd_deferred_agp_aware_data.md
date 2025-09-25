# _DD_DEFERRED_AGP_AWARE_DATA structure

## Description

 DirectX 8.0 and later versions and NT-based operating systems only.

DD_DEFERRED_AGP_AWARE_DATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for D3DGDI2_TYPE_DEFERRED_AGP_AWARE notifications.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data.

## Remarks

Whenever a display device is created, the driver receives a **GetDriverInfo2** call with D3DGDI2_TYPE_DEFERRED_AGP_AWARE type and can determine if it should disable its other mechanisms that handle AGP memory and instead use the D3DGDI2_TYPE_FREE_DEFERRED_AGP and D3DGDI2_TYPE_DEFER_AGP_FREES notifications that the runtime subsequently sends.

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)