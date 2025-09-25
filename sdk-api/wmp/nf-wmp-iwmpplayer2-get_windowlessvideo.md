# IWMPPlayer2::get_windowlessVideo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_windowlessVideo** method retrieves a value indicating whether the Windows Media Player control renders video in windowless mode.

## Parameters

### `pbEnabled` [out]

Pointer to a **VARIANT_BOOL** indicating whether the Windows Media Player control renders video in windowless mode.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

By default, an embedded Windows Media Player control renders video in its own window within the client area. When the **VARIANT_BOOL** retrieved by **get_windowlessVideo** equals **TRUE**, the Windows Media Player object renders video directly in the client area, so you can apply special effects or layer the video with text.

In Windows Vista, rendering video in windowless mode can degrade performance.

The **get_windowlessVideo** method is not supported for Netscape Navigator. Setting a value for this property in Navigator may yield unexpected results.

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **FALSE**.

## See also

[IWMPPlayer2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer2)

[IWMPPlayer2::put_windowlessVideo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer2-put_windowlessvideo)