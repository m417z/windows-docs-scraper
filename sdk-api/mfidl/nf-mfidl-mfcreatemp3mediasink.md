# MFCreateMP3MediaSink function

## Description

Creates the MP3 media sink.

## Parameters

### `pTargetByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The media sink writes the MP3 file to this byte stream. The byte stream must be writable.

### `ppMediaSink` [out]

Receives a pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface of the MP3 media sink.. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The MP3 media sink takes compressed MP3
audio samples as input, and writes an MP3 file with ID3 headers as output. The MP3 media sink does not perform MP3 audio encoding.

#### Examples

```cpp
HRESULT CreateMP3Sink(PCWSTR pszOutputFile, IMFMediaSink **ppSink)
{
    *ppSink = NULL;

    IMFByteStream* pStream = NULL;

    // Create a byte stream for the output file.
    HRESULT hr =  MFCreateFile(
        MF_ACCESSMODE_WRITE,
        MF_OPENMODE_DELETE_IF_EXIST,
        MF_FILEFLAGS_NONE,
        pszOutputFile,
        &pStream
        );

    // Create the MP3 media sink.
    if (SUCCEEDED(hr))
    {
        hr =  MFCreateMP3MediaSink(pStream, ppSink);
    }

    SafeRelease(&pStream);
    return hr;
}

```

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)