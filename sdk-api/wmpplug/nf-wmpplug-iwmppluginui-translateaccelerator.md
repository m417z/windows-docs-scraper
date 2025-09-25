# IWMPPluginUI::TranslateAccelerator

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **TranslateAccelerator** method is called as part of the Windows Media Player message loop to allow the plug-in to intercept and respond to keyboard events.

## Parameters

### `lpmsg` [in]

**LPMSG** structure containing message information from Windows Media Player that the plug-in can respond to.

## Return value

This method returns an **HRESULT**.

## Remarks

The plug-in can set up an accelerator table to reroute specific keyboard events to appropriate handler methods. If the plug-in chooses not to respond to keyboard events, it should return **S_FALSE**.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPPluginUI Interface](https://learn.microsoft.com/windows/desktop/api/wmpplug/nn-wmpplug-iwmppluginui)