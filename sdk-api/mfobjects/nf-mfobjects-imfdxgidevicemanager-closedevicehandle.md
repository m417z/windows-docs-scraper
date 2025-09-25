# IMFDXGIDeviceManager::CloseDeviceHandle

## Description

Closes a Microsoft Direct3D device handle.

## Parameters

### `hDevice` [in]

A handle to the Direct3D device.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_HANDLE** | The specified handle is not a Direct3D device handle. |

## Remarks

 Call this method to release a device handle that was retrieved by the [IMFDXGIDeviceManager::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-opendevicehandle) method.

## See also

[IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager)