# IMFDXGIDeviceManager::UnlockDevice

## Description

Unlocks the Microsoft Direct3D device.

## Parameters

### `hDevice` [in]

A handle to the Direct3D device. To get the device handle, call [IMFDXGIDeviceManager::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-opendevicehandle).

### `fSaveState` [in]

Reserved.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Call this method to release the device after calling [IMFDXGIDeviceManager::LockDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-lockdevice).

## See also

[IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager)