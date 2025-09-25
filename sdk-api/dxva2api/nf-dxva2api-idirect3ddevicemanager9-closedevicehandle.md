# IDirect3DDeviceManager9::CloseDeviceHandle

## Description

Closes a Direct3D device handle. Call this method to release a device handle retrieved by the [IDirect3DDeviceManager9::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-opendevicehandle) method.

## Parameters

### `hDevice` [in]

Handle to the Direct3D device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_HANDLE** | Invalid handle. |

## See also

[Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager)

[IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9)