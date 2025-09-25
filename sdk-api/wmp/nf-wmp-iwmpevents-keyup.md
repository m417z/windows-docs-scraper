# IWMPEvents::KeyUp

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **KeyUp** event occurs when a key is released.

## Parameters

### `nKeyCode` [in]

Specifies which physical key is pressed. For possible values, see the Remarks section of the **KeyDown** event.

### `nShiftState` [in]

A bitfield with the least significant bits corresponding to the SHIFT key (bit 0), the CTRL key (bit 1), and the ALT key (bit 2). These bits correspond to the values 1, 2, and 4, respectively. The shift argument indicates the state of these keys. Some, all, or none of the bits can be set, indicating that some, all, or none of the keys are pressed.

## Remarks

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)

[KeyDown](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents-keydown)