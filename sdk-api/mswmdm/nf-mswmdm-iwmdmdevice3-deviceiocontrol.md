# IWMDMDevice3::DeviceIoControl

## Description

The **DeviceIoControl** method sends a Device I/O Control (IOCTL) code to the device. This is a pass-through method; Windows Media Device Manager just forwards the call to the service provider after validating the parameters.

## Parameters

### `dwIoControlCode` [in]

Control code to send to the device. When calling this method on an MTP device, use the value IOCTL_MTP_CUSTOM_COMMAND defined in MtpExt.h included with the SDK.

### `lpInBuffer` [in]

Optional pointer to an input buffer supplied by the caller. It can be **NULL** if *nInBufferSize* is zero. When calling this method on an MTP device, you can pass in the [MTP_COMMAND_DATA_IN](https://learn.microsoft.com/windows/desktop/api/mtpext/ns-mtpext-mtp_command_data_in) structure.

### `nInBufferSize` [in]

Size of the input buffer, in bytes. When calling this method on an MTP device, you can use the macro **SIZEOF_REQUIRED_COMMAND_DATA_IN** to specify the size.

### `lpOutBuffer` [out]

Optional pointer to the output buffer supplied by the caller. It can be **NULL** if *pnOutBufferSize* points to a value of zero. When calling this method on an MTP device, you can pass in the [MTP_COMMAND_DATA_OUT](https://learn.microsoft.com/windows/desktop/api/mtpext/ns-mtpext-mtp_command_data_out) structure.

### `pnOutBufferSize` [in, out]

Size of the output buffer, in bytes. When the call returns, it specifies the number of bytes actually returned. When calling this method on an MTP device, you can use the macro **SIZEOF_REQUIRED_COMMAND_DATA_OUT** defined in MtpExt.h to specify the size.This parameter cannot be **NULL**.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method provides a private mode of communication between the application and the service provider. The service provider can then process this IOCTL, optionally modify it, and pass it to the kernel mode driver.

Compared to [IWMDMDevice::SendOpaqueCommand](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-sendopaquecommand), this method better aligns with the **DeviceIoControl** Windows API because the output buffer is supplied by the caller. Also, unlike **IWMDMDevice::SendOpaqueCommand**, this method does not involve any MAC check and is more efficient.

This method can be used, for example, to send custom Media Transport Protocol (MTP) commands to an MTP device.

## See also

[IWMDMDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice3)

[IWMDMDevice::SendOpaqueCommand](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-sendopaquecommand)