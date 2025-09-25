# IWMPPlayer::get_enabled

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_enabled** method retrieves a value indicating whether the Windows Media Player control is enabled.

## Parameters

### `pbEnabled` [out]

Pointer to a **VARIANT_BOOL** indicating whether the Windows Media Player control is enabled.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the **VARIANT_BOOL** received from **get_enabled** equals **FALSE**, then Windows Media Player hides the user controls during full-screen playback.

## See also

[IWMPPlayer Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer)

[IWMPPlayer::get_enableContextMenu](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-get_enablecontextmenu)

[IWMPPlayer::put_enabled](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-put_enabled)