# IWMSyncReader::SetStreamsSelected

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetStreamsSelected** method configures the samples to be delivered from a list of streams. Each stream can be set to deliver all samples, no samples, or only [cleanpoint](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) samples.

## Parameters

### `cStreamCount` [in]

Count of streams listed at *pwStreamNumbers*.

### `pwStreamNumbers` [in]

Pointer to an array of **WORD** values containing the stream numbers.

### `pSelections` [in]

Pointer to an array of [WMT_STREAM_SELECTION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_stream_selection) enumeration values. These values correspond with the stream numbers listed at *pwStreamNumbers*. Each value specifies the samples to deliver for the appropriate stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pwStreamNumbers* or *pSelections* is **NULL**.<br><br>OR<br><br>*cStreamCount* is zero. |
| **NS_E_INVALID_REQUEST** | No file is loaded in the synchronous reader. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for an internal object. |

## Remarks

You can call **SetStreamsSelects** at any time after a file has been loaded into the synchronous reader. You can continue making calls as needed during playback.

This method is identical to [IWMReaderAdvanced::SetStreamsSelected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setstreamsselected) except that, in the synchronous reader, stream selection is always manual. Also, because [IWMSyncReader::GetNextSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getnextsample) includes a stream number output, you can select as many mutually exclusive streams as you like and receive samples for them.

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)