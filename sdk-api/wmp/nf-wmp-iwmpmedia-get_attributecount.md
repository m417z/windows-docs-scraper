# IWMPMedia::get_attributeCount

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_attributeCount** method retrieves the number of attributes that can be queried and/or set for the media item.

## Parameters

### `plCount` [out]

Pointer to a **long** containing the count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

For information about the attributes supported by Windows Media Player, see the Windows Media Player [Attribute Reference](https://learn.microsoft.com/windows/desktop/WMP/attribute-reference).

**Windows Media Player 10 Mobile:** Attributes for a media item are available only during playback unless they are retrieved from the item through the media collection.

## See also

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)