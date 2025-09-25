# INSSBuffer::GetBufferAndLength

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetBufferAndLength** method retrieves the location and size of the used portion of the buffer controlled by the buffer object. Buffers are used to store samples. When reading ASF files, you can use the location and length to copy a sample from a buffer delivered by the reader or synchronous reader.

## Parameters

### `ppdwBuffer` [out]

Pointer to a pointer to the buffer.

### `pdwLength` [out]

Pointer to a **DWORD** containing the length of the buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppdwBuffer* or *pdwLength* parameter is **NULL**. |

## See also

[INSSBuffer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer)

[INSSBuffer::GetBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer-getbuffer)