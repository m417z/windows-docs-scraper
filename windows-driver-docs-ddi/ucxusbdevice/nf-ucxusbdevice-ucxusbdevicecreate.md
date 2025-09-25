# UcxUsbDeviceCreate function

## Description

Creates a USB device object on the specified controller.

## Parameters

### `Controller` [in]

A handle to the controller object. The client driver retrieved the handle in a previous call to [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)).

### `UsbDeviceInit` [out]

A pointer to a **UCXUSBDEVICE_INIT** structure that describes various configuration
operations for creating the USB device object. The driver specifies function pointers to its callback functions in this structure.
This structure is managed by UCX.

### `Attributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies attributes for the USB device object.

### `UsbDevice` [out]

A pointer to a variable that receives a handle to the new USB device object.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The client driver for the host controller must call this method after the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call. The parent of the new USB device object is the parent hub device specified by UCX.

For a code example, see [EVT_UCX_CONTROLLER_USBDEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_usbdevice_add).

## See also

[EVT_UCX_CONTROLLER_USBDEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_usbdevice_add)