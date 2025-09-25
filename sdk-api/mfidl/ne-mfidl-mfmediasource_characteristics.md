# MFMEDIASOURCE_CHARACTERISTICS enumeration

## Description

Defines the characteristics of a media source. These flags are retrieved by the [IMFMediaSource::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-getcharacteristics) method.

## Constants

### `MFMEDIASOURCE_IS_LIVE:0x1`

This flag indicates a data source that runs constantly, such as a live presentation. If the source is stopped and then restarted, there will be a gap in the content.

### `MFMEDIASOURCE_CAN_SEEK:0x2`

The media source supports seeking.

### `MFMEDIASOURCE_CAN_PAUSE:0x4`

The source can pause.

### `MFMEDIASOURCE_HAS_SLOW_SEEK:0x8`

The media source downloads content. It might take a long time to seek to parts of the content that have not been downloaded.

### `MFMEDIASOURCE_HAS_MULTIPLE_PRESENTATIONS:0x10`

The media source delivers a playlist, which might contain more than one entry. After the first playlist entry has completed, the media source signals the start of each new playlist entry by sending an [MENewPresentation](https://learn.microsoft.com/windows/desktop/medfound/menewpresentation) event. The event contains a presentation descriptor for the entry.

**Note** Requires Windows 7 or later.

### `MFMEDIASOURCE_CAN_SKIPFORWARD:0x20`

The media source can skip forward in the playlist. Applies only if the MFMEDIASOURCE_HAS_MULTIPLE_PRESENTATIONS flag is present.

**Note** Requires Windows 7 or later.

### `MFMEDIASOURCE_CAN_SKIPBACKWARD:0x40`

The media source can skip backward in the playlist.

**Note** Requires Windows 7 or later.

### `MFMEDIASOURCE_DOES_NOT_USE_NETWORK:0x80`

The media source is not currently
using the network to receive the content. Networking hardware
may enter a power saving state when this bit is set.

**Note** Requires Windows 8 or later.

## Remarks

To skip forward or backward in a playlist, call [IMFMediaSource::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-start) or [IMFMediaSession::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-start) with the **MF_TIME_FORMAT_ENTRY_RELATIVE** time-format GUID. This capability applies only when the **MFMEDIASOURCE_HAS_MULTIPLE_PRESENTATIONS** flag is present.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)