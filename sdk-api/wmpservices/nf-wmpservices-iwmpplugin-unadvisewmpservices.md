# IWMPPlugin::UnAdviseWMPServices

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPPlugin::UnAdviseWMPServices** method is used to release the pointer provided by **AdviseWMPServices**.

## Return value

The method returns an **HRESULT**.

## Remarks

Windows Media Player calls this method when the pointer provided by **AdviseWMPServices** is no longer valid. The plug-in should use this method to cease making stream state requests through the pointer.

## See also

[IWMPPlugin Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpplugin)

[IWMPPlugin::AdviseWMPServices](https://learn.microsoft.com/windows/desktop/api/wmpservices/nf-wmpservices-iwmpplugin-advisewmpservices)