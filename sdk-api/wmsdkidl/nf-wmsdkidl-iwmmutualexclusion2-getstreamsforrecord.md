# IWMMutualExclusion2::GetStreamsForRecord

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreamsForRecord** method retrieves the list of streams that are present in a record.

## Parameters

### `wRecordNumber` [in]

**WORD** containing the record number for which to retrieve the streams.

### `pwStreamNumArray` [out]

Pointer to an array that will receive the stream numbers. If it is **NULL**, **GetStreamsForRecord** will return the number of streams to *pcStreams*.

### `pcStreams` [in, out]

Pointer to a **WORD** containing the number of streams in the record.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pcStreams* is **NULL**.<br><br>OR<br><br>*wRecordNumber* does not contain a valid record number. |
| **ASF_E_BUFFERTOOSMALL** | The value passed as *pcStreams* is smaller than the number of streams in the record. On exit with this error code, the value at *pcStreams* will contain the correct number of streams. |
| **E_FAIL** | The method is unable to access the record for an unspecified reason. |

## Remarks

You should make two calls to **GetStreamsForRecord**. On the first call, pass **NULL** as *pwStreamNumArray*. On return, the value of *pcStreams* is set to the number of streams. Then you can allocate the amount of memory needed to hold the array and pass a pointer to it as *pwStreamNumArray* on the second call.

If you pass an array that is not large enough to contain all of the streams, an error code of ASF_E_BUFFERTOOSMALL is returned. When returning this error code, the method still sets the value at *pcStreams* to the correct number of streams.

## See also

[IWMMutualExclusion2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion2)