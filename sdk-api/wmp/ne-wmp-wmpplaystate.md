# WMPPlayState enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPPlayState** enumeration type defines the possible operational states of Windows Media Player as it plays a digital media file.

## Constants

### `wmppsUndefined:0`

Windows Media Player is in an undefined state.

### `wmppsStopped`

Playback is stopped.

### `wmppsPaused`

Playback is paused.

### `wmppsPlaying`

Stream is playing.

### `wmppsScanForward`

Stream is scanning forward.

### `wmppsScanReverse`

Stream is scanning backward.

### `wmppsBuffering`

Stream is being buffered.

### `wmppsWaiting`

Waiting for streaming data.

### `wmppsMediaEnded`

The end of the media item has been reached.

### `wmppsTransitioning`

Preparing new media item.

### `wmppsReady`

Ready to begin playing.

### `wmppsReconnecting`

Trying to reconnect for streaming data.

### `wmppsLast`

Last enumerated value. Not a valid state.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)