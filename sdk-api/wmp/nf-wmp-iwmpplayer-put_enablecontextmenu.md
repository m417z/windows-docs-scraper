# IWMPPlayer::put_enableContextMenu

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_enableContextMenu** method specifies a value indicating whether to enable the context menu, which appears when the right mouse button is clicked.

## Parameters

### `bEnableContextMenu` [in]

**VARIANT_BOOL** that indicates whether to the enable context menu. The default is **TRUE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

During full-screen playback, Windows Media Player hides the mouse cursor when the **VARIANT_BOOL** retrieved by **IWMPPlayer::get_enableContextMenu** equals **FALSE** and the **BSTR** retrieved by **IWMPPlayer::get_uiMode** equals "none".

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPPlayer Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer)

[IWMPPlayer::get_enableContextMenu](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-get_enablecontextmenu)

[IWMPPlayer::get_uiMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-get_uimode)

[IWMPPlayer::put_enabled](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-put_enabled)