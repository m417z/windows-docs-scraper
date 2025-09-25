# IMFDXGIDeviceManager::GetVideoService

## Description

Queries the Microsoft Direct3D device for an interface.

## Parameters

### `hDevice` [in]

A handle to the Direct3D device. To get the device handle, call [IMFDXGIDeviceManager::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-opendevicehandle).

### `riid` [in]

The interface identifier (IID) of the requested interface. The Direct3D device supports the following interfaces:

* [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device). To get a pointer to the Direct3D11 device, use **IID_ID3D11Device** as the *riid*.
* [ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice). To get a pointer to the Direct3D11 video device, use **IID_ID3D11VideoDevice** as the *riid*.

### `ppService` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_HANDLE** | The specified handle is not a Direct3D device handle. |
| **MF_E_DXGI_DEVICE_NOT_INITIALIZED** | The DXGI Device Manager was not initialized. The owner of the device must call [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice). |
| **MF_E_DXGI_NEW_VIDEO_DEVICE** | The device handle is invalid. |
| **E_NOINTERFACE** | If a [ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice) is specified and the D3D device created is using the reference rasterizer or WARP. Or it is a hardware device and you are using the Microsoft Basic Display Adapter. |

## Remarks

If the method returns **MF_E_DXGI_NEW_VIDEO_DEVICE**, call [IMFDXGIDeviceManager::CloseDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-closedevicehandle) to close the handle and then call [OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-opendevicehandle) again to get a new handle. The [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice) method invalidates all open device handles.

For more info see, [Supporting Direct3D 11 Video Decoding in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/supporting-direct3d-11-video-decoding-in-media-foundation).

## See also

[IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager)