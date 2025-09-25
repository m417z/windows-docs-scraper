# IWMPPluginUI::GetProperty

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProperty** method is called by Windows Media Player to retrieve name/value property pairs from the plug-in.

## Parameters

### `pwszName` [in]

Pointer to a **WCHAR****NULL**-terminated string constant containing the name of the property. Contains one of the following values:

| Value | Description |
| --- | --- |
| PLUGIN_MISC_CURRENTPRESET = L"CurrentPreset" | The out parameter is set to a **Long** (**VT_I4**) value containing the index of the current preset. This property is requested only for plug-ins that have presets. |
| PLUGIN_MISC_PRESETCOUNT = L"PresetCount" | The out parameter is set to a **Long** (**VT_I4**) value indicating the number of presets available in the plug-in. This property is requested only for plug-ins that have presets. |
| PLUGIN_MISC_PRESETNAMES = L"PresetNames" | The out parameter is set to an array of **BSTR** (**VT_ARRAY** | **BSTR**) values containing the names of the presets. This property is requested only for plug-ins that have presets. |
| PLUGIN_MISC_QUERYDESTROY = L"QueryDestroy" | The out parameter is set to a **BSTR** (**VT_BSTR**) value that is displayed to the user when Windows Media Player attempts to close a separate window or background plug-in that is engaged in operations that cannot be interrupted. |
| PLUGIN_SEPARATEWINDOW_DEFAULTHEIGHT = L"DefaultHeight" | The out parameter is set to a **Long** (**VT_I4**) value indicating the desired default opening height of the plug-in window. This property is requested only for plug-ins in separate windows. |
| PLUGIN_SEPARATEWINDOW_DEFAULTWIDTH = L"DefaultWidth" | The out parameter is set to a **Long** (**VT_I4**) value indicating the desired default opening width of the plug-in window. This property is requested only for plug-ins in separate windows. |
| PLUGIN_SEPARATEWINDOW_MAXHEIGHT = L"MaxHeight" | The out parameter is set to a **Long** (**VT_I4**) value indicating the desired maximum height of the plug-in window. This property is requested only for plug-ins in separate, resizable windows. |
| PLUGIN_SEPARATEWINDOW_MAXWIDTH = L"MaxWidth" | The out parameter is set to a **Long** (**VT_I4**) value indicating the desired maximum width of the plug-in window. This property is requested only for plug-ins in separate, resizable windows. |
| PLUGIN_SEPARATEWINDOW_MINHEIGHT = L"MinHeight" | The out parameter is set to a **Long** (**VT_I4**) value indicating the desired minimum height of the plug-in window. This property is requested only for plug-ins in separate, resizable windows. |
| PLUGIN_SEPARATEWINDOW_MINWIDTH = L"MinWidth" | The out parameter is set to a **Long** (**VT_I4**) value indicating the desired minimum width of the plug-in window. This property is requested only for plug-ins in separate, resizable windows. |
| PLUGIN_SEPARATEWINDOW_RESIZABLE = L"Resizable" | The out parameter is set to a **Boolean** (**VT_BOOL**) value that indicates whether the plug-in window is resizable. This property is requested only for plug-ins in separate windows. |

### `pvarProperty` [out]

Pointer to a **VARIANT** to contain the value of the property.

## Return value

This method returns an **HRESULT**.

## Remarks

Windows Media Player determines the type and capabilities of a plug-in by checking the Windows registry, and will retrieve only properties that the plug-in supports.

When a user attempts to close a separate window or background UI plug-in, or to close Windows Media Player when one of these plug-in types is active, this method is called with the **PLUGIN_MISC_QUERYDESTROY** property specified. If the plug-in is engaged in an operation that cannot be interrupted, such as reading or writing a file or waiting for user input in a modal dialog box, set the out parameter of this method to a non-empty value. This value is displayed to the user to indicate the problem. A user who is attempting to close Windows Media Player is then given the option of overriding the plug-in and closing the Player anyway.

When the plug-in is ready to close, set the out parameter to "" (empty string). When Windows Media Player calls this method and receives an empty value in the out parameter, it closes the plug-in without further delay.

This method is not called when a display area, settings area, or metadata area plug-in is closed. Because these plug-in types are displayed in the **Now Playing** pane, they must be ready to close at any time, such as when a user switches to another pane.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPPluginUI Interface](https://learn.microsoft.com/windows/desktop/api/wmpplug/nn-wmpplug-iwmppluginui)