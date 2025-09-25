# IWMPMediaPluginRegistrar::WMPRegisterPlayerPlugin

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPMediaPluginRegistrar::WMPRegisterPlayerPlugin** function adds information to the registry that identifies a Windows Media Player plug-in.

## Parameters

### `pwszFriendlyName`

Pointer to a wide character null-terminated string containing the friendly name of the plug-in. This is also the name that displays to the user.

### `pwszDescription`

Pointer to a wide character null-terminated string containing the description of the plug-in. This information also displays to the user.

### `pwszUninstallString`

Pointer to a wide character null-terminated string containing the uninstall string.

### `dwPriority`

Integer value containing the priority position of the plug-in in the chain of currently enabled plug-ins.

### `guidPluginType`

GUID specifying plug-in type. For DSP plug-ins, specify WMP_PLUGINTYPE_DSP to register for DirectShow playback and WMP_PLUGINTYPE_DSP_OUTOFPROC for Media Foundation playback. See Remarks.

### `clsid`

The class ID of the plug-in.

### `cMediaTypes`

Count of media types supported by the plug-in.

### `pMediaTypes`

Pointer to an array of media types that enumerates the supported media types. Media types are stored as type/subtype pairs.

## Return value

The function returns an **HRESULT**.

## Remarks

Implement this function in the exported **DllRegisterServer** function.

The uninstall string is a command line string that Windows Media Player passes as the argument to the Windows **ShellExecute** function when the user chooses to remove the plug-in by clicking **Remove** in the Player plug-in configuration dialog box. This gives you a way to execute your own uninstall program that initiates from Windows Media Player.

Priority values start at zero. Most DSP plug-ins should specify a value between 1 and 10. Lower values place the plug-in closer to the rendering engine.

DSP plug-ins registered with identical values for **dwPriority** are ordered based on their position in the registry. Plug-ins located higher in the registry hierarchy are assigned a higher priority than plug-ins located lower in the registry hierarchy.

DSP plug-ins designed to work with Windows Media Player 11 must call this method twice. The first call must specify *guidPluginType* as WMP_PLUGINTYPE_DSP. The second call must specify *guidPluginType* as WMP_PLUGINTYPE_DSP_OUTOFPROC. For plug-ins designed to be backward compatible, you should avoid making the second call when installing for earlier versions of Windows Media Player. To accomplish this, check the Windows version. If the Windows operating system major version is greater than or equal to 6, you can safely register the plug-in for Media Foundation playback.

## See also

[IWMPMediaPluginRegistrar Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpmediapluginregistrar)

[IWMPMediaPluginRegistrar::WMPUnRegisterPlayerPlugin](https://learn.microsoft.com/windows/desktop/api/wmpservices/nf-wmpservices-iwmpmediapluginregistrar-wmpunregisterplayerplugin)