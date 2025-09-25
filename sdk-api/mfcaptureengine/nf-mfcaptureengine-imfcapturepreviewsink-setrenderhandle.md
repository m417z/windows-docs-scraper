# IMFCapturePreviewSink::SetRenderHandle

## Description

Specifies a window for preview.

## Parameters

### `handle` [in]

A handle to the window. The preview sink draws the video frames inside this window.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method overrides any previous call to [IMFCapturePreviewSink::SetSampleCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturepreviewsink-setsamplecallback).

## See also

[IMFCapturePreviewSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturepreviewsink)