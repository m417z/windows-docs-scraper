# DXGKCB_IS_DEVICE_PRESENT callback function

## Description

The **DxgkCbIsDevicePresent** function determines whether a specified PCI device is present.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `DevicePresenceParameters` [in]

A pointer to a PCI_DEVICE_PRESENCE_PARAMETERS structure (defined in *Wdm.h*) that the caller fills in with information that identifies the device.

### `DevicePresent` [out]

A pointer to a Boolean variable that receives **TRUE** if the device is present or **FALSE** if the device is not present.

## Return value

**DxgkCbIsDevicePresent** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.