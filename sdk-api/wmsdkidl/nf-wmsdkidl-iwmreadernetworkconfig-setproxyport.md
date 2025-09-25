# IWMReaderNetworkConfig::SetProxyPort

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProxyPort** method specifies the proxy port.

## Parameters

### `pwszProtocol` [in]

Pointer to a wide-character null-terminated string containing the protocol.

### `dwPort` [in]

**DWORD** containing the name of the port.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL or invalid argument passed in. |

## Remarks

By default, the port numbers are 1755 for MMS and 80 for HTTP. The correct port number must be set if a port is required. It is not required if the proxy setting is WMT_PROXY_SETTING_AUTO or WMT_PROXY_SETTING_BROWSER.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::GetProxyPort](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getproxyport)

[IWMReaderNetworkConfig::SetProxySettings](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxysettings)