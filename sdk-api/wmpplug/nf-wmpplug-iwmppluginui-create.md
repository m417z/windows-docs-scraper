# IWMPPluginUI::Create

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Create** method is called by Windows Media Player to instantiate the plug-in user interface. This method is passed a handle to a parent window of the plug-in window. A handle to the newly created window is then passed back to the calling method.

## Parameters

### `hwndParent` [in]

**HWND** handle to a parent window of the plug-in window.

### `phwndWindow` [out]

Pointer to an **HWND** handle to the plug-in window after the content is filled in.

## Return value

This method returns an **HRESULT**.

## Remarks

This method is called by Windows Media Player for all user interface plug-in types except the background type.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPPluginUI Interface](https://learn.microsoft.com/windows/desktop/api/wmpplug/nn-wmpplug-iwmppluginui)