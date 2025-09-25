# IWMPCdromRip::get_ripProgress

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_ripProgress** method retrieves the CD ripping progress as percent complete.

## Parameters

### `plProgress` [out]

Pointer to a **long** that receives the progress value. Progress values range from 0 to 100.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The progress value represents the completed percentage of the entire ripping process. To determine the progress of a specific track, use [IWMPMedia::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getiteminfo) with **RipProgress** as the attribute name. To determine the index of the track currently being ripped, call [IWMPPlaylist::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-getiteminfo) with **CurrentRipTrackIndex** as the attribute name.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPCdromRip Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromrip)

[Ripping a CD](https://learn.microsoft.com/windows/desktop/WMP/ripping-a-cd)