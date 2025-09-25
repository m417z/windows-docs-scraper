# IsMediaBehaviorEnabled function

## Description

Gets a value indicating whether the media behavior associated with the specified GUID is enabled.

## Parameters

### `mediaBehavior`

A GUID that specifies the media behavior for which the enabled state is queried.

## Return value

True if the specified media behavior is enabled; otherwise, false.

## Remarks

Currently, the only value supported for this function is **MEDIA_BEHAVIOR_MEDIAPLAYBACKLIST_AUTOPLAYBACKITEMRESET** which causes media items in a [MediaPlaybackList](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlaybackList) to be automatically reset after being played.