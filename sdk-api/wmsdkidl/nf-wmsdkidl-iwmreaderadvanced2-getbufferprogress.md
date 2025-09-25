# IWMReaderAdvanced2::GetBufferProgress

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetBufferProgress** method retrieves the percentage of data that has been buffered, and the time remaining to completion.

## Parameters

### `pdwPercent` [out]

Pointer to a **DWORD** containing the percentage of data that has been buffered.

### `pcnsBuffering` [out]

Pointer to variable specifying the time remaining, in 100-nanosecond units, until all the buffering is completed.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

To produce meaningful results, this method must be called between the events WMT_BUFFERING_START and WMT_BUFFERING_STOP. If it is called before a WMT_BUFFERING_START event, then both parameters return zero. If it is called after WMT_BUFFERING_STOP but before a subsequent WMT_BUFFERING_START event, this method returns 100 for the percentage and zero for the buffering time, in seconds. WMT_BUFFERING_START events reset the percentage and seconds remaining to zero.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)

[WMT_PLAY_MODE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_play_mode)