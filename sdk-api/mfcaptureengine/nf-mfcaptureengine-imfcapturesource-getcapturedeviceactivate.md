# IMFCaptureSource::GetCaptureDeviceActivate

## Description

 Gets the current capture device's [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) object pointer.

## Parameters

### `mfCaptureEngineDeviceType` [in]

The capture engine device type.

### `ppActivate` [out]

Receives the pointer to a [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) that represents a device.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)