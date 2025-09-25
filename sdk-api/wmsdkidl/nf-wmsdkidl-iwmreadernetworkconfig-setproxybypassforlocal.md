# IWMReaderNetworkConfig::SetProxyBypassForLocal

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProxyBypassForLocal** method specifies the configuration setting for bypassing the proxy for local hosts.

## Parameters

### `pwszProtocol` [in]

Pointer to a wide-character null-terminated string containing the protocol.

### `fBypassForLocal` [in]

Boolean value that is True if bypassing the proxy for local hosts is to be enabled (implying that the origin server is on the local network).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL or invalid argument passed in. |

## Remarks

This setting is used only when the proxy setting is WMT_PROXY_SETTING_MANUAL. If the proxy setting is WMT_PROXY_SETTING_BROWSER, the local bypass flag setting in the browser is used instead.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::GetProxyBypassForLocal](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getproxybypassforlocal)

[IWMReaderNetworkConfig::SetProxySettings](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxysettings)