# IWMReaderNetworkConfig2::SetAutoReconnectLimit

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAutoReconnectLimit** method sets the maximum number of times the reader will attempt to reconnect to the server in the case of an unexpected disconnection. This feature, called Fast Reconnect, applies only to content being streamed from a server running Windows Media Services.

## Parameters

### `dwAutoReconnectLimit` [in]

Specifies the maximum number of times the reader object will attempt to reconnect. To disable automatic reconnection, set this value to zero.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The method configures the Fast Reconnect feature, which enables the reader object to reconnect to the server automatically if it loses the connection. When possible, playback resumes at the same point in the stream. The accuracy may depend on whether the source file is indexed. For live content, there may be a gap in the stream.

The reader only tries to reconnect if the interruption is unexpected. For example, it does not try to reconnect if the server denies access because of an authentication failure, if the server terminates the connection because of client inactivity, if the server administrator terminates the connection, and so forth.

This method is equivalent to setting the WMReconnect modifier in the URL. For example:

mms://MyServer/MyVideo.wmv?WMReconnect=5

## See also

[IWMReaderNetworkConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig2)

[IWMReaderNetworkConfig2::GetAutoReconnectLimit](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig2-getautoreconnectlimit)