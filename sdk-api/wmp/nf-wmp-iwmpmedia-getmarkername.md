# IWMPMedia::getMarkerName

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getMarkerName** method retrieves the name of the marker at the specified index.

## Parameters

### `MarkerNum` [in]

**long** specifying the marker index.

### `pbstrMarkerName` [out]

Pointer to a **BSTR** containing the marker name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method returns **NULL** if the specified marker does not exist.

Some media items do not contain markers. Use **get_markerCount** to find out how many markers are in the current media item.

Marker index numbers start at 1.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPMedia::get_markerCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-get_markercount)