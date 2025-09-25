# MFLockDXGIDeviceManager function

## Description

Locks the shared Microsoft DirectX Graphics Infrastructure (DXGI) Device Manager.

## Parameters

### `pResetToken` [out]

Receives a token that identifies this instance of the DXGI Device Manager. Use this token when calling [IMFDXGIDeviceManager::ResetDevice](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgidevicemanager-resetdevice).
This parameter can be **NULL**.

### `ppManager` [out]

Receives a pointer to the [IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function obtains a pointer to a DXGI Device Manager instance that can be shared between components. The Microsoft Media Foundation platform creates this instance of the DXGI Device Manager as a singleton object. Alternatively, you can create a new DXGI Device Manager by calling [MFCreateDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatedxgidevicemanager).

The first time this function is called, the Media Foundation platform creates the shared DXGI Device Manager.

When you are done use the [IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager) pointer, call the [MFUnlockDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunlockdxgidevicemanager).

## See also

[MFCreateDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatedxgidevicemanager)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)