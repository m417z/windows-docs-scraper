# IWMPPluginEnable::GetEnable

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPPluginEnable::GetEnable** method returns a value indicating whether Windows Media Player has enabled the plug-in.

## Parameters

### `pfEnable` [out]

Pointer to a **Boolean** value indicating whether the user has enabled the plug-in.

## Return value

The method returns an **HRESULT**.

## Remarks

This value is set by Windows Media Player in the **IWMPPluginEnable::SetEnable** method.

## See also

[IWMPPluginEnable Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmppluginenable)

[IWMPPluginEnable::SetEnable](https://learn.microsoft.com/windows/desktop/api/wmpservices/nf-wmpservices-iwmppluginenable-setenable)