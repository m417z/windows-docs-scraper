# IMFSampleOutputStream::BeginWriteSample

## Description

Begins an asynchronous request to write a media sample to the stream.

## Parameters

### `pSample` [in]

A pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the sample.

### `pCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `punkState` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the sample has been written to the stream, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the caller should call [IMFSampleOutputStream::EndWriteSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsampleoutputstream-endwritesample) to complete the asynchronous request.

## See also

[IMFSampleOutputStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsampleoutputstream)