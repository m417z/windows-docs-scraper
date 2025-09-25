## Description

Creates a new instance of [IAudioStateMonitor](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nn-audiostatemonitorapi-iaudiostatemonitor) for render streams with the specified audio stream category.

## Parameters

### `category` [in]

A member of the [AUDIO_STREAM_CATEGORY](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category) enumeration specifying the audio stream category for which the audio state monitor is created.

### `audioStateMonitor` [out]

Receives a pointer to the created **IAudioStateMonitor**.

## Return value

Returns an HRESULT including the following values.

| Value | Description |
|-------|-------------|
| S_OK | Success. |

## Remarks

## See also