# IWMPEvents::OpenStateChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OpenStateChange** event occurs when the Windows Media Player control changes state.

## Parameters

### `NewState` [in]

Specifies the new open state.

## Remarks

Windows Media Player can go through several open states while it attempts to open a file over a network, such as locating the server, connecting to the server, and opening the file. This event will be fired each time the open state changes.

Windows Media Player states are not guaranteed to occur in any particular order. Furthermore, not every state necessarily occurs during a sequence of events. You should not write code that relies upon state order.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)