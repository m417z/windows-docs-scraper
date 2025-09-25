# WMT_NET_PROTOCOL enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_STREAM_SELECTION** enumeration type defines the types of protocols that the network sink supports.

## Constants

### `WMT_PROTOCOL_HTTP:0`

The network sink supports hypertext transfer protocol (HTTP).

## Remarks

This enumeration is used in two methods, **GetNetworkProtocol** and **SetNetworkProtocol**, from the **IWMWriterNetworkSink** interface.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)

[IWMWriterNetworkSink::GetNetworkProtocol](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriternetworksink-getnetworkprotocol)

[IWMWriterNetworkSink::SetNetworkProtocol](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriternetworksink-setnetworkprotocol)