# IWDFUsbTargetDevice::RetrieveDeviceInformation

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveDeviceInformation** method retrieves device information of the specified type.

## Parameters

### `InformationType` [in]

The type of information that the UMDF driver requests about the device.

### `BufferLength` [in, out]

A pointer to a variable that, on input, contains the size, in bytes, of the buffer that **RetrieveDeviceInformation** supplies in *Buffer*. On output, this parameter contains the size that **RetrieveDeviceInformation** requires for *Buffer*.

### `Buffer` [out]

A pointer that receives the buffer that contains the device information.

## Return value

**RetrieveDeviceInformation** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [RetrieveDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrievedeviceinformation) successfully retrieved the device information. |
| **E_OUTOFMEMORY** | [RetrieveDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrievedeviceinformation) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

For information about valid information types that a UMDF driver can pass for the *InformationType* parameter, see the [WinUsb_QueryDeviceInformation](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_querydeviceinformation) function.

If *InformationType* is DEVICE_SPEED (0x01), on successful return, *Buffer* indicates the operating speed of the device. 0x03 indicates high-speed or higher; 0x01 indicates full-speed or lower.

The **RetrieveDeviceInformation** method generates a UMDF request and synchronously sends the request to the I/O target.

#### Examples

For a code example of how to use the**RetrieveDeviceInformation** method, see [IWDFUsbTargetPipe::SetPipePolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-setpipepolicy).

## See also

[IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice)

[WinUsb_QueryDeviceInformation](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_querydeviceinformation)