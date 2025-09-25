# IMFCapturePreviewSink::SetSampleCallback

## Description

Sets a callback to receive the preview data for one stream.

## Parameters

### `dwStreamSinkIndex` [in]

The zero-based index of the stream. The index is returned in the *pdwSinkStreamIndex* parameter of the [IMFCaptureSink::AddStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-addstream) method.

### `pCallback` [in]

A pointer to the [IMFCaptureEngineOnSampleCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengineonsamplecallback) interface. The caller must implement this interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method overrides any previous call to [IMFCapturePreviewSink::SetRenderHandle](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturepreviewsink-setrenderhandle).

## See also

[IMFCapturePreviewSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturepreviewsink)