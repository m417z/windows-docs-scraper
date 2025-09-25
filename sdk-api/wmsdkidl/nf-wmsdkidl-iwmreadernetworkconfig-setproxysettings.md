# IWMReaderNetworkConfig::SetProxySettings

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProxySettings** method specifies the proxy settings.

## Parameters

### `pwszProtocol` [in]

Pointer to a wide-character null-terminated string containing the protocol name. Supported names are HTTP and MMS.

### `ProxySetting` [in]

A value from the [WMT_PROXY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_proxy_settings) enumeration type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL or invalid argument passed in. |

## Remarks

Setting the protocol to WMT_PROXY_SETTING_MANUAL causes the reader to use the proxy settings from [SetProxyHostName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyhostname) and [SetProxyPort](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyport). Setting it to WMT_PROXY_SETTING_AUTO uses Web Proxy Auto-Detect mechanisms to dynamically determine the appropriate proxy based on the specified URL. Setting the protocol to WMT_PROXY_SETTING_BROWSER is valid only for HTTP URLs, and causes the reader to use the proxy settings that are configured in the browser.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::GetProxySettings](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getproxysettings)

[IWMReaderNetworkConfig::SetProxyHostName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyhostname)

[IWMReaderNetworkConfig::SetProxyPort](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyport)

[WMT_PROXY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_proxy_settings)