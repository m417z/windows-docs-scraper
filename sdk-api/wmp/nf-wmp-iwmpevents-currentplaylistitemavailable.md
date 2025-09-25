# IWMPEvents::CurrentPlaylistItemAvailable

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CurrentPlaylistItemAvailable** event occurs when the current playlist item becomes available.

## Parameters

### `bstrItemName` [in]

Specifies the item name.

## Remarks

The name of the current playlist can be used to retrieve the corresponding **Playlist** object by using the **IWMPPlaylistCollection::getByName** method.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)

[IWMPPlaylistCollection::getByName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-getbyname)