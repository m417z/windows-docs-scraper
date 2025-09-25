# IWMPMediaCollection::getMediaAtom

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getMediaAtom** method retrieves the index at which a given attribute resides within the set of available attributes.

## Parameters

### `bstrItemName` [in]

String containing the name of the item for which the index should be retrieved.

### `plAtom` [out]

Pointer to a **long** containing the index.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The index number retrieved with this method can be passed to the **IWMPMedia::getItemInfoByAtom** to access attribute values. This technique is generally more efficient when working with large playlists than accessing an attribute value by name through **IWMPMedia::getItemInfo**.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPMedia::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getiteminfo)

[IWMPMedia::getItemInfoByAtom](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getiteminfobyatom)

[IWMPMediaCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection)