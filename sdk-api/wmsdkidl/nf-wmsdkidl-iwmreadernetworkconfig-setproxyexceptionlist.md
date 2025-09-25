# IWMReaderNetworkConfig::SetProxyExceptionList

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProxyExceptionList** method specifies the proxy exception list.

## Parameters

### `pwszProtocol` [in]

Pointer to a wide-character null-terminated string containing the protocol.

### `pwszExceptionList` [in]

Pointer to a wide-character null-terminated string containing the exception list. The list must be a comma-separated list of hosts. Exception lists are limited to 1024 wide characters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL or invalid argument passed in. |

## Remarks

The exception list is a list of computers, domains, or addresses that bypass the proxy host name when the host in the target URL matches an entry in the list.

Wildcard characters can be used in the list entries (using the * character). For example "*.com" would match all hosts in the "com" domain while "67.*" would match all hosts in the 67 class A subnet. The exception list is used only when the proxy setting is WMT_PROXY_SETTING_MANUAL. If the proxy setting is WMT_PROXY_SETTING_BROWSER, then the exception list configured in the browser is used instead.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::GetProxyExceptionList](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getproxyexceptionlist)

[IWMReaderNetworkConfig::SetProxySettings](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxysettings)