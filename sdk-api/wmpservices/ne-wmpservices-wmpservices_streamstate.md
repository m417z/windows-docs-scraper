# WMPServices_StreamState enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPServices_StreamState** enumeration indicates whether the stream is currently stopped, paused, or playing.

## Constants

### `WMPServices_StreamState_Stop:0`

The stream is stopped.

### `WMPServices_StreamState_Pause`

The stream is paused.

### `WMPServices_StreamState_Play`

The stream is playing.

## See also

[DSP Plug-in Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/dsp-plug-in-enumeration-types)

[IWMPServices::GetStreamState](https://learn.microsoft.com/windows/desktop/api/wmpservices/nf-wmpservices-iwmpservices-getstreamstate)