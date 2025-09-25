# IWMPControls2::step

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **step** method causes the current video media item to freeze playback on the next frame or the previous frame.

## Parameters

### `lStep` [in]

**long** indicating how many frames to step before freezing. Must be set to 1 or -1.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method currently only supports the parameters 1 or -1, so you can only step one frame at a time.

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPControls2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols2)

[IWMPDVD Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpdvd)