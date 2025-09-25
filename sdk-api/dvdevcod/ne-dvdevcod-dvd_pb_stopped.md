# DVD_PB_STOPPED enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The DVD_PB_STOPPED enumeration value has flags that indicate why DVD playback stopped. This flag is sent in the *lParam1* parameter of the [EC_DVD_PLAYBACK_STOPPED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-playback-stopped) event.

## Constants

### `DVD_PB_STOPPED_Other:0`

Unspecified reason.

### `DVD_PB_STOPPED_NoBranch:1`

The current program chain (PGC) completed and the DVD Navigator found no other video or other branching instructions.

### `DVD_PB_STOPPED_NoFirstPlayDomain:2`

The disc does not contain an initial startup program.

### `DVD_PB_STOPPED_StopCommand:3`

The application stopped playback or a DVD Navigator reached a stop command on the disc.

### `DVD_PB_STOPPED_Reset:4`

The DVD Navigator was reset to the start of the disc.

### `DVD_PB_STOPPED_DiscEjected:5`

The disc was ejected.

### `DVD_PB_STOPPED_IllegalNavCommand:6`

An invalid navigation command prevented playback from continuing.

### `DVD_PB_STOPPED_PlayPeriodAutoStop:7`

Playback reached the end time that was specified by the application.

### `DVD_PB_STOPPED_PlayChapterAutoStop:8`

Playback reached the end of the chapter.

### `DVD_PB_STOPPED_ParentalFailure:9`

Playback was stopped because of the parental level.

### `DVD_PB_STOPPED_RegionFailure:10`

Playback was stopped because the region did not match.

### `DVD_PB_STOPPED_MacrovisionFailure:11`

Playback was stopped because of analog copy protection.

### `DVD_PB_STOPPED_DiscReadError:12`

An error occurred while reading the disc.

### `DVD_PB_STOPPED_CopyProtectFailure:13`

Playback was stopped because of copy protection.

### `DVD_PB_STOPPED_CopyProtectOutputFailure:14`

The disc cannot be played because the video display does not meet the copy protection requirements.

### `DVD_PB_STOPPED_CopyProtectOutputNotSupported:15`

The disc cannot be played because the driver does not support checking the video display.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)