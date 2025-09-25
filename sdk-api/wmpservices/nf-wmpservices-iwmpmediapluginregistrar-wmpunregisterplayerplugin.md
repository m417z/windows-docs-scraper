# IWMPMediaPluginRegistrar::WMPUnRegisterPlayerPlugin

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPMediaPluginRegistrar::WMPUnRegisterPlayerPlugin** function removes information from the registry about a Windows Media Player plug-in.

## Parameters

### `guidPluginType`

GUID specifying plug-in type. For DSP plug-ins, specify WMP_PLUGINTYPE_DSP to register for DirectShow playback and WMP_PLUGINTYPE_DSP_OUTOFPROC for Media Foundation playback. See Remarks.

### `clsid`

Specifies the class ID of the plug-in being removed.

## Return value

The function returns an **HRESULT**.

## Remarks

Implement this function in the exported **DllUnRegisterServer** function.

DSP plug-ins designed to work with Windows Media Player 11 must call this method twice if **WMPRegisterPlayerPlugin** was called twice. The first call must specify *guidPluginType* as WMP_PLUGINTYPE_DSP. The second call must specify *guidPluginType* as WMP_PLUGINTYPE_DSP_OUTOFPROC. For plug-ins designed to be backward compatible, you should avoid making the second call when installing for earlier versions of Windows Media Player. To accomplish this, check the Windows version. If the Windows operating system major version is greater than or equal to 6, you can safely remove the plug-in for Media Foundation playback.

## See also

[IWMPMediaPluginRegistrar Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpmediapluginregistrar)

[IWMPMediaPluginRegistrar::WMPRegisterPlayerPlugin](https://learn.microsoft.com/windows/desktop/api/wmpservices/nf-wmpservices-iwmpmediapluginregistrar-wmpregisterplayerplugin)