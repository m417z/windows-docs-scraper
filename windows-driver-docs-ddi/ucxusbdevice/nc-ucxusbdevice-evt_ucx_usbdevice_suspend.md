# EVT_UCX_USBDEVICE_SUSPEND callback function

## Description

UCX invokes this callback function to send a device suspend state.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `UcxUsbDevice` [in]

A handle to a UCX object that represents the USB device that the client driver received in a previous call to the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

## Remarks

The UCX client driver registers its implementation with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.