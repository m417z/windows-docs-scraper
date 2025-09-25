# IWMPMediaCollection::getAttributeStringCollection

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getAttributeStringCollection** method retrieves a pointer to an **IWMPStringCollection** interface. This interface represents the set of all values for a given attribute within a given media type.

## Parameters

### `bstrAttribute` [in]

String containing the attribute for which the values are retrieved.

### `bstrMediaType` [in]

String containing the media type for which the values are retrieved.

### `ppStringCollection` [out]

Pointer to a pointer to an **IWMPStringCollection** interface for the retrieved values.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

For information about the attributes supported by Windows Media Player, see the [Attribute Reference](https://learn.microsoft.com/windows/desktop/WMP/attribute-reference) section.

## See also

[IWMPMediaCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection)

[IWMPStringCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpstringcollection)