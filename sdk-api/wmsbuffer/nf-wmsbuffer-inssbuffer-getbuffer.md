# INSSBuffer::GetBuffer

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetBuffer** method retrieves the location of the buffer controlled by the buffer object. Buffers are used to store samples. When passing samples to the writer, you need the location of the buffer so you can copy your samples into it. When you copy data to the address returned by this call, you must call [INSSBuffer::SetLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer-setlength) to specify how much of the buffer actually contains data.

When receiving samples from the reader or synchronous reader, retrieve the size of the buffer at the same time as the location by calling [INSSBuffer::GetBufferAndLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer-getbufferandlength).

## Parameters

### `ppdwBuffer` [out]

Pointer to a pointer to the buffer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppdwBuffer* parameter is **NULL**. |

## See also

[INSSBuffer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer)

[INSSBuffer::GetBufferAndLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer-getbufferandlength)