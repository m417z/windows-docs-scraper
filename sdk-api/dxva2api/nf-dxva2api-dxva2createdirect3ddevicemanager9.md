# DXVA2CreateDirect3DDeviceManager9 function

## Description

Creates an instance of the [Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager).

## Parameters

### `pResetToken` [out]

Receives a token that identifies this instance of the Direct3D device manager. Use this token when calling [IDirect3DDeviceManager9::ResetDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-resetdevice).

### `ppDeviceManager` [out]

Receives a pointer to the [IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Windows Store apps must use [IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager) and [Direct3D 11 Video APIs](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-apis).

#### Examples

```cpp
HRESULT CreateD3DDeviceManager(
    IDirect3DDevice9 *pDevice,
    UINT *pReset,
    IDirect3DDeviceManager9 **ppManager
    )
{
    UINT resetToken = 0;

    IDirect3DDeviceManager9 *pD3DManager = NULL;

    HRESULT hr = DXVA2CreateDirect3DDeviceManager9(&resetToken, &pD3DManager);

    if (FAILED(hr))
    {
        goto done;
    }

    hr = pD3DManager->ResetDevice(pDevice, resetToken);

    if (FAILED(hr))
    {
        goto done;
    }

    *ppManager = pD3DManager;
    (*ppManager)->AddRef();

    *pReset = resetToken;

done:
    SafeRelease(&pD3DManager);
    return hr;
}

```

## See also

[Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)