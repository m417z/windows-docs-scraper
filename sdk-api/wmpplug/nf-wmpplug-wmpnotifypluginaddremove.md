# WMPNotifyPluginAddRemove function

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPNotifyPluginAddRemove** function notifies Windows Media Player that a plug-in has been installed or uninstalled.

## Return value

The return value indicates whether the function call succeeded.

## Remarks

This function is typically called by a user interface (UI) plug-in in its [DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver) and [DllUnregisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllunregisterserver) methods. Windows Media Player Plug-in Wizard generates this code automatically, so it is only necessary to add calls to this function to UI plug-ins created without the wizard.

## See also

[User Interface Plug-ins Programming Reference](https://learn.microsoft.com/windows/desktop/WMP/user-interface-plug-ins-programming-reference)