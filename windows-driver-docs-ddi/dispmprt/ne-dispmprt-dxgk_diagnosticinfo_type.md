# DXGK_DIAGNOSTICINFO_TYPE enumeration

## Description

Indicates the type of information the driver needs to collect.

## Constants

### `DXGK_DI_ADDDEVICE`

The type of information to be collected for [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device).

### `DXGK_DI_STARTDEVICE`

The type of information to be collected for [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `DXGK_DI_BLACKSCREEN`

Collect black box data for black screen scenarios in calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive) and [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive). DXGK_DDI_BLACKSCREEN is available in Windows 10, version 2004 and later versions. WDDM 2.7 and later drivers are required to support this value.

## See also

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)