# DXGKCB_GET_DEVICE_INFORMATION callback function

## Description

The *DxgkCbGetDeviceInformation* function gets information, including the registry path and a list of translated resources, about a specified display adapter.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to the [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `DeviceInfo` [out]

A pointer to a [DXGK_DEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_device_info) structure that receives information about the display adapter.

## Return value

*DxgkCbGetDeviceInformation* returns STATUS_SUCCESS if it succeeds; otherwise, it returns STATUS_INVALID_PARAMETER.

## See also

[DXGK_DEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_device_info)

[DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)