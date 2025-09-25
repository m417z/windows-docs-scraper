# IWMPMedia::setItemInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **setItemInfo** method sets the value of the specified attribute for the media item.

## Parameters

### `bstrItemName` [in]

**BSTR** containing the attribute name.

### `bstrVal` [in]

**BSTR** containing the new value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **get_attributeCount** method retrieves the number of attributes available for a given media item. Index numbers can then be used with the **getAttributeName** method to determine the names of the built-in attributes that can be used with this method.

Before using this method, use the **isReadOnlyItem** method to determine whether a particular attribute can be set.

Before calling this method, you must have full access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

Note

If you embed the Windows Media Player control in your application, file attributes that you change will not be written to the digital media file until the user runs Windows Media Player. If you use the control in a remoted application written in C++, file attributes that you change will be written to the digital media file shortly after you make the changes. In either case, the changes are immediately available to you through the library.

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPMedia::getAttributeName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getattributename)

[IWMPMedia::get_attributeCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-get_attributecount)

[IWMPMedia::isReadOnlyItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-isreadonlyitem)