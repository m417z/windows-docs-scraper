# IMFCapturePhotoSink::SetOutputByteStream

## Description

Specifies a byte stream that will receive the still image data.

## Parameters

### `pByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The byte stream must be writable.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method overrides any previous call to [IMFCapturePhotoSink::SetOutputFileName](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturephotosink-setoutputfilename) or [IMFCapturePhotoSink::SetSampleCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturephotosink-setsamplecallback).

## See also

[IMFCapturePhotoSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturephotosink)