# IMFDXGIDeviceManager::ResetDevice

## Description

Sets the Microsoft Direct3D device or notifies the device manager that the Direct3D device was reset.

## Parameters

### `pUnkDevice` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the DXGI device.

### `resetToken` [in]

The token that was received in the *pResetToken* parameter of the [MFCreateDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatedxgidevicemanager) function.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When you first create the DXGI Device Manager, call this method with a pointer to the Direct3D device. (The device manager does not create the device; the caller must provide the device pointer initially.) Also call this method if the Direct3D device becomes lost and you need to reset the device or create a new device.

The *resetToken* parameter ensures that only the component that originally created the device manager can invalidate the current device.

If this method succeeds, all open device handles become invalid.

To create a Microsoft Direct3D 11 device, call [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice).

The device should be created with the **D3D11_CREATE_DEVICE_VIDEO_SUPPORT** device creation flag which is defined in the [D3D11_CREATE_DEVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) enumeration.

It is recommended that you use multi-thread protection on the device context to prevent deadlock issues that can sometimes happen when you call [ID3D11VideoContext::GetDecoderBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-getdecoderbuffer) or [ID3D11VideoContext::ReleaseDecoderBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-releasedecoderbuffer). To set multi-thread protection, first call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) to get an [ID3D10Multithread](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10multithread) pointer. Then call [ID3D10Multithread::SetMultithreadProtected](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10multithread-setmultithreadprotected), passing in **true** for *bMTProtect*.

## See also

[IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager)