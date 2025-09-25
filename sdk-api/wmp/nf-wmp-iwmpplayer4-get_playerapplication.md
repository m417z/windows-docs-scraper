# IWMPPlayer4::get_playerApplication

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_playerApplication** method retrieves a pointer to an **IWMPPlayerApplication** interface when a remoted Windows Media Player control is running.

## Parameters

### `ppIWMPPlayerApplication` [out]

Pointer to a pointer to an **IWMPPlayerApplication** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is used only when remoting the Windows Media Player control. If the retrieved value is null, the Player control is not embedded in remote mode.

This method is only accessible in C++ code or in script code in skins through the playerApplication global variable.

## See also

[Global Attributes](https://learn.microsoft.com/windows/desktop/WMP/global-attributes)

[IWMPPlayer4 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer4)

[IWMPPlayerApplication Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayerapplication)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)