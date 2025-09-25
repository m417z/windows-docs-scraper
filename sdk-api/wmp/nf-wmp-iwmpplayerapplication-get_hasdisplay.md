# IWMPPlayerApplication::get_hasDisplay

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_hasDisplay** method retrieves a value indicating whether video can display through the remoted Windows Media Player control.

## Parameters

### `pbHasDisplay` [out]

Pointer to a **VARIANT_BOOL** indicating whether video can display through the remoted Windows Media Player control.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is used only when remoting the Windows Media Player control.

Several Windows Media Player controls can be running remotely at the same time, but video can only display in one location at a time, either in the full mode of the Player or in one of the remoted controls. Use this method to determine whether the current control is the one through which video can be displayed.

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **TRUE**.

## See also

[IWMPPlayerApplication Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayerapplication)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)