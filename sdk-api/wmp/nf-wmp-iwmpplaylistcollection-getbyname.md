# IWMPPlaylistCollection::getByName

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getByName** method retrieves a pointer to an **IWMPPlaylistArray** interface on an object containing playlists with the specified name, if any exist.

## Parameters

### `bstrName` [in]

String containing the name.

### `ppPlaylistArray` [out]

Pointer to a pointer to an **IWMPPlaylistArray** interface for the retrieved array of playlists.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Use **IWMPPlaylistArray::count** to determine whether a playlist exists. If **count** is zero, the array is empty.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPPlaylistArray::get_count](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistarray-get_count)

[IWMPPlaylistCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylistcollection)