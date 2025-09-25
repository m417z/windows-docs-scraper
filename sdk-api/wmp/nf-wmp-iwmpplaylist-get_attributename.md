# IWMPPlaylist::get_attributeName

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_attributeName** method retrieves the name of an attribute specified by an index.

## Parameters

### `lIndex` [in]

**long** containing the index.

### `pbstrAttributeName` [out]

Pointer to a **BSTR** containing the attribute name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The number of attributes is retrieved by the **get_attributeCount** method.

The *pbstAttributeName* string can be supplied to the **setItemInfo** or **getItemInfo** methods to specify or retrieve a value for the named attribute.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

For information about the attributes supported by Windows Media Player, see the Windows Media Player [Attribute Reference](https://learn.microsoft.com/windows/desktop/WMP/attribute-reference).

## See also

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPPlaylist::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-getiteminfo)

[IWMPPlaylist::get_attributeCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-get_attributecount)

[IWMPPlaylist::setItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylist-setiteminfo)