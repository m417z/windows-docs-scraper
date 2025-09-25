# _WDF_USB_REQUEST_TYPE enumeration (wudfusb.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_USB_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_request_type) enumeration contains values that identify a type of USB request object.

## Constants

### `WdfUsbRequestTypeInvalid`

The type of the request object is invalid.

### `WdfUsbRequestTypeNoFormat`

The request object is not formatted.

### `WdfUsbRequestTypeDeviceControlTransfer`

The request object is sent when the application calls the Win32 **DeviceIoControl** function on the file object that is associated with the target device.

### `WdfUsbRequestTypePipeWrite`

The request object is sent when the application calls the Win32 **WriteFile** or **WriteFileEx** function on the file object that is associated with the target device.

### `WdfUsbRequestTypePipeRead`

The request object is sent when the application calls the Win32 **ReadFile** or **ReadFileEx** function on the file object that is associated with the target device.