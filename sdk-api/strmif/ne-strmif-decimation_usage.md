# DECIMATION_USAGE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Describes the strategy that the [Overlay Mixer Filter](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) filter uses to scale the video image down to a smaller size.

## Constants

### `DECIMATION_LEGACY:0`

Decimate the video by taking the following steps, in the order listed, until one of them succeeds.

1. Try to use the overlay scaler on the VGA chip.
2. If the Overlay Mixer is connected through a video port, try to use the scaler on the video port.
3. Crop the video image.

### `DECIMATION_USE_DECODER_ONLY`

Decimate using the scaler on the video decoder. If that fails, crop the video image.

### `DECIMATION_USE_VIDEOPORT_ONLY`

Decimate using the scaler on the video port. If that fails, crop the video image.

### `DECIMATION_USE_OVERLAY_ONLY`

Decimate using the overlay scaler on the VGA chip. If that fails, crop the video image.

### `DECIMATION_DEFAULT`

Decimate the video by taking the following steps, in the order listed, until one of them succeeds.

1. Try to use the scaler on the video decoder.
2. Try to use the overlay scaler on the VGA chip.
3. If the Overlay Mixer is connected through a video port, try to use the scaler on the video port.
4. Crop the video image.

This mode is the default decimation strategy.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMVideoDecimationProperties](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideodecimationproperties)