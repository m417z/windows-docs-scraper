# IWMReaderNetworkConfig::ResetProtocolRollover

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **ResetProtocolRollover** method forces the reader object to use the normal protocol rollover algorithm.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

Protocol rollover is a process whereby the reader object discovers the best streaming protocol available from a server. For more information, see [Protocol Rollover](https://learn.microsoft.com/windows/desktop/wmformat/protocol-rollover).

When the reader object uses protocol rollover, it records which protocol was used and tries that protocol first on subsequent connection attempts. After a certain period of time, the reader object goes back to the default protocol rollover behavior.

However, if the application disables a particular protocol (for example, by calling **SetEnableUDP** or **SetEnableTCP**), the reader object may use a protocol that is less efficient than necessary. You can force the reader object to use the default protocol rollover behavior by calling the **ResetProtocolRollover** method.

Player users sometimes experiment with network settings when they are having connectivity problems. By using this method to reset the protocol rollover settings, the application can improve the quality of streaming that users receive.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::SetEnableUDP](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setenableudp)