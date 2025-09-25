# COPP_HDCP_Protection_Level enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the HDCP protection level.

## Constants

### `COPP_HDCP_Level0:0`

HDCP protection is not enabled. See Remarks.

### `COPP_HDCP_LevelMin`

Minimum HDCP level. Equivalent to **COPP_HDCP_Level0**.

### `COPP_HDCP_Level1:1`

HDCP is enabled.

### `COPP_HDCP_LevelMax`

Maximum HDCP level. Equivalent to **COPP_HDCP_Level1**.

### `COPP_HDCP_ForceDWORD:0x7fffffff`

Reserved.

## Remarks

Some televisions do not have robust support for switching HDCP protection on and off. Because of this limitation, the graphics driver might leave HDCP enabled when the application sets the protection level to zero. If the application sets the HDCP level to zero, therefore, it might receive a COPP status message indicating that HDCP is still enabled. This is not an error.

For more information about HDCP, see http://www.digital-cp.com/.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)