# IWMPPlayerServices2::setBackgroundProcessingPriority

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **setBackgroundProcessingPriority** method specifies a priority level for general background processing tasks.

## Parameters

### `bstrPriority` [in]

**BSTR** containing one of the following values: "High", "Normal", "Off", or "Urgent".

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

This method is used only when remoting the Windows Media Player control.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPPlayerServices2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayerservices2)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)