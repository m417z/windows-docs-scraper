# IWMReaderNetworkConfig::GetProxyBypassForLocal

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProxyBypassForLocal** method queries whether the reader object bypasses the proxy server for local URLs.

## Parameters

### `pwszProtocol` [in]

Pointer to a string that contains a protocol name, such as "http" or "mms". The string is not case-sensitive.

### `pfBypassForLocal` [out]

Pointer to a variable that receives a Boolean value. If the value is **TRUE**, the reader bypasses the proxy server when it retrieves a URL from a local host. If the value is **FALSE**, the reader always goes through the proxy server (if any). The returned value applies only to the protocol specified in *pwszProtocol*; the reader object supports separate settings for each protocol.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | **NULL** or invalid argument passed in. |
| **E_OUTOFMEMORY** | Insufficient memory to complete task |

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::SetProxyBypassForLocal](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxybypassforlocal)