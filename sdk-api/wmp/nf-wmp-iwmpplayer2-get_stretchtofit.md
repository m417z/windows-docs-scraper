# IWMPPlayer2::get_stretchToFit

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_stretchToFit** method retrieves a value indicating whether video displayed by the Windows Media Player control automatically sizes to fit the video window when the video window is larger than the dimensions of the video image.

## Parameters

### `pbEnabled` [out]

Pointer to a **VARIANT_BOOL** indicating whether video displayed by the Windows Media Player control automatically resizes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When the **VARIANT_BOOL** retrieved by **get_stretchToFit** equals **TRUE**, the Windows Media Player control maintains the original aspect ratio of the video. If the aspect ratio of the video does not match the aspect ratio of the video window, black mask areas may appear on either the top and bottom or left and right of the video image.

This method applies to the Windows Media Player control only when embedded in a webpage.

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **FALSE**.

## See also

[IWMPPlayer2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer2)

[IWMPPlayer2::put_stretchToFit](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer2-put_stretchtofit)