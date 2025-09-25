# IWMPPlayerServices::setTaskPaneURL

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

This page documents a feature of the Windows Media Player 9 Series SDK and the Windows Media Player 10 SDK. It may be unavailable in subsequent versions.

The **setTaskPaneURL** method displays the specified URL in the specified task pane of the full mode of Windows Media Player.

## Parameters

### `bstrTaskPane` [in]

**BSTR** containing one of the following values.

| Value | Description |
| --- | --- |
| MediaGuide | Opens Windows Media Player in the **MediaGuide** feature. |
| RadioTuner | Opens Windows Media Player in the **RadioTuner** feature. |
| Services | Opens Windows Media Player in the **Premium Services** feature. |

### `bstrURL` [in]

**BSTR** containing the URL to display in the task pane.

### `bstrFriendlyName` [in]

**BSTR** containing the friendly name of the content at the specified URL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

This method is used only when remoting the Windows Media Player control. This method must be called when the control is in the docked state. Once set, the specified task pane is opened the next time the remoted control transitions to Windows Media Player.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPPlayerServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayerservices)

[IWMPPlayerServices::setTaskPane](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayerservices-settaskpane)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)