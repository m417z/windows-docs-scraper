# DXVA_COPPStatusData structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains the result from a Certified Output Protection Protocol (COPP) status request.

## Members

### `rApp`

A 128-bit random number that was passed by the application in the [AMCOPPStatusInput](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppstatusinput) structure.

### `dwFlags`

Status flag. See [COPP_StatusFlags](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_statusflags).

### `dwData`

Response to the status query. The meaning of this value depends on the status request. For more information, see [COPP Query Reference](https://learn.microsoft.com/windows/desktop/DirectShow/copp-query-reference).

### `ExtendedInfoValidMask`

Reserved. Must be zero.

### `ExtendedInfoData`

Reserved. Must be zero.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)