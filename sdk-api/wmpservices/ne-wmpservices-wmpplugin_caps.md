# WMPPlugin_Caps enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPPlugin_Caps** enumeration type signals whether the plug-in can convert between input and output formats.

## Constants

### `WMPPlugin_Caps_CannotConvertFormats:1`

The plug-in requires that the input format and output format be the same.

## Remarks

When **IWMPPlugin::GetCaps** returns **WMPPlugin_Caps_CannotConvertFormats**, Windows Media Player handles any necessary format conversion.

## See also

[DSP Plug-in Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/dsp-plug-in-enumeration-types)

[IWMPPlugin::GetCaps](https://learn.microsoft.com/previous-versions/aa391071(v=vs.85))