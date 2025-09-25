# IWMPNetwork::getProxySettings

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getProxySettings** method retrieves the proxy setting for a given protocol.

## Parameters

### `bstrProtocol` [in]

**BSTR** containing the protocol name. For a list of supported protocols, see [Supported Protocols and File Types](https://learn.microsoft.com/windows/desktop/WMP/supported-protocols-and-file-types).

### `plProxySetting` [out]

Pointer to a **long** containing one of the following values.

| Value | Description |
| --- | --- |
| 0 | A proxy server is not being used. |
| 1 | The proxy settings for the current browser are being used (only valid for HTTP). |
| 2 | The manually specified proxy settings are being used. |
| 3 | The proxy settings are being auto-detected. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method fails unless the calling application is running on the local computer or intranet.

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPNetwork Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpnetwork)

[IWMPNetwork::setProxySettings](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-setproxysettings)