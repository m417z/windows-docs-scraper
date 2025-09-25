# IWMStreamPrioritization::GetPriorityRecords

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetPriorityRecords** method retrieves the list of streams and their priorities from the profile.

## Parameters

### `pRecordArray` [out]

Pointer to an array of **WM_STREAM_PRIORITY_RECORD** structures. This array will receive the current stream priority data.

### `pcRecords` [in, out]

Pointer to a **WORD** that receives the count of records.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pcRecords* is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | *pcRecords* specifies fewer records than exist in the stream prioritization object. |

## Remarks

You should make two calls to **GetPriorityRecords**. On the first call, pass **NULL** as *pRecordArray*. On return, the value of *pcRecords* is set to the number of prioritization records in the stream priority object. Then you can allocate the required amount of memory for the array and pass a pointer to it as *pRecordArray* in the second call.

If you pass an array as *pRecordArray* that does not have enough elements allocated to contain the data, an error code of ASF_E_BUFFERTOOSMALL is returned. When returning this error code, the method still sets the value of *pcRecords*.

Records in a stream prioritization object are given in order of decreasing priority

## See also

[IWMStreamPrioritization Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamprioritization)

[IWMStreamPrioritization::SetPriorityRecords](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamprioritization-setpriorityrecords)

[WM_STREAM_PRIORITY_RECORD](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_stream_priority_record)