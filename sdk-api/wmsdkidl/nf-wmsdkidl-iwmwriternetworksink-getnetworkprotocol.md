# IWMWriterNetworkSink::GetNetworkProtocol

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetNetworkProtocol** method retrieves the network protocol that the network sink uses. Currently, HTTP is the only protocol the network sink supports.

## Parameters

### `pProtocol` [out]

Pointer to a variable that receives a member of the [WMT_NET_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_net_protocol) enumeration type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pProtocol* is **NULL**. |

## See also

[IWMWriterNetworkSink Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriternetworksink)

[IWMWriterNetworkSink::SetNetworkProtocol](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriternetworksink-setnetworkprotocol)

[WMT_NET_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_net_protocol)