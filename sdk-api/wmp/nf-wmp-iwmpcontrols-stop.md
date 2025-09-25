# IWMPControls::stop

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **stop** method stops playback of the media item.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method causes Windows Media Player to release any system resources it is using, such as the audio device. The current media item, however, is not released.

When Windows Media Player is stopped, the current playback point in the media item is reset to the beginning of the item. Subsequently calling **IWMPControls::play** will start playback from the beginning of the media item. To halt a play operation without changing the current position, use the **IWMPControls::pause** method.

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls::next](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-next)

[IWMPControls::pause](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-pause)

[IWMPControls::play](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-play)

[IWMPControls::previous](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-previous)