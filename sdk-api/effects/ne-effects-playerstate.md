# PlayerState enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **PlayerState** enumeration type provides some basic states of Windows Media Player.

| Number | Description |
| --- | --- |
| 0 | Stop state |
| 1 | Pause state |
| 2 | Play state |

## Constants

### `stop_state:0`

### `pause_state:1`

### `play_state:2`

## Remarks

This enumeration is used by the **TimedLevel** structure.

## See also

[TimedLevel](https://learn.microsoft.com/previous-versions/windows/desktop/api/effects/ns-effects-timedlevel)

[Visualization Structures and Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/visualization-structures-and-enumeration-types)