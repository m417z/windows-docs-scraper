# IWMPControls::next

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **next** method sets the next item in the playlist as the current item.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the playlist is on the last entry when **next** is invoked, the first entry in the playlist will become the current one.

For server-side playlists, this method skips to the next item in the server-side playlist, not the client playlist.

When playing a DVD, this method skips to the next logical chapter in the playback sequence, which may not be the next chapter in the playlist. When playing DVD stills, this method skips to the next still.

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls::previous](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-previous)

[IWMPControls::stop](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-stop)