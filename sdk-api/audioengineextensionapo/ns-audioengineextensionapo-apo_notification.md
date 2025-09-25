## Description

Represents a notification for a change to an APO endpoint or system effects.

## Members

### `type`

A value from the [APO_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ne-audioengineextensionapo-apo_notification_type) enumeration specifying the type of change the notification represents.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.audioEndpointVolumeChange`

When *type* is APO_NOTIFICATION_TYPE_ENDPOINT_VOLUME, the union value is an [AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_volume_change_notification) representing a notification of a change to APO endpoint volume.

### `DUMMYUNIONNAME.audioEndpointPropertyChange`

When *type* is APO_NOTIFICATION_TYPE_ENDPOINT_PROPERTY_CHANGE, the union value is an [AUDIO_ENDPOINT_PROPERTY_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_property_change_notification) representing a notification of a change to an APO endpoint property.

### `DUMMYUNIONNAME.audioSystemEffectsPropertyChange`

When *type* is APO_NOTIFICATION_TYPE_ENDPOINT_PROPERTY_CHANGE, the union value is an [AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_systemeffects_property_change_notification) representing a notification of a change to an APO system effect property.

### `DUMMYUNIONNAME.audioEndpointVolumeChange2`

When *type* is APO_NOTIFICATION_TYPE_ENDPOINT_VOLUME2, the union value is an [AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION2](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_endpoint_volume_change_notification2) representing a notification of a change to APO endpoint volume that includes master and channel volume, in dB.

### `DUMMYUNIONNAME.deviceOrientation`

When *type* is APO_NOTIFICATION_TYPE_DEVICE_ORIENTATION, the union value is a [DEVICE_ORIENTATION_TYPE](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ne-audioengineextensionapo-device_orientation_type) representing a device orientation value.

### `DUMMYUNIONNAME.audioMicrophoneBoostChange`

When *type* is APO_NOTIFICATION_TYPE_MICROPHONE_BOOST, the union value is a [AUDIO_MICROPHONE_BOOST_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_microphone_boost_apo_notification_descriptor) representing an endpoint microphone boost APO notification.

### `DUMMYUNIONNAME.audioEnvironmentChange`

When *type* is APO_NOTIFICATION_TYPE_AUDIO_ENVIRONMENT_STATE_CHANGE, the union value is a [AUDIO_ENVIRONMENT_STATE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-audio_environment_state_change_notification) representing an audio environment change APO notification.

## Remarks

Register for the types of notifications you want to receive by implementing [IAudioProcessingObjectNotifications::GetApoNotificationRegistrationInfo](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications-getaponotificationregistrationinfo). Receive the registered notifications by implementing [IAudioProcessingObjectNotifications::HandleNotification](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications-handlenotification).

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also