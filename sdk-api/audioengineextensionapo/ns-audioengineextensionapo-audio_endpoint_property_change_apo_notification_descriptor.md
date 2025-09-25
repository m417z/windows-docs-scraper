## Description

Specifies an endpoint property change APO notification.

## Members

### `device`

An [IMMDevice](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-immdevice) representing the audio endpoint associated with the notification.

## Remarks

Return an [APO_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-apo_notification_descriptor) containing this structure from an implementation of [IAudioProcessingObjectNotifications::GetApoNotificationRegistrationInfo](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications-getaponotificationregistrationinfo) to request endpoint property change APO notifications.

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also