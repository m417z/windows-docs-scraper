# IMFDXGIDeviceManager::OpenDeviceHandle

## Description

Gets a handle to the Microsoft Direct3D device.

## Parameters

### `phDevice` [out]

Receives the device handle.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_DXGI_DEVICE_NOT_INITIALIZED** | The DXGI Device Manager was not initialized. The owner of the device must call [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice). |

## See also

[IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager)