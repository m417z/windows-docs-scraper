# IAMCertifiedOutputProtection::ProtectionCommand

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ProtectionCommand` method sends a COPP command to the graphics driver.

## Parameters

### `cmd` [in]

Pointer to an [AMCOPPCommand](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppcommand) structure that contains the command.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Invalid state. Possibly the application passed unexpected data, or called **IAMCertifiedOutputProtection** methods in the wrong order. |
| **VFW_E_NO_COPP_HW** | The display device does not support COPP; or the VMR has not connected to a display device yet. |

## See also

[IAMCertifiedOutputProtection Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcertifiedoutputprotection)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)