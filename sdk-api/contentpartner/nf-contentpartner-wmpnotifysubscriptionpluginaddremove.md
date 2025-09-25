# WMPNotifySubscriptionPluginAddRemove function

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPNotifySubscriptionPluginAddRemove** function notifies Windows Media Player that a COM object has been installed or uninstalled.

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

## Return value

The return value indicates whether the function call succeeded.

## Remarks

This function is typically called by a plug-in in its [DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver) and [DllUnregisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllunregisterserver) methods. It alerts Windows Media Player to enumerate registered online store objects.

## See also

[Reference for Type 2 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/reference-for-type-2-online-stores)