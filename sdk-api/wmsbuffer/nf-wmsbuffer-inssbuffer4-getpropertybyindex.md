# INSSBuffer4::GetPropertyByIndex

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetPropertyByIndex** method retrieves a buffer property, also called a data unit extension, that was set using [INSSBuffer3::SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer3-setproperty). This method differs from [INSSBuffer3::GetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer3-getproperty) in that, instead of accessing the property by name, it uses an index ranging from zero to one less than the total number of properties associated with the sample.

## Parameters

### `dwBufferPropertyIndex` [in]

**DWORD** containing the buffer property index. This value will be between zero and one less than the total number of properties associated with the sample. You can retrieve the total number of properties by calling [INSSBuffer4::GetPropertyCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer4-getpropertycount).

### `pguidBufferProperty` [out]

Pointer to a GUID specifying the type of buffer property.

### `pvBufferProperty` [out]

Void pointer containing the value of the buffer property.

### `pdwBufferPropertySize` [in, out]

Pointer to a **DWORD** containing the size of the value pointed to by *pvBufferProperty*. If you set *pvBufferProperty* to **NULL**, this value will be set to the required size in bytes of the buffer needed to store the property value.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[INSSBuffer4 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer4)