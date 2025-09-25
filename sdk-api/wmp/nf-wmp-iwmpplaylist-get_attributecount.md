# IWMPPlaylist::get_attributeCount

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_attributeCount** method retrieves the number of attributes associated with the playlist.

## Parameters

### `plCount` [out]

Pointer to a **long** containing the count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Because playlists can come from many different sources, they can have several different sets of properties. This method retrieves the total number of properties available so that the other methods of the **Playlist** object can access them.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

For information about the attributes supported by Windows Media Player, see the Windows Media Player [Attribute Reference](https://learn.microsoft.com/windows/desktop/WMP/attribute-reference).

## See also

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)