# IWMPPlayerApplication::switchToControl

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **switchToControl** method switches a remoted Windows Media Player control to the docked state.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is used only when remoting the Windows Media Player control.

You should avoid keeping a remoted instance of the Player running in the background during times when the control is not in use. Because the remoted Player control instance shares its playback engine with the full mode Player, keeping a background instance running can cause unexpected behavior. For example, the user might close the full mode Player while a file is playing. The user would expect that file playback would completely stop when the Player closes, but audio might continue to play because the playback engine is still active.

**Windows Media Player 10 Mobile:** This method always returns E_NOTIMPL.

## See also

[IWMPPlayerApplication Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayerapplication)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)