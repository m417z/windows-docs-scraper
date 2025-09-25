# IDirect3DDeviceManager9::LockDevice

## Description

Gives the caller exclusive access to the Direct3D device.

## Parameters

### `hDevice` [in]

A handle to the Direct3D device. To get the device handle, call [IDirect3DDeviceManager9::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-opendevicehandle).

### `ppDevice` [out]

Receives a pointer to the device's **IDirect3DDevice9** interface.

### `fBlock` [in]

Specifies whether to wait for the device lock. If the device is already locked and this parameter is **TRUE**, the method blocks until the device is unlocked. Otherwise, if the device is locked and this parameter is **FALSE**, the method returns immediately with the error code **DXVA2_E_VIDEO_DEVICE_LOCKED**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DXVA2_E_NEW_VIDEO_DEVICE** | The device handle is invalid. |
| **DXVA2_E_NOT_INITIALIZED** | The Direct3D device manager was not initialized. The owner of the device must call [IDirect3DDeviceManager9::ResetDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-resetdevice). |
| **DXVA2_E_VIDEO_DEVICE_LOCKED** | The device is locked and *fBlock* is **FALSE**. |
| **E_HANDLE** | The specified handle is not a Direct3D device handle. |

## Remarks

When you are done using the Direct3D device, call [IDirect3DDeviceManager9::UnlockDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-unlockdevice) to unlock to the device.

If the method returns **DXVA2_E_NEW_VIDEO_DEVICE**, call [IDirect3DDeviceManager9::CloseDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-closedevicehandle) to close the handle and then call [OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-opendevicehandle) again to get a new handle. The [IDirect3DDeviceManager9::ResetDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-resetdevice) method invalidates all open device handles.

If *fBlock* is **TRUE**, this method can potentially deadlock. For example, it will deadlock if a thread calls **LockDevice** and then waits on another thread that calls **LockDevice**. It will also deadlock if a thread calls **LockDevice** twice without calling [UnlockDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-unlockdevice) in between.

#### Examples

```cpp
HRESULT LockDevice(
    IDirect3DDeviceManager9 *pDeviceManager,
    BOOL fBlock,
    IDirect3DDevice9 **ppDevice, // Receives a pointer to the device.
    HANDLE *pHandle              // Receives a device handle.
    )
{
    *pHandle = NULL;
    *ppDevice = NULL;

    HANDLE hDevice = 0;

    HRESULT hr = pDeviceManager->OpenDeviceHandle(&hDevice);

    if (SUCCEEDED(hr))
    {
        hr = pDeviceManager->LockDevice(hDevice, ppDevice, fBlock);
    }

    if (hr == DXVA2_E_NEW_VIDEO_DEVICE)
    {
        // Invalid device handle. Try to open a new device handle.
        hr = pDeviceManager->CloseDeviceHandle(hDevice);

        if (SUCCEEDED(hr))
        {
            hr = pDeviceManager->OpenDeviceHandle(&hDevice);
        }

        // Try to lock the device again.
        if (SUCCEEDED(hr))
        {
            hr = pDeviceManager->LockDevice(hDevice, ppDevice, TRUE);
        }
    }

    if (SUCCEEDED(hr))
    {
        *pHandle = hDevice;
    }
    return hr;
}

```

## See also

[Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager)

[IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9)