# IWMPSyncDevice3::cancelEstimation

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **cancelEstimation** method cancels an estimation that was previously initiated by [estimateSyncSize](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice3-estimatesyncsize).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When you call this method, Windows Media Player raises the [IWMPEvents4::SyncEstimationComplete](https://learn.microsoft.com/windows/desktop/WMP/iwmpevents4-syncestimationcomplete) event with an **HRESULT** of E_ABORT.

## See also

[IWMPSyncDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice3)