# COPP_StatusHDCPFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains HDCP status flags. This enumeration is used in the [DXVA_COPPStatusHDCPKeyData](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ns-dxva9typ-dxva_coppstatushdcpkeydata) structure.

## Constants

### `COPP_HDCPRepeater:0x01`

The device is an HDCP repeater.

### `COPP_HDCPFlagsReserved:0xFFFFFFFE`

Reserved. Must be zero.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)