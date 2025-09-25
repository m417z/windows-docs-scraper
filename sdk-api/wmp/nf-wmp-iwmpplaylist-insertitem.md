# IWMPPlaylist::insertItem

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **insertItem** method adds a media item at the specified location in the playlist.

## Parameters

### `lIndex` [in]

**long** containing the index at which this method will add the item.

### `pIWMPMedia` [in]

Pointer to an **IWMPMedia** interface for the inserted item.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

All items after the inserted item will have their index numbers increased by one.

Before calling this method, you must have full access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylist::removeItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-removeitem)