# WMT_PROXY_SETTINGS enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_PROXY_SETTINGS** enumeration type defines network proxy settings for use with a reader object.

## Constants

### `WMT_PROXY_SETTING_NONE:0`

No proxy settings will be used.

### `WMT_PROXY_SETTING_MANUAL:1`

Proxy settings will be explicitly set.

### `WMT_PROXY_SETTING_AUTO:2`

Proxy settings will be automatically negotiated.

### `WMT_PROXY_SETTING_BROWSER:3`

The browser will negotiate the proxy settings. This applies only when using HTTP.

### `WMT_PROXY_SETTING_MAX`

## Remarks

The WMT_PROXY_SETTING_BROWSER setting applies only to the HTTP protocol.

This enumeration is used directly in **GetProxySettings** and **SetProxySettings**, and referenced in several other methods of the **IWMReaderNetworkConfig** interface.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)

[IWMReaderNetworkConfig::GetProxySettings](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getproxysettings)

[IWMReaderNetworkConfig::SetProxySettings](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxysettings)