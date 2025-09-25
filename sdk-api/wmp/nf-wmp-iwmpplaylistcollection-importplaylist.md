# IWMPPlaylistCollection::importPlaylist

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **importPlaylist** method adds a static playlist to the library.

## Parameters

### `pItem` [in]

Pointer to an **IWMPPlaylist** interface for the playlist that this method will add.

### `ppImportedItem` [out]

Pointer to a pointer to an **IWMPPlaylist** interface for the added playlist.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Playlists that do not contain any media items cannot be added to the library by using this method. To create an empty playlist in the library, use the **newPlaylist** method. You can then fill the resulting playlist with media items by using **IWMPPlaylist::appendItem** or **IWMPPlaylist::insertItem**.

If you pass this method an auto playlist, the query is executed once and the result is added to the library as a static playlist. To add an auto playlist to the library and preserve its automatic behavior, use **IWMPMediaCollection::add**. For more information, see [Static and Auto Playlists](https://learn.microsoft.com/windows/desktop/WMP/static-and-auto-playlists).

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylist::appendItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-appenditem)

[IWMPPlaylist::insertItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-insertitem)

[IWMPPlaylistCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylistcollection)

[IWMPPlaylistCollection::newPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-newplaylist)