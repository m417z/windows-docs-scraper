# IWMWriterSink::IsRealTime

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IsRealTime** is called by the writer to determine whether the sink needs data units to be delivered in real time. It is up to you to decide whether your custom sink requires real-time delivery.

## Parameters

### `pfRealTime` [out]

Pointer to a Boolean value that is True if the sink requires real time data unit delivery.

## Return value

This method is implemented by the application. It should always return S_OK.

## See also

[IWMWriterSink Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwritersink)