# IMFDXGIDeviceManager::TestDevice

## Description

Tests whether a Microsoft Direct3D device handle is valid.

## Parameters

### `hDevice` [in]

A handle to the Direct3D device. To get the device handle, call [IMFDXGIDeviceManager::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-opendevicehandle).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_HANDLE** | The specified handle is not a Direct3D device handle. |
| **MF_E_DXGI_NEW_VIDEO_DEVICE** | The device handle is invalid. |

## Remarks

If the method returns **MF_E_DXGI_NEW_VIDEO_DEVICE**, call [IMFDXGIDeviceManager::CloseDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-closedevicehandle) to close the handle and then call [OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-opendevicehandle) again to get a new handle. The [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice) method invalidates all open device handles.

## See also

[IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager)