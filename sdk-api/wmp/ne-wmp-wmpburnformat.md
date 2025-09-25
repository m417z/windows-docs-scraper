# WMPBurnFormat enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPBurnFormat** enumeration type defines the possible types of CDs for burning.

## Constants

### `wmpbfAudioCD:0`

The CD being burned is an audio CD.

### `wmpbfDataCD`

The CD being burned is a data CD.

## Remarks

Windows Media Player 10 Mobile: This enumeration is not supported.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)

[IWMPCdromBurn::get_burnFormat](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromburn-get_burnformat)

[IWMPCdromBurn::put_burnFormat](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromburn-put_burnformat)