# MFCreateDXGIDeviceManager function

## Description

Creates an instance of the Microsoft DirectX Graphics Infrastructure (DXGI) Device Manager.

## Parameters

### `resetToken` [out]

Receives a token that identifies this instance of the DXGI Device Manager. Use this token when calling [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice).

### `ppDeviceManager` [out]

Receives a pointer to the [IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When you create an [IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager) with **MFCreateDXGIDeviceManager**, a Microsoft Direct3D 11 device is not associated with the device manager. To associate a Direct3D 11 device with the device manager, call [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice), passing in the pointer to the Direct3D 11 device. To create a Direct3D 11 device, call [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice). The device should be created with the **D3D11_CREATE_DEVICE_VIDEO_SUPPORT** device creation flag which is defined in the [D3D11_CREATE_DEVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) enumeration.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)