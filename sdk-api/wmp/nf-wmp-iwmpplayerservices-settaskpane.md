# IWMPPlayerServices::setTaskPane

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **setTaskPane** method displays the specified task pane in the full mode of Windows Media Player.

## Parameters

### `bstrTaskPane` [in]

**BSTR** containing one of the following values.

| Value | Description |
| --- | --- |
| NowPlaying | Windows Media Player 9, 10, 11: Opens Windows Media Player in the **Now Playing** feature.<br><br>Windows Media Player 12: Opens Windows Media Player in **Player** mode . |
| MediaGuide | Windows Media Player 9, 10, 11: Opens Windows Media Player in the **Media Guide** feature. <br><br>Windows Media Player 12: Opens Windows Media Player in **Library** mode with the Media Guide displayed. |
| CopyFromCD | Windows Media Player 9: Opens Windows Media Player in the **Copy From CD** feature.<br><br>Windows Media Player 10, 11: Opens Windows Media Player in the **Rip** feature.<br><br>Windows Media Player 12: Opens Windows Media Player in **Library** mode. |
| CopyFromCD?AutoCopy:*id* | Windows Media Player 9: Opens Windows Media Player in the **Copy From CD** feature and automatically invokes the copy functionality after switching.<br><br>Windows Media Player 10, 11: Opens Windows Media Player in the **Rip** feature and automatically invokes the rip functionality after switching.<br><br>Windows Media Player 12: Opens Windows Media Player in **Library** mode and automatically invokes the rip functionality after switching.<br><br>All versions: To specify a particular drive identifier, append a colon character (:) followed by the CD drive identifier number. If you omit the colon and the ID, the first CD drive is used. If the user has selected **Eject CD when copying is completed** in Windows Media Player, the CD will be ejected when copying is completed. |
| Library | Windows Media Player 9, 10, 11: Opens Windows Media Player in the **Library** feature.<br><br>Windows Media Player 12: Opens Windows Media Player in **Library** mode with the **Play** tab open. |
| RadioTuner | Windows Media Player 9: Opens Windows Media Player in the **Radio Tuner** feature<br><br>Windows Media Player 10, 11, 12: Opens Windows Media Player in the current active online store. |
| CopyToCD | Windows Media Player 9: Not supported.<br><br>Windows Media Player 10, 11: Opens Windows Media Player in the **Burn** feature.<br><br>Windows Media Player 12: Opens Windows Media Player in **Library** mode with the burn list open. |
| CopyToCDOrDevice | Windows Media Player 9: Opens Windows Media Player in the **Copy to CD or Device** feature.<br><br>Windows Media Player 10, 11: Opens Windows Media Player in the **Sync** feature.<br><br>Windows Media Player 12: Opens Windows Media Player in **Library** mode with the **Sync** tab open. |
| Services | Windows Media Player 9: Opens Windows Media Player in the **Premium Services** feature <br><br>Windows Media Player 10, 11, 12: Opens Windows Media Player in the current active online store. |
| SkinChooser | Opens Windows Media Player in the **Skin Chooser** feature. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

This method is used only when remoting the Windows Media Player control.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPPlayerServices::setTaskPaneURL(deprecated)](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayerservices-settaskpaneurl)

[IWMPPlayerServicesInterface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayerservices)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)