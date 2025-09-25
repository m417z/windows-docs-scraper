# IWMPPlugin::GetID

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPPlugin::GetID** method returns the class id of the plug-in.

## Parameters

### `pGUID` [out]

Pointer to a **GUID** that represents the class id of the plug-in.

## Return value

The method returns an **HRESULT**.

## Remarks

For more information on the **GUID** structure, see the Platform SDK.

## See also

[IWMPPlugin Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpplugin)