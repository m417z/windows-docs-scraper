# IWMReaderAdvanced::SetStreamsSelected

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetStreamsSelected** method specifies which streams are selected when manual stream selection is enabled.

## Parameters

### `cStreamCount` [in]

**WORD** containing the count of stream numbers in the *pwStreamNumbers* array.

### `pwStreamNumbers` [in]

Pointer to an array containing the stream numbers. Stream numbers are in the range of 1 through 63.

### `pSelections` [in]

Pointer to an array, of equal length to *pwStreamNumbers*, with each entry containing one member of the [WMT_STREAM_SELECTION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_stream_selection) enumeration type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

This method enables the selected state of multiple streams to be changed simultaneously. Multiple streams can then be turned on or off at the exact time required. For this reason, the parameters of this method and the **GetStreamSelected** method are not identical.

When selecting streams manually, you should select only one stream at a time from each set of mutually exclusive streams in a file. The SDK does not prevent you from selecting multiple mutually exclusive streams, but the samples for all mutually exclusive streams will be delivered to [IWMReaderCallback::OnSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallback-onsample) using the same output number. This makes it difficult to differentiate between samples from the various streams.

To deliver samples by stream number, you must receive uncompressed stream samples. You can receive stream samples for a specific stream by calling [IWMReaderAdvanced::SetReceiveStreamSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setreceivestreamsamples). You must also implement **IWMReaderCallbackAdvanced::OnStreamSample**.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::GetStreamSelected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getstreamselected)

[To Use Manual Stream Selection](https://learn.microsoft.com/windows/desktop/wmformat/to-use-manual-stream-selection)