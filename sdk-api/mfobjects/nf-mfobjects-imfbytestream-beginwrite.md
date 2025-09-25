# IMFByteStream::BeginWrite

## Description

Begins an asynchronous write operation to the stream.

## Parameters

### `pb` [in]

Pointer to a buffer containing the data to write.

### `cb` [in]

Size of the buffer in bytes.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `punkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When all of the data has been written to the stream, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the application should call [IMFByteStream::EndWrite](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-endwrite) to complete the asynchronous request.

Do not reallocate, free, or write to the buffer while an asynchronous write is still pending.

**Implementation notes:**This method should update the current position in the stream by adding the number of bytes that will be written to the stream, which is specified by the value returned in the *pcbWritten*, to the current position. Other methods that can update the current position are [Read](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-read), [BeginRead](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginread), [Write](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-write), [Seek](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-seek), and [SetCurrentPosition](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-setcurrentposition).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)