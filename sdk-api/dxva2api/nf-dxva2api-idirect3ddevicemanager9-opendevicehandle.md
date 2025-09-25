# IDirect3DDeviceManager9::OpenDeviceHandle

## Description

Gets a handle to the Direct3D device.

## Parameters

### `phDevice` [out]

Receives the device handle.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DXVA2_E_NOT_INITIALIZED** | The Direct3D device manager was not initialized. The owner of the device must call [IDirect3DDeviceManager9::ResetDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-resetdevice). |

## Remarks

To get the Direct3D device's **IDirect3DDevice9** pointer, call [IDirect3DDeviceManager9::LockDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-lockdevice) with the handle returned in *phDevice*. Close the device handle when you are done using it, by calling [IDirect3DDeviceManager9::CloseDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-closedevicehandle).

To test whether a device handle is still valid, call [IDirect3DDeviceManager9::TestDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-testdevice).

## See also

[Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager)

[IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9)