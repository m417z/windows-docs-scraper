# IDirect3DDeviceManager9::GetVideoService

## Description

Gets a DirectX Video Acceleration (DXVA) service interface.

## Parameters

### `hDevice` [in]

A handle to a Direct3D device. To get a device handle, call [IDirect3DDeviceManager9::OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-opendevicehandle).

### `riid` [in]

The interface identifier (IID) of the requested interface. The Direct3D device might support the following DXVA service interfaces:

* [IDirectXVideoDecoderService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoderservice)
* [IDirectXVideoProcessorService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessorservice)

### `ppService` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DXVA2_E_NEW_VIDEO_DEVICE** | The device handle is invalid. |
| **DXVA2_E_NOT_AVAILABLE** | The Direct3D device does not support video acceleration. |
| **DXVA2_E_NOT_INITIALIZED** | The Direct3D device manager was not initialized. The owner of the device must call [IDirect3DDeviceManager9::ResetDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-resetdevice). |
| **E_HANDLE** | The specified handle is not a Direct3D device handle. |

## Remarks

If the method returns **DXVA2_E_NEW_VIDEO_DEVICE**, call [IDirect3DDeviceManager9::CloseDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-closedevicehandle) to close the handle and then call [OpenDeviceHandle](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-opendevicehandle) again to get a new handle. The [IDirect3DDeviceManager9::ResetDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-resetdevice) method invalidates all open device handles.

#### Examples

```cpp
HRESULT GetVideoProcessorService(
    IDirect3DDeviceManager9 *pDeviceManager,
    IDirectXVideoProcessorService **ppVPService
    )
{
    *ppVPService = NULL;

    HANDLE hDevice;

    HRESULT hr = pDeviceManager->OpenDeviceHandle(&hDevice);
    if (SUCCEEDED(hr))
    {
        // Get the video processor service
        HRESULT hr2 = pDeviceManager->GetVideoService(
            hDevice,
            IID_PPV_ARGS(ppVPService)
            );

        // Close the device handle.
        hr = pDeviceManager->CloseDeviceHandle(hDevice);

        if (FAILED(hr2))
        {
            hr = hr2;
        }
    }

    if (FAILED(hr))
    {
        SafeRelease(ppVPService);
    }

    return hr;
}

```

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager)

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9)