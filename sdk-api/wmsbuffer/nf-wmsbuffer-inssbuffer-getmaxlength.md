# INSSBuffer::GetMaxLength

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMaxLength** method retrieves the maximum size to which a buffer can be set. The maximum value is set when the sample is created. If you are using [IWMWriter::AllocateSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-allocatesample), the size you specify becomes the maximum buffer length. The actual amount of the buffer that is used can be retrieved by calling [INSSBuffer::GetLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer-getlength).

## Parameters

### `pdwLength` [out]

Pointer to a **DWORD** containing the maximum length, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pdwLength* parameter is **NULL**. |

## Remarks

The maximum size of the buffer as returned by this method does not affect or reflect the size of any data unit extensions associated with the sample stored in the buffer.

## See also

[Data Unit Extensions](https://learn.microsoft.com/windows/desktop/wmformat/data-unit-extensions)

[INSSBuffer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer)

[INSSBuffer::GetLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer-getlength)