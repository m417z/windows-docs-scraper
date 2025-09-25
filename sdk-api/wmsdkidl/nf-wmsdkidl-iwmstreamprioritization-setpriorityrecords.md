# IWMStreamPrioritization::SetPriorityRecords

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetPriorityRecords** method assigns the members of an array as the stream priority list in the stream prioritization object.

## Parameters

### `pRecordArray` [in]

Pointer to an array of [WM_STREAM_PRIORITY_RECORD](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_stream_priority_record) structures.

### `cRecords` [in]

Count of records.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *cRecords* specifies a record count greater than zero, but *pRecordArray* is **NULL**.<br><br>OR<br><br>One of the array rules has been broken (see the Remarks section). |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to store the array in the stream prioritization object. |

## Remarks

Valid arrays contain no duplicate stream numbers. Streams are listed in the array in descending priority order. Any stream that is designated as mandatory must occur in the array before any entries that are optional. If any of these rules are broken, **SetPriorityRecords** will return E_INVALIDARG.

**SetPriorityRecords** overwrites an existing stream priority array if there is one. You can clear the array by passing zero for *cRecords*.

This method does not verify that the streams specified are valid for the profile.

## See also

[IWMStreamPrioritization Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamprioritization)

[IWMStreamPrioritization::GetPriorityRecords](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamprioritization-getpriorityrecords)

[WM_STREAM_PRIORITY_RECORD](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_stream_priority_record)