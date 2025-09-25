# IWMPPlayer::get_fullScreen

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_fullScreen** method retrieves a value indicating whether video content is played back in full-screen mode.

## Parameters

### `pbFullScreen` [out]

Pointer to a **VARIANT_BOOL** indicating whether video content is played back in full-screen mode. The default is **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For full-screen mode to work properly when embedding the Windows Media Player control, the video display area must have a height and width of at least one pixel. If the **BSTR** specified in **IWMPPlayer::put_uiMode** is set to "mini" or "full", the height of the control itself must be 65 pixels or greater to accommodate the video display area in addition to the user interface.

If the **BSTR** specified in **IWMPPlayer::put_uiMode** is set to "invisible", then specifying the **VARIANT_BOOL** to **TRUE** in **get_fullScreen** raises an error and does not affect the behavior of the control.

During full-screen playback, Windows Media Player hides the mouse cursor when the **VARIANT_BOOL** retrieved from **IWMPPlayer::get_enableContextMenu** equals **FALSE** and the **BSTR** retrieved from **IWMPPlayer::get_uiMode** equals "none".

If the **BSTR** specified in **IWMPPlayer::put_uiMode** is set to "full" or "mini", Windows Media Player displays transport controls in full-screen mode when the mouse cursor moves. After a brief interval of no mouse movement, the transport controls are hidden. If the **BSTR** specified in **IWMPPlayer::put_uiMode** is set to "none", no controls are displayed in full-screen mode.

Note

Displaying transport controls in full-screen mode requires the Windows XP operating system.

If transport controls are not displayed in full-screen mode, then Windows Media Player automatically exits full-screen mode when playback stops.

## See also

[IWMPPlayer Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer)

[IWMPPlayer::get_enableContextMenu](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-get_enablecontextmenu)

[IWMPPlayer::put_fullScreen](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-put_fullscreen)

[IWMPPlayer::put_uiMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-put_uimode)