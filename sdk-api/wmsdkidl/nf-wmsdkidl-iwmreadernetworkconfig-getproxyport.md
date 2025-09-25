# IWMReaderNetworkConfig::GetProxyPort

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProxyPort** method retrieves the port number of the proxy server.

## Parameters

### `pwszProtocol` [in]

Pointer to a string that contains a protocol name, such as "http" or "mms". The string is not case-sensitive.

### `pdwPort` [out]

Pointer to a variable that receives the port number. The returned value applies only to the protocol specified in *pwszProtocol*; the reader object supports separate settings for each protocol.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_BUFFERTOOSMALL** | The size of the buffer passed in is not large enough to hold the return string. |
| **E_INVALIDARG** | NULL or invalid argument passed in. |

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::SetProxyPort](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyport)