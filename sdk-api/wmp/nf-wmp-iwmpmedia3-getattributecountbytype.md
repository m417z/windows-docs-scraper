# IWMPMedia3::getAttributeCountByType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getAttributeCountByType** method retrieves the number of attributes associated with the specified attribute type.

## Parameters

### `bstrType` [in]

**BSTR** containing the type.

### `bstrLanguage` [in]

**BSTR** containing the language. If the value is set to null or "" (empty string), the current locale string is used. Otherwise, the value must be a valid RFC 1766 language string such as "en-us".

### `plCount` [out]

Pointer to a **long** containing the count of attributes that are associated with the type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is used to determine the number of attributes corresponding to a particular attribute name for a given media item. Index numbers can then be passed to the **getItemInfoByType** method. This is useful, for example, when a media item has been categorized under multiple genres.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method always retrieves a **long** set to 0.

## See also

[IWMPMedia3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia3)

[IWMPMedia3::getItemInfoByType](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia3-getiteminfobytype)