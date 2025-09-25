# IWMPStringCollection2::getItemInfoByType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getItemInfoByType** method retrieves the value corresponding to the specified string collection item index, name, language, and attribute index.

## Parameters

### `lCollectionIndex` [in]

A **long** specifying the zero-based index of the string collection item from which to get the attribute.

### `bstrType` [in]

**BSTR** containing the attribute name.

### `bstrLanguage` [in]

**BSTR** containing the language. If the value is set to null or "" (empty string) the current locale string is used. Otherwise, the value must be a valid RFC 1766 language string such as "en-us".

### `lAttributeIndex` [in]

A **long** containing the zero-based index of the attribute.

### `pvarValue` [out]

Pointer to a **VARIANT** that receives the returned value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method supports attributes with multiple values and attributes with complex values. The **getItemInfo** method does not support attributes with multiple values or attributes with complex values.

By passing the value "ChildList" in the *bstrType* parameter, you can retrieve a new string collection that contains the children of one of the items in the parent string collection. For instance, if the parent collection contains a list of AlbumIDs, you can use this method to obtain a child string collection that contains all the tracks for one of the albums. This approach is faster and more efficient than calling the **IWMPMediaCollection2::getStringCollectionByQuery** method twice; once to get a collection of AlbumIDs, and a second time to get a collection of titles for a particular AlbumID. To use ChildList in the way just described, the parent string collection must be obtained from a media collection through **IWMPLibraryServices**, and not by using the **IWMPCore::get_mediaCollection** method.

When using ChildList, pass the value "ChildList" in the *bstrType* parameter, and the value 0 in the *lAttributeIndex* parameter. You can call **QueryInterface** on the **VARIANT** that is returned to obtain an **IWMPStringCollection2** interface, from which you can access the child list.

To use this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[AlbumID Attribute](https://learn.microsoft.com/windows/desktop/WMP/albumid-attribute)

[IWMPLibraryServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibraryservices)

[IWMPMediaCollection2::getStringCollectionByQuery](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection2-getstringcollectionbyquery)

[IWMPStringCollection2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpstringcollection2)

[IWMPStringCollection2::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpstringcollection2-getiteminfo)