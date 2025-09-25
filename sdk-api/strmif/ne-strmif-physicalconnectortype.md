# PhysicalConnectorType enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the physical type of pin (audio or video).

## Constants

### `PhysConn_Video_Tuner:1`

Specifies a tuner pin for video.

### `PhysConn_Video_Composite`

Specifies a composite pin for video.

### `PhysConn_Video_SVideo`

Specifies an S-Video (Y/C video) pin.

### `PhysConn_Video_RGB`

Specifies an RGB pin for video.

### `PhysConn_Video_YRYBY`

Specifies a YRYBY (Y, R–Y, B–Y) pin for video.

### `PhysConn_Video_SerialDigital`

Specifies a serial digital pin for video.

### `PhysConn_Video_ParallelDigital`

Specifies a parallel digital pin for video.

### `PhysConn_Video_SCSI`

Specifies a SCSI (Small Computer System Interface) pin for video.

### `PhysConn_Video_AUX`

Specifies an AUX (auxiliary) pin for video.

### `PhysConn_Video_1394`

Specifies an IEEE 1394 pin for video.

### `PhysConn_Video_USB`

Specifies a USB (Universal Serial Bus) pin for video.

### `PhysConn_Video_VideoDecoder`

Specifies a video decoder pin.

### `PhysConn_Video_VideoEncoder`

Specifies a video encoder pin.

### `PhysConn_Video_SCART`

Specifies a SCART (Peritel) pin for video.

### `PhysConn_Video_Black`

Not used.

### `PhysConn_Audio_Tuner:0x1000`

Specifies a tuner pin for audio.

### `PhysConn_Audio_Line`

Specifies a line pin for audio.

### `PhysConn_Audio_Mic`

Specifies a microphone pin.

### `PhysConn_Audio_AESDigital`

Specifies an AES/EBU (Audio Engineering Society/European Broadcast Union) digital pin for audio.

### `PhysConn_Audio_SPDIFDigital`

Specifies an S/PDIF (Sony/Philips Digital Interface Format) digital pin for audio.

### `PhysConn_Audio_SCSI`

Specifies a SCSI pin for audio.

### `PhysConn_Audio_AUX`

Specifies an AUX pin for audio.

### `PhysConn_Audio_1394`

Specifies an IEEE 1394 pin for audio.

### `PhysConn_Audio_USB`

Specifies a USB pin for audio.

### `PhysConn_Audio_AudioDecoder`

Specifies an audio decoder pin.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)