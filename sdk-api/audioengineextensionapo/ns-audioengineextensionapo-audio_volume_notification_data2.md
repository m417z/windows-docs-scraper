## Description

Represents information about a volume change notification event. This structure is used by the [AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION2](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_volume_change_notification2) structure.

## Members

### `notificationData`

An [AUDIO_VOLUME_NOTIFICATION_DATA](https://learn.microsoft.com/windows/win32/api/endpointvolume/ns-endpointvolume-audio_volume_notification_data) structure containing additional information about the volume change event.

### `masterVolumeInDb`

A float value representing the current master volume level of the audio stream in dB.

### `volumeMinInDb`

A float value representing the minimum volume level of the endpoint in decibels. This value remains constant for the lifetime of the audio device specified in the associated [AUDIO_ENDPOINT_VOLUME_APO_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_volume_apo_notification_descriptor).

### `volumeMaxInDb`

A float value representing the maximum volume level of the endpoint in decibels. This value remains constant for the lifetime of the audio device specified in the associated **AUDIO_ENDPOINT_VOLUME_APO_NOTIFICATION_DESCRIPTOR**.

### `volumeIncrementInDb`

A float value representing the volume increment of the endpoint in decibels. This value remains constant for the lifetime of the audio device specified in the associated **AUDIO_ENDPOINT_VOLUME_APO_NOTIFICATION_DESCRIPTOR**.

### `step`

An unsigned integer value representing the current step in the volume range. Is a value in the range from 0 to *stepCount* - 1, where 0 represents the minimum volume level and *stepCount* - 1 represents the maximum level.

### `stepCount`

An unsigned integer value representing the number of steps in the volume range. This value remains constant for the lifetime of the audio device specified in the associated **AUDIO_ENDPOINT_VOLUME_APO_NOTIFICATION_DESCRIPTOR**.

### `channelVolumesInDb`

The first element in an array of channel volumes in dB. This element contains the current volume level of channel 0 in the audio stream. If the audio stream contains more than one channel, the volume levels for the additional channels immediately follow the **AUDIO_VOLUME_NOTIFICATION_DATA2** structure.

## Remarks

## See also