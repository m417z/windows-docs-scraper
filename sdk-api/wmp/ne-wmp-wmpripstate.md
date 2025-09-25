# WMPRipState enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPRipState** enumeration type defines the possible operational states of Windows Media Player as it rips a CD.

## Constants

### `wmprsUnknown:0`

Not a valid state.

### `wmprsRipping`

Windows Media Player is ripping.

### `wmprsStopped`

The ripping operation is stopped.

## Remarks

Windows Media Player 10 Mobile: This enumeration is not supported.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)

[IWMPCdromRip Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromrip)