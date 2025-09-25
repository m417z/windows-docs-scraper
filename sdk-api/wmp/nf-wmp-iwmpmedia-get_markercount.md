# IWMPMedia::get_markerCount

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_markerCount** method retrieves the number of markers in the media item.

## Parameters

### `pMarkerCount` [out]

Pointer to a **long** that contains the marker count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method returns zero if a file has no markers, or if the media item is not the same as the one specified in **IWMPCore::get_currentMedia**.

Marker numbers start at 1.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPCore::get_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_currentmedia)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)