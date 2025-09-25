# IMFSampleOutputStream::EndWriteSample

## Description

Completes an asynchronous request to write a media sample to the stream.

## Parameters

### `pResult` [in]

A pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method when the [IMFSampleOutputStream::BeginWriteSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsampleoutputstream-beginwritesample) method completes asynchronously.

## See also

[IMFSampleOutputStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsampleoutputstream)