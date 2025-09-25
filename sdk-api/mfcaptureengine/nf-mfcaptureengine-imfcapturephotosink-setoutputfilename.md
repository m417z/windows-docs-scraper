# IMFCapturePhotoSink::SetOutputFileName

## Description

Specifies the name of the output file for the still image.

## Parameters

### `fileName` [in]

A null-terminated string that contains the URL of the output file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method overrides any previous call to [IMFCapturePhotoSink::SetOutputByteStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturephotosink-setoutputbytestream) or [IMFCapturePhotoSink::SetSampleCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturephotosink-setsamplecallback).

## See also

[IMFCapturePhotoSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturephotosink)