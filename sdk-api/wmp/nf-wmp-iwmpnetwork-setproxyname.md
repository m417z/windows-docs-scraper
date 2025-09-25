# IWMPNetwork::setProxyName

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **setProxyName** method specifies the name of the proxy server to use.

## Parameters

### `bstrProtocol` [in]

**BSTR** containing the protocol name. For a list of supported protocols, see [Supported Protocols and File Types](https://learn.microsoft.com/windows/desktop/WMP/supported-protocols-and-file-types).

### `bstrProxyName` [in]

**BSTR** containing the name of the proxy server to use.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method has no effect unless the value retrieved from **IWMPNetwork::getProxySettings** is 2 (use manual settings).

This method fails unless the calling application is running on the local computer or intranet.

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPNetwork Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpnetwork)

[IWMPNetwork::getProxyName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-getproxyname)

[IWMPNetwork::getProxySettings](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-getproxysettings)