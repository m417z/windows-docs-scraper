## Description

Represents an audio endpoint volume change APO notification.

## Members

### `endpoint`

An [IMMDevice](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-immdevice) representing the audio endpoint associated with the notification.

### `volume`

A pointer to a [AUDIO_VOLUME_NOTIFICATION_DATA](https://learn.microsoft.com/windows/win32/api/endpointvolume/ns-endpointvolume-audio_volume_notification_data) representing the new endpoint volume.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also