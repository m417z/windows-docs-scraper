# MF_MEDIA_ENGINE_READY enumeration

## Description

Defines ready-state values for the Media Engine.

## Constants

### `MF_MEDIA_ENGINE_READY_HAVE_NOTHING:0`

No data is available.

### `MF_MEDIA_ENGINE_READY_HAVE_METADATA:1`

Some metadata is available, including the duration and, for video files, the video dimensions. No media data is available.

### `MF_MEDIA_ENGINE_READY_HAVE_CURRENT_DATA:2`

There is media data for the current playback position, but not enough data for playback or seeking.

### `MF_MEDIA_ENGINE_READY_HAVE_FUTURE_DATA:3`

There is enough media data to enable some playback or seeking. The amount of data might be a little as the next video frame.

### `MF_MEDIA_ENGINE_READY_HAVE_ENOUGH_DATA:4`

There is enough data to play the resource, based on the current rate at which the resource is being fetched.

## Remarks

These values correspond to constants defined for the **HTMLMediaElement.readyState** attribute in HTML5.

## See also

[IMFMediaEngine::GetReadyState](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-getreadystate)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)