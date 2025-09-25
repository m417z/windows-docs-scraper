# IWMReaderAdvanced2::GetDownloadProgress

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDownloadProgress** method retrieves the percentage and amount of data that has been downloaded, and the time remaining to completion.

## Parameters

### `pdwPercent` [out]

Pointer to a **DWORD** containing the percentage of data that has been downloaded.

### `pqwBytesDownloaded` [out]

Pointer to a **QWORD** containing the number of bytes of data downloaded.

### `pcnsDownload` [out]

Pointer to variable specifying the time remaining, in 100-nanosecond units, for data to be downloaded.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method can be called to monitor progress while content is being downloaded from a Web server.

Content can be downloaded from a Web server when either the play mode is WMT_PLAY_MODE_AUDTOSELECT (in which case the reader automatically adjusts its play mode to DOWNLOAD) or the play mode is explicitly set to WMT_PLAY_MODE_DOWNLOAD.

If one of these two play modes is not current, and this method is called, all parameters return zero.

Before the first WMT_BUFFERING_START event, all the parameters return zero. Between WMT_BUFFERING_START and WMT_END_OF_STREAMING, the values for the percentage of downloading completed and number of bytes downloaded always increase. The value for the number of seconds of downloading remaining can go up or down depending on changing download rates. After WMT_END_OF_STREAMING has been sent, the percentage returns 100, bytes downloaded remains at the size of the download, and seconds remaining is zero.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)

[WMT_PLAY_MODE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_play_mode)