# IMFCaptureSource::GetCaptureDeviceSource

## Description

Gets the current capture device's [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) object pointer.

## Parameters

### `mfCaptureEngineDeviceType` [in]

The capture engine device type.

### `ppMediaSource` [out]

Receives a pointer to the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) that represent the device.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)