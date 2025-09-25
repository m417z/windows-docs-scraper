# MFCreateContentDecryptorContext function

## Description

Creates an [IMFContentDecryptorContext](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentdecryptorcontext) interface for the specified media protection system.

## Parameters

### `guidMediaProtectionSystemId` [in]

The identifier of the media protection system for which you want to create an [IMFContentDecryptorContext](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentdecryptorcontext) interface.

### `pD3DManager` [in, optional]

Pointer to the [IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager) interface that you want to use for sharing the Direct3D 11 device.

### `pContentProtectionDevice` [in]

The [IMFContentProtectionDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentprotectiondevice) interface for the specified media protection system.

### `ppContentDecryptorContext` [out]

Pointer to the created [IMFContentDecryptorContext](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentdecryptorcontext) interface.

## See also

[IMFContentDecryptorContext](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentdecryptorcontext)

[IMFContentProtectionDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentprotectiondevice)

[IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)