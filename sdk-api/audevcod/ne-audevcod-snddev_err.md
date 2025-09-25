# SNDDEV_ERR enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies how the audio device was being accessed when the failure occurred.

## Constants

### `SNDDEV_ERROR_Open`

The audio device attempted to open.

### `SNDDEV_ERROR_Close`

The audio device attempted to close.

### `SNDDEV_ERROR_GetCaps`

The capabilities of the underlying hardware were being retrieved.

### `SNDDEV_ERROR_PrepareHeader`

The header for the audio device was being prepared.

### `SNDDEV_ERROR_UnprepareHeader`

The header for the audio device was being unprepared.

### `SNDDEV_ERROR_Reset`

The audio device attempted to reset.

### `SNDDEV_ERROR_Restart`

The audio device attempted to restart.

### `SNDDEV_ERROR_GetPosition`

The current and stop position settings were being retrieved.

### `SNDDEV_ERROR_Write`

The audio device was being written to.

### `SNDDEV_ERROR_Pause`

The audio device attempted to pause.

### `SNDDEV_ERROR_Stop`

The audio device attempted to stop.

### `SNDDEV_ERROR_Start`

The audio device attempted to start.

### `SNDDEV_ERROR_AddBuffer`

A buffer was being added to the audio device.

### `SNDDEV_ERROR_Query`

The audio device was being queried.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)