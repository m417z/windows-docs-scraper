# IWMPMediaCollection::remove

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **remove** method removes a specified item from the media collection.

## Parameters

### `pItem` [in]

Pointer to an **IWMPMedia** interface that identifies the item to remove.

### `varfDeleteFile` [in]

Specifies whether the method should remove the specified item.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method deletes an item from the library. This method does not delete files from the user's computer.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPMediaCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection)

[IWMPMediaCollection::add](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection-add)