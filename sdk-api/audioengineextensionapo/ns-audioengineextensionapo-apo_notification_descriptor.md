## Description

Specifies a requested APO notification.

## Members

### `type`

A value from the [APO_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ne-audioengineextensionapo-apo_notification_type) enumeration

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.audioEndpointVolume`

An [AUDIO_ENDPOINT_VOLUME_APO_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_volume_apo_notification_descriptor) specifying an endpoint volume change APO notification.

### `DUMMYUNIONNAME.audioEndpointPropertyChange`

An [AUDIO_ENDPOINT_PROPERTY_CHANGE_APO_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_property_change_apo_notification_descriptor) specifying an endpoint property change APO notification.

### `DUMMYUNIONNAME.audioSystemEffectsPropertyChange`

An [AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_APO_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_systemeffects_property_change_apo_notification_descriptor) specifying a system effects property change APO notification.

### `DUMMYUNIONNAME.audioMicrophoneBoost`

An [AUDIO_MICROPHONE_BOOST_APO_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_microphone_boost_apo_notification_descriptor) specifying a microphone boost APO notifications.

## Remarks

Return this structure from an implementation of [IAudioProcessingObjectNotifications::GetApoNotificationRegistrationInfo](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications-getaponotificationregistrationinfo) or [IAudioProcessingObjectNotifications2::GetApoNotificationRegistrationInfo2](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications2-getaponotificationregistrationinfo2) to specify a requested APO notifications.

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also