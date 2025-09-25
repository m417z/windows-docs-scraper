# EVT_UCX_USBDEVICE_GET_CHARACTERISTIC callback function

## Description

 UCX invokes this callback to retrieve the device characteristics.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `UcxUsbDevice` [in]

A handle to a UCX object that represents the USB device that the client driver received in a previous call to the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

### `UcxUsbDeviceCharacteristic` [in, out]

A pointer to a [UCX_USBDEVICE_CHARACTERISTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_characteristic) structure that contains the type of characteristic in which the caller is interested. The client driver fills the value of the requested characteristic. For example, if the type indicates [UCX_USBDEVICE_CHARACTERISTIC_PATH_DELAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_characteristic_path_delay), the driver fills the **UCX_USBDEVICE_CHARACTERISTIC_PATH_DELAY** structure, pointed to by **PathDelay** member, with the appropriate maximum and send path delay values.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The UCX client driver registers its implementation with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.