## Description

Represents an audio endpoint volume change APO notification. This is an updated version of [AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_volume_change_notification) that provides additional information in about the volume change event.

## Members

### `endpoint`

An [IMMDevice](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-immdevice) representing the audio endpoint associated with the notification.

### `volume`

A pointer to a [AUDIO_VOLUME_NOTIFICATION_DATA2](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_volume_notification_data2) containing information about the volume change event.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also