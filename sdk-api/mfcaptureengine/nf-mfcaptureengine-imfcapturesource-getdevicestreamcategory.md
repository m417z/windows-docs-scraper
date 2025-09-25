# IMFCaptureSource::GetDeviceStreamCategory

## Description

Gets the stream category for the specified source stream index.

## Parameters

### `dwSourceStreamIndex` [in]

The index of the source stream.

### `pStreamCategory` [out]

Receives the MF_CAPTURE_ENGINE_STREAM_CATEGORY of the specified source stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)