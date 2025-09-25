# IWMReaderAdvanced::SetManualStreamSelection

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetManualStreamSelection** method specifies whether stream selection is to be controlled manually. Stream selection applies to outputs associated with mutually exclusive streams. Under normal circumstances, the reader will select the most appropriate stream for an output at time of playback.

## Parameters

### `fSelection` [in]

Boolean value that is True if manual selection is specified.

## Return value

This method always returns S_OK.

## Remarks

When you call this method to enable manual stream selection, all streams in the file are selected. To select specific streams, pass an array of the desired stream numbers to the [IWMReaderAdvanced::SetStreamsSelected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setstreamsselected) method.

When manual stream selection is enabled, you can manage the selected streams using [GetStreamSelected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getstreamselected) and **SetStreamsSelected**.

Stream numbers are in the range of 1 through 63.

## See also

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::GetManualStreamSelection](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getmanualstreamselection)

[To Use Manual Stream Selection](https://learn.microsoft.com/windows/desktop/wmformat/to-use-manual-stream-selection)