# IWMPEvents::ModeChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **ModeChange** event occurs when a mode of the player is changed.

## Parameters

### `ModeName` [in]

Specifies the mode that was changed. Contains one of the following values.

| Value | Description |
| --- | --- |
| shuffle | Tracks are played in random order. |
| loop | The entire sequence of tracks is played repeatedly. |

### `NewValue` [in]

Indicates the new state of the specified mode.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)