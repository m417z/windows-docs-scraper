# IWMPCore3::newPlaylist

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **newPlaylist** method retrieves a pointer to an **IWMPPlaylist** interface for a new playlist.

## Parameters

### `bstrName` [in]

**BSTR** containing the playlist name.

### `bstrURL` [in]

**BSTR** containing the playlist URL.

### `ppPlaylist` [out]

Pointer to a pointer to an **IWMPPlaylist** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the *bstrURL* parameter is a null or empty string, this method creates an empty **Playlist** object. If the *bstrname* parameter is an empty string, this method applies the current metafile name.

The new playlist created with this method is not added to the library. To add a new playlist to the library, use **IWMPPlaylistCollection::importPlaylist** or **IWMPPlaylistCollection::newPlaylist**. Any leading or trailing spaces in the playlist name are automatically removed when it is added to the library.

Because the library allows multiple playlists with the same name, you may want to check for the presence of a playlist with a given name before adding a new one.

## See also

[IWMPCore3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcore3)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylistCollection::importPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-importplaylist)

[IWMPPlaylistCollection::newPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-newplaylist)