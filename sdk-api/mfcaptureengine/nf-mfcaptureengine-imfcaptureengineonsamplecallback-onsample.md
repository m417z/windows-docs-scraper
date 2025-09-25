# IMFCaptureEngineOnSampleCallback::OnSample

## Description

Called when the capture sink receives a sample.

## Parameters

### `pSample` [in, optional]

A pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface. Use this interface to get the time stamp, duration, and stream data. For more information, see [Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples). This parameter can be **NULL**, so make sure to check for a **NULL** value before you dereference the pointer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureEngineOnSampleCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengineonsamplecallback)