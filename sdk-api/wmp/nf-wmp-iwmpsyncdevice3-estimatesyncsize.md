# IWMPSyncDevice3::estimateSyncSize

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **estimateSyncSize** method initiates the estimation of the size required on the device to synchronize a specified playlist.

## Parameters

### `pNonRulePlaylist` [in]

A pointer to an [IWMPPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist) interface that represents the playlist for which the size will be estimated. This parameter can be set to **NULL**. If this argument is specified the estimation will return the size of *pNonRulePlaylist* and the current sync rules, if any.

### `pRulesPlaylist` [in]

A pointer to an [IWMPPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist) interface that represents the playlist for which the size will be estimated. This parameter can be set to **NULL**. If this argument is specified then the current sync rules will be excluded from the estimation so that the estimation will return the size of *pNonRulePlaylist* and *pRulesPlaylist*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Windows Media Player is shutting down, or *pNonRulePlaylist* and *pRulesPlaylist* are both **NULL**. |
| **E_UNEXPECTED** | A synchronization session is already in progress for the device. |

## Remarks

The estimation of required size is done asynchronously. That is, this method initiates the estimation and then returns immediately. When the estimation is complete, Windows Media Player raises the [IWMPEvents4::SyncEstimationComplete](https://learn.microsoft.com/windows/desktop/WMP/iwmpevents4-syncestimationcomplete) event.

The estimation cannot occur if a synchronization session is currently in progress for the device.

If you call this method and then call it again before the first estimation is complete, the first estimation is canceled and a new estimation is initiated.

## See also

[IWMPSyncDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice3)