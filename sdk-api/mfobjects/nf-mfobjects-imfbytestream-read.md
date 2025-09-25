# IMFByteStream::Read

## Description

Reads data from the stream.

## Parameters

### `pb` [in]

Pointer to a buffer that receives the data. The caller must allocate the buffer.

### `cb` [in]

Size of the buffer in bytes.

### `pcbRead` [out]

Receives the number of bytes that are copied into the buffer. This parameter cannot be **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method reads at most *cb* bytes from the current position in the stream and copies them into the buffer provided by the caller. The number of bytes that were read is returned in the *pcbRead* parameter. The method does not return an error code on reaching the end of the file, so the application should check the value in *pcbRead* after the method returns.

This method is synchronous. It blocks until the read operation completes.

 **Implementation notes:**This method should update the current position in the stream by adding the number of bytes that were read, which is specified by the value returned in the *pcbRead* parameter, to the current position. Other methods that can update the current position are **Read**, [Write](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-write), [BeginWrite](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginwrite), [Seek](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-seek), and [SetCurrentPosition](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-setcurrentposition).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

#### Examples

The following example reads data from a byte stream into a caller-allocated media buffer. For more information about media buffers, see [Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers).

```cpp
// Read data from a byte stream into a media buffer.
//
// This function reads a maximum of cbMax bytes, or up to the size of the
// buffer, whichever is smaller. If the end of the byte stream is reached, the
// actual amount of data read might be less than either of these values.
//
// To find out how much data was read, call IMFMediaBuffer::GetCurrentLength.

HRESULT ReadFromByteStream(
    IMFByteStream *pStream,     // Pointer to the byte stream.
    IMFMediaBuffer *pBuffer,    // Pointer to the media buffer.
    DWORD cbMax                 // Maximum amount to read.
    )
{
    DWORD cbBufferMax = 0;
    DWORD cbRead = 0;
    BYTE *pData= NULL;

    HRESULT hr = pBuffer->Lock(&pData, &cbBufferMax, NULL);

    // Do not exceed the maximum size of the buffer.
    if (SUCCEEDED(hr))
    {
        if (cbMax > cbBufferMax)
        {
            cbMax = cbBufferMax;
        }

        // Read up to cbMax bytes.
        hr = pStream->Read(pData, cbMax, &cbRead);
    }

    // Update the size of the valid data in the buffer.
    if (SUCCEEDED(hr))
    {
        hr = pBuffer->SetCurrentLength(cbRead);
    }
    if (pData)
    {
        pBuffer->Unlock();
    }
    return hr;
}

```

The next example is similar, but allocates a new media buffer to hold the data.

**Note** This example uses the [SafeRelease](https://learn.microsoft.com/windows/desktop/medfound/saferelease) function to release interface pointers.

```cpp
//-------------------------------------------------------------------
// AllocReadFromByteStream
//
// Reads data from a byte stream and returns a media buffer that
// contains the data.
//-------------------------------------------------------------------

HRESULT AllocReadFromByteStream(
    IMFByteStream *pStream,         // Pointer to the byte stream.
    DWORD cbToRead,                 // Number of bytes to read.
    IMFMediaBuffer **ppBuffer       // Receives a pointer to the media buffer.
    )
{
    HRESULT hr = S_OK;
    BYTE *pData = NULL;
    DWORD cbRead = 0;   // Actual amount of data read.

    IMFMediaBuffer *pBuffer = NULL;

    // Create the media buffer.
    // This function allocates the memory for the buffer.
    hr = MFCreateMemoryBuffer(cbToRead, &pBuffer);

    // Get a pointer to the memory buffer.
    if (SUCCEEDED(hr))
    {
        hr = pBuffer->Lock(&pData, NULL, NULL);
    }

    // Read the data from the byte stream.
    if (SUCCEEDED(hr))
    {
        hr = pStream->Read(pData, cbToRead, &cbRead);
    }

    // Update the size of the valid data in the buffer.
    if (SUCCEEDED(hr))
    {
        hr = pBuffer->SetCurrentLength(cbRead);
    }

    // Return the pointer to the caller.
    if (SUCCEEDED(hr))
    {
        *ppBuffer = pBuffer;
        (*ppBuffer)->AddRef();
    }

    if (pData)
    {
        pBuffer->Unlock();
    }
    SafeRelease(&pBuffer);
    return hr;
}

```

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)