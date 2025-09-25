# IWMPPlaylist::removeItem

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **removeItem** method removes the specified media item from the playlist.

## Parameters

### `pIWMPMedia` [in]

Pointer to an **IWMPMedia** interface for the item to remove.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the item removed is the currently playing track, playback stops and the next item in the playlist becomes the current one.

If there is no next item, the previous item is used. If there are no other items, then the **IWMPCore::get_currentMedia** method will return **NULL**.

Before calling this method, you must have full access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPCore::get_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_currentmedia)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylist::insertItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-insertitem)