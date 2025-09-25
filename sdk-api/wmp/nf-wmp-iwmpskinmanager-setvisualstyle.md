# IWMPSkinManager::SetVisualStyle

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetVisualStyle** method specifies the path to a theme file in Windows XP to which Windows Media Player synchronizes the skin.

## Parameters

### `bstrPath` [in]

**BSTR** containing the path to the theme file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

Windows XP calls this method when the user changes the current theme. The current skin selection will change to match the theme, or will change to the Windows Classic skin if there is no skin that matches the current theme. If Windows Media Player is in skin mode, the skin will change immediately. Otherwise, the new skin selection will be applied the next time skin mode is entered.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSkinManager Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpskinmanager)