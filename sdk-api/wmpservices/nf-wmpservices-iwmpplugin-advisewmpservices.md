# IWMPPlugin::AdviseWMPServices

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPPlugin::AdviseWMPServices** method is implemented by the plug-in.

## Parameters

### `pWMPServices` [in]

Pointer to an **IWMPServices** interface.

## Return value

The method returns an **HRESULT**.

## Remarks

Windows Media Player calls the **AdviseWMPServices** method on the plug-in to pass in a pointer that the plug-in can then use to call the **IWMPServices** interface, which contains methods that provide information about the current state of the stream.

## See also

[IWMPPlugin Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpplugin)

[IWMPServices Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpservices)