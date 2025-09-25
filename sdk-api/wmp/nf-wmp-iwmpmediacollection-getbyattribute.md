# IWMPMediaCollection::getByAttribute

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getByAttribute** method retrieves a pointer to an **IWMPPlaylist** interface. This interface corresponds to the specified attribute having the specified value.

## Parameters

### `bstrAttribute` [in]

String containing the specified attribute.

### `bstrValue` [in]

String containing the specified value.

### `ppMediaItems` [out]

Pointer to a pointer to an **IWMPPlaylist** interface for the retrieved media items.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method can be used to create a generic query for media items that match a value for an attribute in the database. This is useful in the case of user-defined attributes. If the attribute does not exist, an error will result.

You can use this method to retrieve all of the media items of a specific type. Use the attribute name "MediaType" and one of the following values:

| Value | Description |
| --- | --- |
| audio | Music and other audio-only items |
| other | Other items, such as an .asf file or the URL of a stream. |
| photo | Photo items. Requires Windows Media Player 10. |
| playlist | Playlists represented as media items. |
| radio | Radio station items. Not used by Windows Media Player 10. |
| video | Video items. |

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

There are two ways you ways you can retrieve an **IWMPMediaCollection** interface, and the behavior of the **getByAttribute** method depends on which of those two ways you use. If you retrieve the interface by calling [IWMPCore::get_mediaCollection](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_mediacollection), then the **getByAttribute** method returns all the media items in the library that have the specified attribute and value. If you retrieve the interface by calling [IWMPLibrary::get_mediaCollection](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmplibrary-get_mediacollection), then the **getByAttribute** method returns only the audio items in the library that have the specified attribute and value.

## See also

[IWMPMediaCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylistCollection::getAll](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-getall)