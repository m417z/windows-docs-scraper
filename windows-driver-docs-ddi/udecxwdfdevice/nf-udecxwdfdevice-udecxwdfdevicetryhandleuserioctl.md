# UdecxWdfDeviceTryHandleUserIoctl function

## Description

Attempts to handle an IOCTL request sent by a user-mode software.

## Parameters

### `UdecxWdfDevice`

A handle to a framework device object that represents the controller. The client driver initialized this object in the previous call to [**UdecxWdfDeviceAddUsbDeviceEmulation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

### `Request` [in]

A handle to a framework request object that represents the IOCTL request.

## Return value

TRUE indicates that USB device emulation class extension (UdeCx) recognized and completed the request (with success or failure). In this case, the client driver must
not complete the request. FALSE otherwise; the driver must complete the request.

## Remarks

The UDE client driver presents itself to user-mode software as a host controller driver. The client driver registers and exposes the GUID_DEVINTERFACE_USB_HOST_CONTROLLER device interface GUID. User-mode software can open a handle to the device by specifying that GUID. By using that handle, the software can send IOCTL requests.

**Note** Note that other interface's IOCTL codes may overlap with the USB host controller interface. If
such I/O reaches this function the IOCTL will not be handled correctly.

The client driver does not need to process the received IOCTL. It can send the request to the class extension by calling **UdecxWdfDeviceTryHandleUserIoctl**. If the class extension recognizes the request as a standard request, it completes it. Otherwise, the call fails and the client driver is then expected to complete the request. For a list of IOCTLs that must be handled, see [USB IOCTLs for applications and services](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist).

* [IOCTL_GET_HCD_DRIVERKEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_get_hcd_driverkey_name)
* [IOCTL_USB_GET_ROOT_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_root_hub_name)
* [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/win32/api/usbuser/ni-usbuser-ioctl_usb_user_request)

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)