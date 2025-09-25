# IWMPNetwork::get_frameRate

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_frameRate** method retrieves the current video frame rate.

## Parameters

### `plFrameRate` [out]

Pointer to a **long** containing the frame rate.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The frame rate value is returned in frames per hundred seconds. For example, a value of 2998 indicates 29.98 frames per second (fps).

## See also

[IWMPNetwork Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpnetwork)

[IWMPNetwork::get_encodedFrameRate](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-get_encodedframerate)