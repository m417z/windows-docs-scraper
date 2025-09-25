# IWMPSettings::get_rate

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_rate** method retrieves the current playback rate for video.

## Parameters

### `pdRate` [out]

Pointer to a **double** containing the rate with a default value of 1.0.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The value retrieved by this method acts as a multiplier value that enables you to play a media item at a faster or slower rate. The default value of 1.0 indicates the authored speed.

Note that an audio track becomes difficult to understand at rates lower than 0.5 or higher than 1.5. A playback rate of 2 equates to twice the normal playback speed.

Windows Media Player will attempt to use the most effective of the following four different playback modes

* Smooth video playback with audio pitch maintained
* Smooth video playback with audio pitch not maintained
* Smooth video playback with no audio
* Keyframe video playback with no audio

The mode chosen by Windows Media Player depends on numerous factors including file type and location, operating system, network, and server.

Other considerations apply as well, depending on the digital media format used to create the content:

* **Windows Media Video (WMV) and ASF.** Optimal values for this property are from 1 to 10, or from –1 to –10 for reverse play. Values from 0.5 to 1.0 or from -0.5 to -1.0 may also work well in cases where audio pitch can be maintained, such as when playing files located on the local computer. Values with an absolute magnitude greater than 10 are allowed, but are not very meaningful.
* **Other video formats.** This property can range from 0 to 9. Negative values are not allowed. Values less than 1 represent slow motion. Values above 9 are allowed, but are not very meaningful.

The **IWMPControls::fastForward method** changes the value retrieved by **get_rate** to 5.0, while the **IWMPControls::fastReverse** method changes the value retrieved by **get_rate** to –5.0.

The playback rate of some digital media formats cannot be altered. Use the **IWMPSettings::get_isAvailable** method to determine whether this property can be specified for a particular media item.

**Windows Media Player 10 Mobile:** This method only retrieves a **long** set to -2.0, 1.0, or 2.0.

## See also

[IWMPControls::fastForward](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-fastforward)

[IWMPControls::fastReverse](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-fastreverse)

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::get_isAvailable](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-get_isavailable)

[IWMPSettings::get_mute](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-get_mute)

[IWMPSettings::put_rate](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_rate)