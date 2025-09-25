# IWMPPluginUI::DisplayPropertyPage

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DisplayPropertyPage** method is called by Windows Media Player to request that the plug-in display its property page. This method is passed a handle to a parent window of the plug-in property page dialog box.

## Parameters

### `hwndParent` [in]

**HWND** handle to a parent window of the property page dialog box.

## Return value

This method returns an **HRESULT**.

## Remarks

This method is called by Windows Media Player only for plug-ins that provide a property page.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPPluginUI Interface](https://learn.microsoft.com/windows/desktop/api/wmpplug/nn-wmpplug-iwmppluginui)