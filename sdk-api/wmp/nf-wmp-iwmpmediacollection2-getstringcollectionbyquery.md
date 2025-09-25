# IWMPMediaCollection2::getStringCollectionByQuery

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getStringCollectionByQuery** method retrieves a pointer to an **IWMPStringCollection** interface. This interface represents a set of all string values for a specified attribute that match the query conditions.

## Parameters

### `bstrAttribute` [in]

String containing the attribute name.

### `pQuery` [in]

Pointer to the **IWMPQuery** interface that represents the query that defines the conditions used to retrieve the string collection.

### `bstrMediaType` [in]

String containing the media type. Must contain one of the following values: "audio", "video", "photo", "playlist", or "other".

### `bstrSortAttribute` [in]

String containing the attribute name used for sorting. An empty string means no sorting is applied.

### `fSortAscending` [in]

**VARIANT_BOOL** that indicates whether the playlist must be sorted in ascending order.

### `ppStringCollection` [out]

Address of a variable that receives a pointer to an **IWMPStringCollection** interface for the retrieved set of string values.

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

[IWMPQuery Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpquery)

[IWMPStringCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpstringcollection)

[MediaType Attribute](https://learn.microsoft.com/windows/desktop/WMP/mediatype-attribute)