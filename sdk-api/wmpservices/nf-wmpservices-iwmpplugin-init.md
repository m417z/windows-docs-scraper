# IWMPPlugin::Init

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPPlugin::Init** method is called when Windows Media Player initializes the plug-in.

## Parameters

### `dwPlaybackContext` [in]

DWORD value that indicates the particular Windows Media Player playback engine to which the plug-in belongs.

## Return value

The method returns an **HRESULT**.

## Remarks

It is possible at any given time that multiple instances of Windows Media Player could be running in the same process. For instance, multiple Windows Media Player control instances could be embedded in the same browser window, or even in multiple instances of a browser that coexist in the same process. It is also possible that the same instance of Windows Media Player could create multiple playback engines at the same time. The *dwPlaybackContext* value allows you to determine which instance of the Windows Media Player playback engine contains the plug-in. This is useful if you wish to enable multiple plug-ins to connect to each other.

**Init** and **Shutdown** will always be called on the same thread.

## See also

[IWMPPlugin Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpplugin)