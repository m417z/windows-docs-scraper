# IWMPMedia::isMemberOf

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **isMemberOf** method retrieves a value indicating whether the specified media item is a member of the specified playlist.

## Parameters

### `pPlaylist` [in]

Pointer to an **IWMPPlaylist** interface.

### `pvarfIsMemberOf` [out]

Pointer to a **VARIANT_BOOL** that indicates whether the item is a member of the playlist.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method cannot check playlists retrieved through the **MediaCollection** object. To test whether a media item is a member of a particular named playlist, retrieve the playlist collection with the **IWMPCore::get_playlistCollection** method. Once you retrieve the collection, retrieve the individual playlist by calling the **IWMPPlaylistCollection::getByName** method.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPCore::get_playlistCollection](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_playlistcollection)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylistCollection::getByName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-getbyname)