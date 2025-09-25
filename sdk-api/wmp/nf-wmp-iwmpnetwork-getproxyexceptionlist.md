# IWMPNetwork::getProxyExceptionList

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getProxyExceptionList** method retrieves the proxy exception list.

## Parameters

### `bstrProtocol` [in]

**BSTR** containing the protocol name. For a list of supported protocols, see [Supported Protocols and File Types](https://learn.microsoft.com/windows/desktop/WMP/supported-protocols-and-file-types).

### `pbstrExceptionList` [out]

Pointer to a **BSTR** containing a semicolon-delimited list of hosts for which the proxy server is bypassed. The value retrieved is meaningful only when **IWMPNetwork::getProxySettings** retrieves a value of 2 (use manual settings).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This is a list of computers, domains, and/or addresses that will bypass the proxy server when the host portion of the target URL matches an entry in the list.

The * character can be used as a wildcard for listing entries. For example, *.com would match all hosts in the com domain while 67.* would match all hosts in the 67 class A subnet.

This method fails unless the calling application is running on the local computer or intranet.

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPNetwork Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpnetwork)

[IWMPNetwork::getProxySettings](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-getproxysettings)

[IWMPNetwork::setProxyExceptionList](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-setproxyexceptionlist)