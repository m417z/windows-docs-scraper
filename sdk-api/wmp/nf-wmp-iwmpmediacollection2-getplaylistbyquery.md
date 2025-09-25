# IWMPMediaCollection2::getPlaylistByQuery

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getPlaylistByQuery** method retrieves a pointer to an **IWMPPlaylist** interface. This interface represents a playlist that contains media items that match the query conditions.

## Parameters

### `pQuery` [in]

Pointer to the **IWMPQuery** interface that represents the query.

### `bstrMediaType` [in]

String that contains the media type. Must contain one of the following values: "audio", "video", "photo", "playlist", or "other".

### `bstrSortAttribute` [in]

String that contains the attribute name used for sorting. An empty string means that no sorting is applied.

### `fSortAscending` [in]

**VARIANT_BOOL** that indicates whether the playlist must be sorted in ascending order.

### `ppPlaylist` [out]

Address of a variable that receives a pointer to an **IWMPPlaylist** interface for the retrieved playlist.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Compound queries using **IWMPQuery** are not case sensitive.

When the compound query specified by the *pQuery* parameter contains a condition built on the **MediaType** attribute, that condition is ignored. The value for the *bstrMediaType* parameter is always used. For example, if the compound query contains the condition "MediaType Equals audio" and the value for the *bstrMediaType* parameter is "video", the resulting playlist will contain only video items.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPMediaCollection2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection2)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPQuery Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpquery)

[MediaType Attribute](https://learn.microsoft.com/windows/desktop/WMP/mediatype-attribute)