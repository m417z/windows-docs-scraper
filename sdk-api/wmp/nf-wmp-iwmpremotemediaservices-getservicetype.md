# IWMPRemoteMediaServices::GetServiceType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetServiceType** method is called by Windows Media Player to determine whether a host program wants to run its embedded control remotely.

## Parameters

### `pbstrType` [out]

Pointer to a BSTR containing one or more of the following values.

| Value | Description |
| --- | --- |
| Local | The Windows Media Player control is embedded in local mode. |
| NoDeviceSupport | The Windows Media Player control is embedded in remote mode and provides no support for device synchronization interfaces. Attempting to use device synchronization features in code when in this mode will result in the following error code: NS_E_PDA_DEVICESUPPORTDISABLED (0xC00D1190L). Requires Windows Media Player 10. |
| NoDialogs | Windows Media Player 10: The Windows Media Player control is embedded in remote mode and does not display dialog boxes. See Remarks.Windows Media Player 11: The Windows Media Player control is embedded in either local or remote mode and does not display dialog boxes. |
| Remote | The Windows Media Player control is embedded in remote mode. |
| RemoteNoDialogs | The Windows Media Player control is embedded in remote mode and does not display dialog boxes. Use of this value requires Windows Media Player 9 Series update 819756 or later. See Remarks. |
| ExclusiveService:*keyname* | The Windows Media Player control is embedded in remote mode, and service selector for online stores is disabled. The only online store available to the user is the one identified by *keyname*. If this value is combined with other values from this table, it must be the last value in the combination. Requires Windows Media Player 11. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

You should avoid keeping a remoted instance of the Player running in the background during times when the control is not in use. Because the remoted Player control instance shares its playback engine with the full mode Player, keeping a background instance running can cause unexpected behavior. For example, the user might close the full mode Player while a file is playing. The user would expect that file playback would completely stop when the Player closes, but audio might continue to play because the playback engine is still active.

For Windows Media Player 10, the values for *pbstrType* may be used in combination by concatenating multiple values separated by spaces. For example, to use a remoted instance of Windows Media Player 10 that displays no dialog boxes and searches for digital media content, use "Remote NoDialogs FindFolders" as the value for *pbstrType*.

For Windows Media Player 11, an application that embeds the Player control remotely can specify an exclusive online store. In that case, the service selector is disabled and only the specified online store is available to the user. For more information, see Specifying an Exclusive Online Store in [Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control).

NoDialogs, FindFolders, and Exclusive:*keyname* are valid only when combined with Remote. These values are not supported when combined with Local.

The RemoteNoDialogs value is supported for backward compatibility with Windows Media Player 9 Series. (See [Microsoft Knowledge Base Article - 819756](https://support.microsoft.com/?id=819756) for more information.) For Windows Media Player 10, the recommended usage is "Remote NoDialogs".

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPRemoteMediaServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpremotemediaservices)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)