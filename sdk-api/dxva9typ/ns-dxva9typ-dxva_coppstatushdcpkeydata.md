# DXVA_COPPStatusHDCPKeyData structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains the result from an HDCP Key Data query in Certified Output Protection Protocol (COPP). This query returns the device's HDCP key selection vector (KSV).

## Members

### `rApp`

A 128-bit random number that was passed by the application in the [AMCOPPStatusInput](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppstatusinput) structure.

### `dwFlags`

Status flag. See [COPP_StatusFlags](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_statusflags).

### `dwHDCPFlags`

Receives zero or more flags from the [COPP_StatusHDCPFlags](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_statushdcpflags) enumeration. If the COPP_HDCPRepeater flag is present, the application should not play the content using this graphics adapter.

### `BKey`

Receives the HDCP key selection vector, BKSV, from the HDSCP device attached to the graphics adapter.

### `Reserved1`

Reserved. Must be zero.

### `Reserved2`

Reserved. Must be zero.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)