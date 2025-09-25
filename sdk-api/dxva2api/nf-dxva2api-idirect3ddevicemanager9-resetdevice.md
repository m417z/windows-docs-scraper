# IDirect3DDeviceManager9::ResetDevice

## Description

Sets the Direct3D device or notifies the device manager that the Direct3D device was reset.

## Parameters

### `pDevice` [in]

Pointer to the **IDirect3DDevice9** interface of the Direct3D device.

### `resetToken` [in]

Token received in the *pResetToken* parameter of the [DXVA2CreateDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-dxva2createdirect3ddevicemanager9) function.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid token |
| **D3DERR_INVALIDCALL** | Direct3D device error. |

## Remarks

When you first create the Direct3D device manager, call this method with a pointer to the Direct3D device. The device manager does not create the device; the caller must provide the device pointer initially.

Also call this method if the Direct3D device becomes lost and you need to reset the device or create a new device. This occurs if **IDirect3DDevice9::TestCooperativeLevel** returns D3DERR_DEVICELOST or D3DERR_DEVICENOTRESET. For more information about lost devices, see the Direct3D documentation.

The *resetToken* parameter ensures that only the component which originally created the device manager can invalidate the current device.

If this method succeeds, all open device handles become invalid.

## See also

[Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager)

[IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9)