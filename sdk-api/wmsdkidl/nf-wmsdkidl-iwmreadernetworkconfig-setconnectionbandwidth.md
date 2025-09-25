# IWMReaderNetworkConfig::SetConnectionBandwidth

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetConnectionBandwidth** method specifies the connection bandwidth for the client.

## Parameters

### `dwConnectionBandwidth` [in]

Specifies the maximum bandwidth for the connection, in bits per second. Specify zero for the reader to automatically detect the bandwidth

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL or invalid argument passed in. |

## Remarks

By default, the SDK automatically detects the bandwidth of the connection to the server. When auto-detection is set, a call to **GetConnectionBandwidth** following the [Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-open) request returns the dynamically detected connection bandwidth.

Setting a bandwidth by using this method is sometimes called *bandwidth-throttling* because it deliberately limits the available bandwidth.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::GetConnectionBandwidth](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getconnectionbandwidth)