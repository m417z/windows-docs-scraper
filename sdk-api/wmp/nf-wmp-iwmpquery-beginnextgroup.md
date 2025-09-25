# IWMPQuery::beginNextGroup

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **beginNextGroup** method begins a new condition group.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Beginning a new condition group implies that you have completed the current condition group. The new condition group is always concatenated to the previous condition group by using OR logic.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPMediaCollection2::createQuery](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection2-createquery)

[IWMPMediaCollection2::getPlaylistByQuery](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection2-getplaylistbyquery)

[IWMPMediaCollection2::getStringCollectionByQuery](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection2-getstringcollectionbyquery)

[IWMPQuery Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpquery)