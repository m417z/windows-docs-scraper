# IWMPControls::fastForward

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **fastForward** method starts fast play of the media item in the forward direction.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **fastForward** method plays the clip back at five times the normal speed. Calling **fastForward** is equivalent to specifying 5.0 for the rate through the **IWMPSettings::put_rate** method. If the rate is subsequently changed, or if **IWMPControls::play** or **IWMPControls::stop** is called, Windows Media Player will cease fast forwarding.

The **fastForward** method does not work for live broadcasts and certain media types. To determine whether you can fast forward in a clip, call the **IWMPControls::get_isAvailable** method and pass in the **BSTR** value "FastForward".

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls::get_isAvailable](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-get_isavailable)

[IWMPControls::play](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-play)

[IWMPControls::stop](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-stop)

[IWMPSettings::put_rate](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_rate)