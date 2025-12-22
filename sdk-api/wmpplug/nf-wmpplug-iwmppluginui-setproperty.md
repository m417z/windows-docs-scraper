# IWMPPluginUI::SetProperty

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProperty** method is called by Windows Media Player to set name/value property pairs for the plug-in.

## Parameters

### `pwszName` [in]

Pointer to a **WCHAR****NULL**-terminated string constant containing the name of the property. Contains one of the following values:

| Value | Description |
| --- | --- |
| PLUGIN_MISC_CURRENTPRESET = L"CurrentPreset" | The *pvarProperty* parameter contains a **Long** (**VT_I4**) value that specifies the index of the plug-in preset which is to be made current. |
| PLUGIN_ALL_MEDIASENDTO = L"MediaSendTo" | The *pvarProperty* parameter contains an array of **IUnknown** (**VT_ARRAY** \| **VT_UNKNOWN**) pointers for **Media** objects that are sent to the plug-in from the Playlist control. |
| PLUGIN_ALL_PLAYLISTSENDTO = L"PlaylistSendTo" | The *pvarProperty* parameter contains an array of **IUnknown** (**VT_ARRAY** \| **VT_UNKNOWN**) pointers for **Playlist** objects that are sent to the plug-in from the library. |

### `pvarProperty` [in]

Pointer to a **VARIANT** containing the new value of the property.

## Return value

This method returns an **HRESULT**.

## Remarks

Windows Media Player determines the type and capabilities of a plug-in by checking the Windows registry, and will specify only properties that the plug-in supports.

**Media** and **Playlist** objects are sent to the plug-in as arrays of **IUnknown** pointers. The plug-in can call **QueryInterface** on these pointers to retrieve **IWMPMedia** or **IWMPPlaylist** interfaces.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPPluginUI Interface](https://learn.microsoft.com/windows/desktop/api/wmpplug/nn-wmpplug-iwmppluginui)

[Media Object](https://learn.microsoft.com/windows/desktop/WMP/media-object)