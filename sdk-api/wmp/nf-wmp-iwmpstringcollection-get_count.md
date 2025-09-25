# IWMPStringCollection::get_count

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_count** method retrieves the number of items in the string collection.

## Parameters

### `plCount` [out]

Pointer to a **long** containing the count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To retrieve the value of this method, read access to the library is required. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPSettings2::get_mediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-get_mediaaccessrights)

[IWMPSettings2::requestMediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-requestmediaaccessrights)

[IWMPStringCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpstringcollection)