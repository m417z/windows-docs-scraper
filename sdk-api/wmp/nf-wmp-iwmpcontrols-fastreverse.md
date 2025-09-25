# IWMPControls::fastReverse

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **fastReverse** method starts fast play of the media item in the reverse direction.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **fastReverse** method scans the clip in reverse at five times the normal speed, displaying only the key frames if it is a video file. Calling **fastReverse** is equivalent to specifying -5.0 for the rate through the **IWMPSettings::put_rate** method. If the rate is subsequently changed, or if **IWMPControls::play** or **IWMPControls::stop** is called, Windows Media Player will cease fast reverse.

If the item is part of a playlist, **fastReverse** stops at the beginning of the current track. For instance, if track 3 is in **fastReverse**, when the beginning of track 3 is reached, Windows Media Player will not go to track 2. The play count is not incremented when calling **fastReverse**.

If you call **IWMPControls::fastForward** while **fastReverse** is running, **fastReverse** will be stopped and **IWMPControls::fastForward** will begin.

This method does not work for live broadcasts and certain digital media types. To determine whether you can use fast reverse in a clip, call the **IWMPControls::get_isAvailable** method and pass in the **BSTR** value "FastReverse".

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls::fastForward](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-fastforward)

[IWMPControls::get_isAvailable](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-get_isavailable)

[IWMPControls::play](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-play)

[IWMPControls::stop](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-stop)

[IWMPSettings::put_rate](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_rate)