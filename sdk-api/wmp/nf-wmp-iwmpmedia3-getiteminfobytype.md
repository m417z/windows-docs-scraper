# IWMPMedia3::getItemInfoByType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getItemInfoByType** method retrieves the value of the attribute corresponding to the specified attribute type and index.

## Parameters

### `bstrType` [in]

**BSTR** containing the type.

### `bstrLanguage` [in]

**BSTR** containing the language. If the value is set to null or "" (empty string), the current locale string is used. Otherwise, the value must be a valid RFC 1766 language string such as "en-us".

### `lIndex` [in]

**long** containing the index.

### `pvarValue` [out]

Pointer to a **VARIANT** that contains the returned value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method retrieves the metadata for an individual digital media item or a media item that is part of a playlist.

This method supports attributes with multiple values and attributes with complex values. The **getItemInfo** method does not support attributes with multiple values and attributes with complex values.

The **attributeCount** method retrieves the number of attribute names available for a given media item. Index numbers can then be used with the **getAttributeName** method to determine the name of each available attribute. Individual attribute names can be passed to the *name* parameter of **getItemInfoByType**.

The **getAttributeCountByType** method returns the number of attributes that correspond to a particular attribute name for a given media item. Index numbers can then be passed to the *index* parameter of **getItemInfoByType**. This is useful when a media item has been categorized under multiple genres, for example.

The set of attributes available from sources other than the local library (remote libraries, portable devices, or CDs is defined by the other sources.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPMedia3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia3)

[IWMPMedia3::getAttributeCountByType](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia3-getattributecountbytype)

[IWMPMedia::getAttributeName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getattributename)

[IWMPMedia::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getiteminfo)

[IWMPMedia::get_attributeCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-get_attributecount)