# IAMCertifiedOutputProtection::ProtectionStatus

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ProtectionStatus` method sends a COPP status request to the graphics driver.

## Parameters

### `pStatusInput` [in]

Pointer to an [AMCOPPStatusInput](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppstatusinput) structure that contains the status request.

### `pStatusOutput` [out]

Pointer to an [AMCOPPStatusOutput](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppstatusoutput) structure. The method fills this structure with the driver's response.

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