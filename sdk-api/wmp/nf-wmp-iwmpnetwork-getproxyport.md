# IWMPNetwork::getProxyPort

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getProxyPort** method retrieves the proxy port being used.

## Parameters

### `bstrProtocol` [in]

**BSTR** containing the protocol name. For a list of supported protocols, see [Supported Protocols and File Types](https://learn.microsoft.com/windows/desktop/WMP/supported-protocols-and-file-types).

### `lProxyPort` [out]

**long** containing the proxy port being used. The value retrieved is meaningful only when **IWMPNetwork::getProxySettings** retrieves a value of 2 (use manual settings).

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

[IWMPNetwork::getProxySettings](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-getproxysettings)

[IWMPNetwork::setProxyPort](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-setproxyport)