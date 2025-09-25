# IWMPEffects2::NotifyNewMedia

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **NotifyNewMedia** method is called by Windows Media Player to inform the visualization that a new media item has been loaded.

## Parameters

### `pMedia` [in]

Pointer to an **IWMPMedia** interface that represents the new media item.

## Return value

This method returns an **HRESULT**.

## See also

[IWMPEffects2 Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects2)