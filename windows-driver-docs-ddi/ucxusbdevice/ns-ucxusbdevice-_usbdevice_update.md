# _USBDEVICE_UPDATE structure

## Description

Passed by UCX to update the specified device. This structure is in the request parameters (**Parameters.Others.Arg1**) of a framework request object passed in the [EVT_UCX_USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_update) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that contains the handle for the USB hub or device.

### `Flags`

A bitwise-OR of [USBDEVICE_UPDATE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_flags) values that indicates the attributes that must be updated by the client driver.

### `DeviceDescriptor`

A pointer a [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) structure that contains the device descriptor.

### `BosDescriptor`

A pointer a **USB_BOS_DESCRIPTOR** structure that contains the device descriptor. See [Usbspec.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/).

### `MaxExitLatency`

The maximum exit latency period.

### `IsHub`

Indicates if the USB device to update is a USB hub (TRUE) or not (FALSE).

### `FailureFlags`

A [USBDEVICE_UPDATE_FAILURE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_failure_flags) structure that indicates the errors, if any, that occurred during the update operation.

### `Usb20HardwareLpmParameters`

A [USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_20_hardware_lpm_parameters) structure that describes the Link Power Management (LPM) features.

### `RootPortResumeTime`

The resume time for the root port.

### `Reserved`

Reserved for internal use.

## See also

- [USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_20_hardware_lpm_parameters)
- [USBDEVICE_UPDATE_FAILURE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_failure_flags)
- [USBDEVICE_UPDATE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_flags)
- [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)