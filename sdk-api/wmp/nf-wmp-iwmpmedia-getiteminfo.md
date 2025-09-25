# IWMPMedia::getItemInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getItemInfo** method retrieves the value of the specified attribute for the media item.

## Parameters

### `bstrItemName` [in]

**BSTR** containing the item name.

### `pbstrVal` [out]

Pointer to a **BSTR** containing the returned value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method retrieves the metadata for an individual media item or a media item that is part of a playlist.

The **get_attributeCount** method retrieves the number of attribute names available for a given media item. Index numbers can then be used with the **getAttributeName** method to determine the name of each available attribute. Individual attribute names can be passed to **getItemInfo**.

To retrieve attributes with multiple values and attributes with complex values, use the **getItemInfoByType** method.

The set of attributes available from sources other than the local library (remote libraries, portable devices, or CDs) is defined by the other sources.

Before calling this method, you must have Read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

To share the Windows media libraries over UPnP, Windows Media Player creates a content directory service (CDS) that

is exposed over UPnP. Other devices can then navigate and browse the libraries.

In Windows 7, an application can use the Windows Media Player [TrackingID](https://learn.microsoft.com/windows/desktop/WMP/trackingid-attribute) and [MediaType](https://learn.microsoft.com/windows/desktop/WMP/mediatype-attribute) attributes to construct the object ID of each item in the CDS. Note that this construction might change in future versions of Windows. The application passes each of these attribute strings in the *bstrItemName* parameter in a call to **getItemInfo**. **getItemInfo** returns the value for each attribute in a variable to which the *pbstrVal* parameter points. The application then uses the following syntax to construct each object ID:

*TrackingID*.0.*MediaTypeID*

This syntax has the following meaning:

* *TrackingID* is the string that is stored in the Windows Media Player [TrackingID](https://learn.microsoft.com/windows/desktop/WMP/trackingid-attribute) attribute of the media item.
* *MediaTypeID* depends on the value of the [MediaType](https://learn.microsoft.com/windows/desktop/WMP/mediatype-attribute)

  attribute, as shown in the following table:

  | MediaType attribute | MediaTypeID |
  | --- | --- |
  | [Audio Items](https://learn.microsoft.com/windows/desktop/WMP/audio-item-attributes) | 4 |
  | [Photo Items](https://learn.microsoft.com/windows/desktop/WMP/photo-item-attributes) | B |
  | [Video Items](https://learn.microsoft.com/windows/desktop/WMP/video-item-attributes) | 8 |

**Windows Media Player 10 Mobile:** Attributes for a media item are available only during playback unless they are retrieved from the item through the media collection.

## See also

[Attribute Reference](https://learn.microsoft.com/windows/desktop/WMP/attribute-reference)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPMedia3::getItemInfoByType](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia3-getiteminfobytype)

[IWMPMedia::getAttributeName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getattributename)

[IWMPMedia::get_attributeCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-get_attributecount)

[IWMPMedia::setItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-setiteminfo)