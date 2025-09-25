# IWMPStringCollection::item

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **item** method retrieves the string at the given index.

## Parameters

### `lIndex` [in]

**long** containing the index.

### `pbstrString` [out]

Pointer to a **BSTR** containing the string.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **IWMPStringCollection** interface is used to retrieve the set of values available for an attribute. For example, the **IWMPMediaCollection::getAttributeStringCollection** method can be used to retrieve a pointer to an **IWMPStringCollection** interface representing all the values for the Genre attribute within the Audio media type. The **item** method can then be used to iterate through all of the possible values for the Genre attribute.

To use this method, read access to the library is required. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPMediaCollection::getAttributeStringCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection-getattributestringcollection)

[IWMPSettings2::get_mediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-get_mediaaccessrights)

[IWMPSettings2::requestMediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-requestmediaaccessrights)

[IWMPStringCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpstringcollection)