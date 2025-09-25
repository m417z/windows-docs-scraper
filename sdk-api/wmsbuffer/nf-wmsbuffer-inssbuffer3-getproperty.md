# INSSBuffer3::GetProperty

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProperty** method is used to retrieve a property of the sample in the buffer. Buffer properties are used to pass information along with the sample to the writer object when writing ASF files. Sample properties are GUID values.

## Parameters

### `guidBufferProperty` [in]

**GUID** value identifying the property to retrieve. The predefined buffer properties are described in the [Sample Extension Types](https://learn.microsoft.com/windows/desktop/wmformat/sample-extension-types) section of this documentation. You can also define your own sample extension schemes using your own GUID values.

### `pvBufferProperty` [out]

Pointer to a buffer that will receive the value of the property specified by *guidBufferProperty*.

### `pdwBufferPropertySize` [in, out]

Pointer to a **DWORD** value containing the size of the buffer pointed to by *pvBufferProperty*. If you pass **NULL** for *pvBufferProperty*, the method sets the value pointed to by this parameter to the size required to hold the property value. If you pass a non-**NULL** value for *pvBufferProperty*, the value pointed to by this parameter must equal the size of the buffer pointed to by *pvBufferProperty*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pdwBufferPropertySize* is **NULL**. |
| **NS_E_UNSUPPORTED_PROPERTY** | The property specified as *guidBufferProperty* is not set in this buffer object. |

## See also

[INSSBuffer3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer3)

[INSSBuffer3::SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer3-setproperty)