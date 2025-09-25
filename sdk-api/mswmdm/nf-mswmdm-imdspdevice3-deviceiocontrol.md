# IMDSPDevice3::DeviceIoControl

## Description

The **DeviceIoControl** method calls the device I/O control.

## Parameters

### `dwIoControlCode` [in]

I/O control code being sent to the device.

### `lpInBuffer` [in]

Input buffer supplied by the calling application. This can be **NULL** if *nInBufferSize* is zero.

### `nInBufferSize` [in]

Size of *lpInBuffer*, in bytes.

### `lpOutBuffer` [out]

Output buffer, supplied by the calling application.

### `pnOutBufferSize` [in]

Size of *lpOutBuffer*, in bytes.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method provides a private mode of communication between the application and the service provider. The service provider can then process this IOCTL, optionally modify it, and pass it to the kernel-mode driver.

Compared to [IMDSPDevice::SendOpaqueCommand](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-sendopaquecommand), this method better aligns with the **DeviceIoControl** Windows API because the output buffer is supplied by the caller. Also, unlike **IMDSPDevice::SendOpaqueCommand**, this method does not involve any MAC check and is more efficient.

## See also

[IMDSPDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice3)

[IMDSPDevice::SendOpaqueCommand](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-sendopaquecommand)

[IWMDMDevice3::DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-deviceiocontrol)