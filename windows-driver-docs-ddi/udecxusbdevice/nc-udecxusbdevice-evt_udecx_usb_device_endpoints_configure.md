# EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function to change the configuration by selecting an alternate setting, disabling current endpoints, or adding dynamic endpoints.

## Parameters

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver created this object in a previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `Request` [in]

A handle to a framework request object that represents the request.

### `Params` [in]

A pointer to a [UDECX_ENDPOINTS_CONFIGURE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ns-udecxusbdevice-_udecx_endpoints_configure_params) structure that describes the configuration options.

## Remarks

The client driver registered this callback function in a previous call to [UdecxUsbDeviceInitSetStateChangeCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetstatechangecallbacks) by supplying a function pointer to its implementation.

The class extension invokes this callback function to request the client driver to configure one or more new endpoints into hardware, and/or informs the driver when one or more existing endpoints is no longer being used.

After creating endpoints, for each new endpoint, the client driver must call [UdecxUsbEndpointSetWdfIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointsetwdfioqueue) before completing the request.

After releasing endpoints, the client driver should not use framework queue objects associated with the endpoints. The class extension considers those queues as purged to prevent future requests.

The class extension can also request a new configuration value or an alternate setting through this callback.

This call is asynchronous. The client driver must signals completion with status by completing the request passed by the class extension.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbEndpointSetWdfIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointsetwdfioqueue)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)