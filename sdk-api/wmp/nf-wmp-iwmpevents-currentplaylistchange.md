# IWMPEvents::CurrentPlaylistChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CurrentPlaylistChange** event occurs when something changes within the current playlist.

## Parameters

### `change` [in]

Specifies what type of change occurred to the playlist. See the **PlaylistChange** event for a table of possible values.

## Remarks

This event does not occur when a different playlist becomes the current playlist. It only occurs when a change happens within the current playlist, such as a media item being appended to the playlist.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)

[PlaylistChange](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents-playlistchange)