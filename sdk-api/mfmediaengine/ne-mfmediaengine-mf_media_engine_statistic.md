# MF_MEDIA_ENGINE_STATISTIC enumeration

## Description

Identifies statistics that the Media Engine tracks during playback. To get a playback statistic from the Media Engine, call [IMFMediaEngineEx::GetStatistics](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-getstatistics).

In the descriptions that follow, the data type and value-type tag for the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) are listed in parentheses.

## Constants

### `MF_MEDIA_ENGINE_STATISTIC_FRAMES_RENDERED:0`

The number of rendered video frames. (**ULONG**, **VT_UI4**)

### `MF_MEDIA_ENGINE_STATISTIC_FRAMES_DROPPED:1`

The number of dropped video frames. (**ULONG**, **VT_UI4**)

### `MF_MEDIA_ENGINE_STATISTIC_BYTES_DOWNLOADED:2`

The number of bytes that have been downloaded since the last HTTP range request. (**ULARGE_INTEGER**, **VT_UI8**).

### `MF_MEDIA_ENGINE_STATISTIC_BUFFER_PROGRESS:3`

The percentage of the playout buffer filled during buffering. The value is an integer in the range 0–100. (**LONG**, **VT_I4**)

### `MF_MEDIA_ENGINE_STATISTIC_FRAMES_PER_SECOND:4`

The frames per second. (**FLOAT**, **VT_R4**)

### `MF_MEDIA_ENGINE_STATISTIC_PLAYBACK_JITTER:5`

The amount of playback jitter. (**DOUBLE**, **VT_R8**)

Supported in Windows 8.1 and later.

### `MF_MEDIA_ENGINE_STATISTIC_FRAMES_CORRUPTED:6`

The number of corrupted frames. (**ULONG**, **VT_UI4**)

Supported in Windows 8.1 and later.

### `MF_MEDIA_ENGINE_STATISTIC_TOTAL_FRAME_DELAY:7`

The total amount of frame delay. (**DOUBLE**, **VT_R8**)

Supported in Windows 8.1 and later.

## See also

[IMFMediaEngineEx::GetStatistics](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-getstatistics)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)