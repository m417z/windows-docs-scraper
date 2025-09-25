# IDirect3DDeviceManager9::UnlockDevice

## Description

Unlocks the Direct3D device. Call this method to release the device after calling [IDirect3DDeviceManager9::LockDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-lockdevice).

## Parameters

### `hDevice` [in]

Handle to the Direct3D device. To get the device handle, call [IDirect3DDeviceManager9::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-opendevicehandle).

### `fSaveState` [in]

If **TRUE**, the method saves the Direct3D device state in a state block. Internally, the method uses the Direct3D **IDirect3DStateBlock9** interface to save the device state. The next time you call [LockDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-lockdevice) with the same device handle, the state block is restored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The specified device handle is not locked, or is not a valid handle. |

## See also

[Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager)

[IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9)