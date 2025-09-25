# IDirect3DDeviceManager9::TestDevice

## Description

Tests whether a Direct3D device handle is valid.

## Parameters

### `hDevice` [in]

Handle to a Direct3D device. To get a device handle, call [IDirect3DDeviceManager9::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-opendevicehandle).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The device handle is valid. |
| **E_HANDLE** | The specified handle is not a Direct3D device handle. |
| **DXVA2_E_NEW_VIDEO_DEVICE** | The device handle is invalid. |

## Remarks

If the method returns DXVA2_E_NEW_VIDEO_DEVICE, call [IDirect3DDeviceManager9::CloseDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-closedevicehandle) to close the handle and then call [OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-opendevicehandle) again to get a new handle. The [IDirect3DDeviceManager9::ResetDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-resetdevice) method invalidates all open device handles.

## See also

[Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager)

[IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9)