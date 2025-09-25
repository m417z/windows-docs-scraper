# IWMReaderNetworkConfig::GetProxyHostName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProxyHostName** method retrieves the name of the host to use as the proxy.

## Parameters

### `pwszProtocol` [in]

Pointer to a string that contains a protocol name, such as "http" or "mms". The string is not case-sensitive.

### `pwszHostName` [out]

Pointer to a buffer that receives the name of the proxy server host. The returned value applies only to the protocol specified in *pwszProtocol*; the reader object supports separate settings for each protocol.

### `pcchHostName` [in, out]

On input, pointer to a variable specifying the size of *pwszHostName*, in characters. On output, the variable contains the length of the string, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_BUFFERTOOSMALL** | The size of the buffer passed in is not large enough to hold the return string. |
| **E_INVALIDARG** | **NULL** or invalid argument passed in. |

## Remarks

Call this method twice. The first time, pass **NULL** as the value for *pwszHostName*. The method returns the size of the string in the *pcchHostName* parameter. Allocate the required amount of memory for the string and call the method again. This time, pass a pointer to the allocated buffer in the *pwszHostName* parameter.

The host name is ignored if the proxy setting is WMT_PROXY_SETTING_AUTO or WMT_PROXY_SETTING_BROWSER.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::SetProxyHostName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyhostname)

[IWMReaderNetworkConfig::SetProxySettings](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxysettings)