# IWMPEvents::PlaylistChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **PlaylistChange** event occurs when a playlist changes.

## Parameters

### `Playlist` [in]

Pointer to an **IDispatch** interface for the playlist that changed.

### `change` [in]

A **WMPPlaylistChangeEventType** enumeration value.

## Remarks

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)

[WMPPlaylistChangeEventType](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpplaylistchangeeventtype)