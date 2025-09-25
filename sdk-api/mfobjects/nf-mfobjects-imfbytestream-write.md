# IMFByteStream::Write

## Description

Writes data to the stream.

## Parameters

### `pb` [in]

Pointer to a buffer that contains the data to write.

### `cb` [in]

Size of the buffer in bytes.

### `pcbWritten` [out]

Receives the number of bytes that are written.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method writes the contents of the *pb* buffer to the stream, starting at the current stream position. The number of bytes that were written is returned in the *pcbWritten* parameter.

This method is synchronous. It blocks until the write operation completes.

**Implementation notes:**This method should update the current position in the stream by adding the number of bytes that were written to the stream, which is specified by the value returned in the *pcbWritten*, to the current position offset.

 Other methods that can update the current position are [Read](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-read), [BeginRead](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginread), [BeginWrite](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginwrite), [Seek](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-seek), and [SetCurrentPosition](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-setcurrentposition).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

#### Examples

The following example writes data from a media buffer to a byte stream. For more information about media buffers, see [Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers).

```cpp
//-------------------------------------------------------------------
// WriteBufferToByteStream
//
// Writes data from a media buffer to a byte stream.
//-------------------------------------------------------------------

HRESULT WriteBufferToByteStream(
    IMFByteStream *pStream,   // Pointer to the byte stream.
    IMFMediaBuffer *pBuffer,  // Pointer to the media buffer.
    DWORD *pcbWritten         // Receives the number of bytes written.
    )
{
    HRESULT hr = S_OK;
    DWORD cbData = 0;
    DWORD cbWritten = 0;
    BYTE *pMem = NULL;

    hr = pBuffer->Lock(&pMem, NULL, &cbData);

    if (SUCCEEDED(hr))
    {
        hr = pStream->Write(pMem, cbData, &cbWritten);
    }

    if (SUCCEEDED(hr))
    {
        if (pcbWritten)
        {
            *pcbWritten = cbWritten;
        }
    }

    if (pMem)
    {
        pBuffer->Unlock();
    }
    return hr;
}

```

The following function template writes a typed variable to a byte stream.

```
template <class T>
HRESULT WriteToStream(
    IMFByteStream *pStream, // Pointer to the byte stream.
    const T* p,             // Data to write to the stream.
    ULONG cb = sizeof(T)    // Size of the data in bytes.
)
{
    ULONG cbWritten = 0;
    HRESULT hr = S_OK;

    hr = pStream->Write((const BYTE*)p, cb, &cbWritten);
    if (SUCCEEDED(hr) && (cbWritten != cb))
    {
        hr = E_FAIL;
    }
    return hr;
}
```

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)