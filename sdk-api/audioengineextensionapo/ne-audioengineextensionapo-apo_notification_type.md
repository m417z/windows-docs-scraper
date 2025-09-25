## Description

Specifies the type of an [APO_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-apo_notification).

## Constants

### `APO_NOTIFICATION_TYPE_NONE:0`

None.

### `APO_NOTIFICATION_TYPE_ENDPOINT_VOLUME:1`

Endpoint volume notification. The [AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_volume_change_notification) structure conveys data for this notification.

### `APO_NOTIFICATION_TYPE_ENDPOINT_PROPERTY_CHANGE:2`

Endpoint property change notification. The [AUDIO_ENDPOINT_PROPERTY_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_property_change_notification) structure conveys data for this notification.

### `APO_NOTIFICATION_TYPE_SYSTEM_EFFECTS_PROPERTY_CHANGE:3`

System effects property change notification. The [AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_systemeffects_property_change_notification) structure conveys data for this notification.

### `APO_NOTIFICATION_TYPE_ENDPOINT_VOLUME2:4`

Endpoint volume notification for an endpoint that includes master and channel volume, in dB. The [AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION2](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_volume_change_notification2) structure conveys data for this notification.

### `APO_NOTIFICATION_TYPE_DEVICE_ORIENTATION:5`

Display orientation notification for the device. The [DEVICE_ORIENTATION_TYPE](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ne-audioengineextensionapo-device_orientation_type) enumeration conveys data for this notification.

### `APO_NOTIFICATION_TYPE_MICROPHONE_BOOST:6`

Microphone boost notification. The [AUDIO_MICROPHONE_BOOST_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_microphone_boost_notification) structure conveys data for this notification.

### `APO_NOTIFICATION_TYPE_AUDIO_ENVIRONMENT_STATE_CHANGE`

An audio environment state change notification. The [AUDIO_ENVIRONMENT_STATE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_environment_state_change_notification) structure conveys data for this notification.

## Remarks

Clients use this enumeration to specify requested notification types in their implementations of [IAudioProcessingObjectNotifications2::GetApoNotificationRegistrationInfo2](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications2-getaponotificationregistrationinfo2) and [IAudioProcessingObjectNotifications::GetApoNotificationRegistrationInfo](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications-getaponotificationregistrationinfo).

The [APO_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-apo_notification) structure passed into [HandleNotification](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications-handlenotification) will contain a different structure in its union field depending on which type of notification is being raised. For more information, see [APO_NOTIFICATION Structure](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-apo_notification).

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also