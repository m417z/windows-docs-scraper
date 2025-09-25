# DXGKDDI_CREATEDEVICE callback function

## Description

The **DXGKDDI_CREATEDEVICE** function creates a graphics context device that is subsequently used in calls to the display miniport driver's device-specific functions.

## Parameters

### `hAdapter`

[in] A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgiDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCreateDevice`

[in/out] Pointer to a [**DXGKARG_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice) structure that describes the graphics context device.

## Return value

**DXGKDDI_CREATEDEVICE** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | **DXGKDDI_CREATEDEVICE** successfully created the graphics context device.|
| STATUS_NO_MEMORY | **DXGKDDI_CREATEDEVICE** could not allocate memory that was required for it to complete.|

## Remarks

*Dxgkrnl* calls the display miniport driver's **DXGKDDI_CREATEDEVICE** function to create a graphics context device that the graphics subsystem subsequently passes in calls to the display miniport driver. The driver uses a device to hold a collection of rendering state. The graphics subsystem can create multiple devices in the same process on a given graphics processing unit (GPU) adapter.

> [!NOTE]
> The number of devices that can simultaneously exist is limited only by available system memory. That is, a driver cannot have a hard-coded maximum device limit.

Generally, devices are independent of each other; in other words, resources that are created in one device cannot be referenced or accessed by resources that are created in another device. However, cross-process resources are an exception to this rule.

**DXGKDDI_CREATEDEVICE** should be made pageable.

## See also

[**DXGKARG_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice)

[**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)