# EVT_UDECX_USB_DEVICE_SET_FUNCTION_SUSPEND_AND_WAKE callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function when it gets a request to change the function state of the specified interface of the virtual USB 3.0 device.

## Parameters

### `UdecxWdfDevice` [in]

A handle to a framework device object that represents the controller to which the USB device is attached. The client driver initialized this object in a previous call to [UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver created this object in a previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `Interface` [in]

This value is the **bInterfaceNumber** of the interface that is waking up.

### `FunctionPower` [in]

A [UDECX_USB_DEVICE_FUNCTION_POWER](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ne-udecxusbdevice-_udecx_usb_device_function_power)-type value that indicates whether the interface can suspend and send wake signal to the host controller.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE.

## Remarks

The client driver registered the function in a previous call to [UdecxUsbDeviceInitSetStateChangeCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetstatechangecallbacks) by supplying a function pointer to its implementation.

In the callback implementation, the client driver for the USB device is expected to perform steps to enter working state.

This event callback function applies to USB 3.0+ devices. UdeCx invokes this function to notify the client driver of a request to change the power state of a particular function. It also informs the driver whether or not the function can wake from the new state.

The power request may be completed asynchronously by returning STATUS_PENDING, and then later completing it by calling [UdecxUsbDeviceSetFunctionSuspendAndWakeComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicesetfunctionsuspendandwakecomplete) with the actual completion code.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)