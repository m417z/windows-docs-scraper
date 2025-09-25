# IWMReaderAdvanced2::StopBuffering

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **StopBuffering** method requests that the reader send the WMT_BUFFERING_STOP message as soon as possible.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

The reader responds to the request to stop buffering only if it is currently buffering data. This means it has sent a WMT_BUFFERING_START message, but not sent the corresponding WMT_BUFFERING_STOP. There is, however, no guarantee of how quickly the reader responds to the request. This feature is particularly useful when the play mode is set to WMT_PLAY_MODE_DOWNLOAD.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)

[WMT_PLAY_MODE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_play_mode)