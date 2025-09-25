# IWMPCdromBurn::refreshStatus

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **refreshStatus** method updates the status information for the current burn playlist.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You should call this method after you create or change a burn playlist before reading status information or burning the CD. You can test whether a refresh is required by calling **get_burnState** and checking for wmpbsRefreshStatusPending.

Refreshing the status is a synchronous operation. This means that a lengthy period of time might elapse before this method returns if the current burn playlist is large and contains many changes.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPCdromBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromburn)

[IWMPCdromBurn::get_burnState](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromburn-get_burnstate)

[WMPBurnState](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpburnstate)