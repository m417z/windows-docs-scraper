# IWMPPlaylistCollection::newPlaylist

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **newPlaylist** method creates a new, empty playlist in the library.

## Parameters

### `bstrName` [in]

String containing the name of the new playlist.

### `ppItem` [out]

Pointer to a pointer to an **IWMPPlaylist** interface for the new playlist.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method creates an empty playlist in the library. To fill the playlist with media items, use **IWMPPlaylist::appendItem** or **IWMPPlaylist::insertItem**.

Multiple playlists having the same name are permitted in the library. To avoid creating a duplicate playlist name with this method, use the **getByName** method and **IWMPPlaylistArray::count** to determine whether a playlist with a particular name already exists.

Leading and trailing spaces are not permitted in playlist names, and are automatically removed from the value specified for the bstrName parameter.

Before calling this method, you must have full access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylist::appendItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-appenditem)

[IWMPPlaylist::insertItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-insertitem)

[IWMPPlaylistArray::get_count](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistarray-get_count)

[IWMPPlaylistCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylistcollection)

[IWMPPlaylistCollection::getByName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-getbyname)