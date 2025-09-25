# IMFCapturePhotoSink::SetSampleCallback

## Description

Sets a callback to receive the still-image data.

## Parameters

### `pCallback` [in]

A pointer to the [IMFCaptureEngineOnSampleCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengineonsamplecallback) interface. The caller must implement this interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method overrides any previous call to [IMFCapturePhotoSink::SetOutputByteStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturephotosink-setoutputbytestream) or [IMFCapturePhotoSink::SetOutputFileName](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturephotosink-setoutputfilename).

## See also

[IMFCapturePhotoSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturephotosink)