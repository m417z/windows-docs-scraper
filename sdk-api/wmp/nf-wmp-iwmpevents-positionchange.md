# IWMPEvents::PositionChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **PositionChange** event occurs when the current playback position within the media item has been changed.

## Parameters

### `oldPosition` [in]

Specifies the original position.

### `newPosition` [in]

Specifies the new position.

## Remarks

This event is not raised routinely during playback. It only occurs when something actively changes the current playback position within the playing media item, such as the user moving the seek handle or code specifying a value for **IWMPControls::currentPosition**.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)