# IWMPMedia::getItemInfoByAtom

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getItemInfoByAtom** method retrieves the value of the attribute with the specified index number.

## Parameters

### `lAtom` [in]

**long** specifying the index at which a given attribute resides within the set of available attributes.

### `pbstrVal` [out]

Pointer to a **BSTR** containing the returned value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method can be used to retrieve metadata for a specific media item by using an attribute index number. The **get_attributeCount** method can be used to determine the number of attributes available for the media item.

The **getMediaAtom** method of the **MediaCollection** object can also be used to retrieve the index of a particular attribute. This technique is generally more efficient than the **getItemInfo** or **getItemInfoByType** methods when working with large playlists.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** Attributes for a media item are available only during playback unless they are retrieved from the item through the media collection.

## See also

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPMedia3::getItemInfoByType](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia3-getiteminfobytype)

[IWMPMedia::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getiteminfo)

[IWMPMedia::get_attributeCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-get_attributecount)

[IWMPMedia::setItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-setiteminfo)

[IWMPMediaCollection::getMediaAtom](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection-getmediaatom)