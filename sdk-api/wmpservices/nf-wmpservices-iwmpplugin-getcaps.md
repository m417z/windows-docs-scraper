# IWMPPlugin::GetCaps

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPPlugin::GetCaps** method returns a flag that specifies whether the plug-in can convert between an input format and an output format.

## Parameters

### `pdwFlags` [out]

Pointer to a variable that specifies whether the plug-in can convert formats. The specified value is a bitwise combination of zero or more flags from the **WMPPlugin_Caps** enumeration.

## Return value

The method returns an **HRESULT**.

## Remarks

There are currently two possible [out] values that the plug-in may specify: zero to indicate that the plug-in can convert formats, or **WMPPlugin_Caps_CannotConvertFormats**, which forces Windows Media Player to handle any necessary format conversion.

## See also

[IWMPPlugin Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpplugin)

[WMPPlugin_Caps](https://learn.microsoft.com/windows/desktop/api/wmpservices/ne-wmpservices-wmpplugin_caps)