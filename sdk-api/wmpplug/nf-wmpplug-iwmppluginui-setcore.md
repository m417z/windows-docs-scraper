# IWMPPluginUI::SetCore

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetCore** method is called by Windows Media Player to provide plug-in access to the core Windows Media Player APIs.

## Parameters

### `pCore` [in]

Pointer to an **IWMPCore** interface.

## Return value

This method returns an **HRESULT**.

## Remarks

This method is called by Windows Media Player to allow the plug-in to set or release a pointer to the **IWMPCore** interface. If *pCore* is **NULL**, the plug-in is being shut down and all stored references to the core should be released.

This method is not called when Windows Media Player instantiates the plug-in for the purpose of displaying its property page. This method can therefore be used as an entry point that will only be called when the plug-in is enabled and Windows Media Player loads it normally.

## See also

[IWMPPluginUI Interface](https://learn.microsoft.com/windows/desktop/api/wmpplug/nn-wmpplug-iwmppluginui)