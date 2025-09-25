# IWMPControls::put_currentMarker

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_currentMarker** method specifies the current marker number.

## Parameters

### `lMarker` [in]

**long** containing the marker.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Specifying a marker with the **put_currentMarker** method causes playback to start from that marker. Before attempting to specify a marker with **put_currentMarker**, determine whether a file has markers and how many it has by calling **IWMPMedia::get_markerCount**. If a file has no markers, specifying a marker to anything but zero by using **put_currentMarker** results in an error. Specifying a marker to a number higher than a number retrieved by using **IWMPMedia::get_markerCount** also results in an error.

Until the current media item is set (using **IWMPCore::put_URL** or **IWMPCore::put_currentMedia**), **get_currentMarker** retrieves a marker that is zero.

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls::get_currentMarker](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-get_currentmarker)

[IWMPCore::put_URL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_url)

[IWMPCore::put_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_currentmedia)

[IWMPMedia::get_markerCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-get_markercount)