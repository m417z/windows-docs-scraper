# WinUsb_GetDescriptor function

## Description

The **WinUsb_GetDescriptor** function returns the requested descriptor. This is a synchronous operation.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface in the selected configuration.

To retrieve the device or configuration descriptor, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

To retrieve the interface descriptor of the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

To retrieve the endpoint descriptor of an endpoint in the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

To retrieve descriptors of all other interfaces and their related endpoints, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `DescriptorType` [in]

A value that specifies the type of descriptor to return. This parameter corresponds to the **bDescriptorType** field of a standard device descriptor, whose values are described in the *Universal Serial Bus*  specification. Some of these values are listed in the description of the **DescriptorType** member of the [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usb/ns-usb-_urb_control_descriptor_request) structure.

### `Index` [in]

The descriptor index. For an explanation of the descriptor index, see the *Universal Serial Bus* specification (www.usb.org).

### `LanguageID` [in]

A value that specifies the language identifier, if the requested descriptor is a string descriptor.

### `Buffer` [out]

A caller-allocated buffer that receives the requested descriptor.

### `BufferLength` [in]

The length, in bytes, of *Buffer*.

### `LengthTransferred` [out]

The number of bytes that were copied into *Buffer*.

## Return value

**WinUsb_GetDescriptor** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |

## Remarks

If the output buffer pointed to by the *Buffer* parameter is large enough, **WinUsb_GetDescriptor** creates a copy of the specified descriptor into the output buffer. No data is copied if the buffer is not large enough to hold descriptor data. The descriptor is created during the [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize) call or it may be retrieved at this point from the device.

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)

[_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usb/ns-usb-_urb_control_descriptor_request)