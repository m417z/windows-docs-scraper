# IWMPControls::get_currentMarker

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_currentMarker** method retrieves the current marker number.

## Parameters

### `plMarker` [out]

Pointer to a **long** containing the marker.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **get_currentMarker** method always retrieves a pointer to the current or last marker, which means the actual file position can be either at the current marker or before the next marker. Markers are numbered beginning at 1, so if a file has markers, you can change the current playback position to zero by calling **IWMPControls::put_currentMarker** to and specifying the marker as zero .

Until the current media item is set (using **IWMPCore::put_URL** or **IWMPCore::put_currentMedia**), **get_currentMarker** retrieves a marker that is zero.

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls::put_currentMarker](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-put_currentmarker)

[IWMPCore::put_URL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_url)

[IWMPCore::put_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-put_currentmedia)