# IWMPMediaCollection::add

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **add** method adds a new media item or playlist to the library.

## Parameters

### `bstrURL` [in]

String containing the URL that specifies the location of the media item or playlist.

### `ppItem` [out]

Pointer to a pointer to the **IWMPMedia** interface for the added item or playlist.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method loads an existing media item or playlist into the library, given a path. This method does not move or change the file. This method fails if given an invalid local path, but media items themselves are not checked for validity before they are added to the library.

This method accepts both static and auto playlist files. The **IWMPPlaylistCollection::importPlaylist** method can also be used to add a static playlist to the library.

Before calling this method, you must have full access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPMediaCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection)

[IWMPMediaCollection::remove](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection-remove)

[IWMPPlaylistCollection::importPlaylist](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-importplaylist)