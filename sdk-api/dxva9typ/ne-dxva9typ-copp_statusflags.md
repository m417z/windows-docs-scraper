# COPP_StatusFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the status of a Certified Output Protection Protocol (COPP) session.

## Constants

### `COPP_StatusNormal:0x00`

Normal status.

### `COPP_LinkLost:0x01`

The integrity of the connection has been compromised. Examples of events that cause the driver to set this flag include:

* The driver can no longer enforce the current protection level.
* The driver detected an internal integrity error.
* The connector between the computer and the display device was unplugged.

### `COPP_RenegotiationRequired:0x02`

The connection configuration has changed. For example, the user has changed the desktop display mode.

### `COPP_StatusFlagsReserved:0xFFFFFFFC`

Reserved. Must be zero.

## Remarks

If COPP_LinkLost is returned, the application should release the current instance of the VMR, create a new instance of the VMR, and establish a new COPP session (including key exchange and certificate validation).

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)