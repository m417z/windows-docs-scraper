# IMFDXGIDeviceManager::LockDevice

## Description

Gives the caller exclusive access to the Microsoft Direct3D device.

## Parameters

### `hDevice` [in]

A handle to the Direct3D device. To get the device handle, call [IMFDXGIDeviceManager::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-opendevicehandle).

### `riid` [in]

The interface identifier (IID) of the requested interface. The Direct3D device will support the following interfaces:

* [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)
* [ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)
* [ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)

### `ppUnkDevice` [out]

Receives a pointer to the requested interface. The caller must release the interface.

### `fBlock` [in]

Specifies whether to wait for the device lock. If the device is already locked and this parameter is **TRUE**, the method blocks until the device is unlocked. Otherwise, if the device is locked and this parameter is **FALSE**, the method returns immediately with the error code **DXVA2_E_VIDEO_DEVICE_LOCKED**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_HANDLE** | The specified handle is not a Direct3D device handle. |
| **MF_E_DXGI_DEVICE_NOT_INITIALIZED** | The DXGI Device Manager was not initialized. The owner of the device must call [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice). |
| **MF_E_DXGI_NEW_VIDEO_DEVICE** | The device handle is invalid. |
| **MF_E_DXGI_VIDEO_DEVICE_LOCKED** | The device is locked and *fBlock* is **FALSE**. |

## Remarks

When you are done using the Direct3D device, call [IMFDXGIDeviceManager::UnlockDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-unlockdevice) to unlock the device.

If the method returns **MF_E_DXGI_NEW_VIDEO_DEVICE**, call [IMFDXGIDeviceManager::CloseDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-closedevicehandle) to close the handle and then call [OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-opendevicehandle) again to get a new handle. The [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice) method invalidates all open device handles.

If *fBlock* is **TRUE**, this method can potentially deadlock. For example, it will deadlock if a thread calls **LockDevice** and then waits on another thread that calls **LockDevice**. It will also deadlock if a thread calls **LockDevice** twice without calling [UnlockDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-unlockdevice) in between.

## See also

[IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager)