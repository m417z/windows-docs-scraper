# IMFASFIndexer::GetCompletedIndex

## Description

Retrieves the completed index from the ASF indexer object.

## Parameters

### `pIIndexBuffer` [in]

Pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of a media buffer that receives the index data.

### `cbOffsetWithinIndex` [in]

The offset of the data to be retrieved, in bytes from the start of the index data. Set to 0 for the first call. If subsequent calls are needed (the buffer is not large enough to hold the entire index), set to the byte following the last one retrieved.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INDEX_NOT_COMMITTED** | The index was not committed before attempting to get the completed index. For more information, see Remarks. |

## Remarks

This method uses as much of the buffer as possible, and updates the length of the buffer appropriately.

If *pIIndexBuffer* is large enough to contain the entire buffer, *cbOffsetWithinIndex* should be 0, and the call needs to be made only once. Otherwise, there should be no gaps between successive buffers.

The user must write this data to the content at *cbOffsetFromIndexStart* bytes after the end of the ASF data object. You can call [IMFASFIndexer::GetIndexPosition](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getindexposition) to determine the start position of the ASF index.

This call will not succeed unless [IMFASFIndexer::CommitIndex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-commitindex) has been called. After calling **GetCompletedIndex**, the caller must call [IMFASFContentInfo::GenerateHeader](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-generateheader) and overwrite the existing ASF header with the new header; otherwise, the ASF header will not match the content, and the file is not guaranteed to play correctly.

You cannot use this method in an index reading scenario. You can only use this method when writing indexes.

#### Examples

The following example shows how to write the complete ASF index to a byte stream.

```cpp
HRESULT WriteASFIndex(IMFASFIndexer *pIndex,IMFByteStream *pStream)
{
    const DWORD cbChunkSize = 4096;

    IMFMediaBuffer *pBuffer = NULL;

    QWORD cbIndex = 0;
    DWORD cbIndexWritten = 0;

    HRESULT hr = pIndex->GetIndexWriteSpace(&cbIndex);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = MFCreateMemoryBuffer(cbChunkSize, &pBuffer);
    if (FAILED(hr))
    {
        goto done;
    }

    while (cbIndexWritten < cbIndex)
    {
        BYTE *pData = NULL;
        DWORD cbData = 0;
        DWORD cbWritten = 0;

        hr = pIndex->GetCompletedIndex(pBuffer, cbIndexWritten);
        if (FAILED(hr))
        {
            goto done;
        }

        hr = pBuffer->Lock(&pData, NULL, &cbData);
        if (FAILED(hr))
        {
            goto done;
        }

        hr = pStream->Write(pData, cbData, &cbWritten);

        (void)pBuffer->Unlock();

        if (FAILED(hr))
        {
            goto done;
        }

        cbIndexWritten += cbData;
    }

done:
    SafeRelease(&pBuffer);
    return hr;
};

```

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)

[Using the Indexer to Write a New Index](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd757932(v=vs.85))