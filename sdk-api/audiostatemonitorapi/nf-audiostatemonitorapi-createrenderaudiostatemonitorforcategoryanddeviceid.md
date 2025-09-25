## Description

Creates a new instance of [IAudioStateMonitor](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nn-audiostatemonitorapi-iaudiostatemonitor) for render streams with the specified audio category and audio device ID.

## Parameters

### `category` [in]

A member of the [AUDIO_STREAM_CATEGORY](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category) enumeration specifying the audio stream category for which the audio state monitor is created.

### `deviceId` [in]

The unique identifier of the audio device for which the audio state monitor is created. The endpoint may be specified using the MMDevice ID, obtained using [IMMDevice::GetId](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-immdevice-getid), or by using its SWD ID, obtained using [Windows.Devices.Enumeration](https://learn.microsoft.com/uwp/api/windows.devices.enumeration) or [Windows.Media.Devices.MediaDevice](https://learn.microsoft.com/uwp/api/windows.media.devices.mediadevice).

### `audioStateMonitor` [out]

Receives a pointer to the created **IAudioStateMonitor**.

## Return value

Returns an HRESULT including the following values.

| Value | Description |
|-------|-------------|
| S_OK | Success. |

## Remarks

## See also