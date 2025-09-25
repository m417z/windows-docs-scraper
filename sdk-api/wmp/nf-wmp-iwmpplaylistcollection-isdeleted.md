# IWMPPlaylistCollection::isDeleted

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **isDeleted** method retrieves a value indicating whether the specified playlist is in the deleted items folder.

## Parameters

### `pItem` [in]

Pointer to an **IWMPPlaylist** interface for the queried playlist.

### `pvarfIsDeleted` [out]

Pointer to a **VARIANT_BOOL** that specifies whether the given playlist was deleted.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **FALSE**.

## See also

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylistCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylistcollection)