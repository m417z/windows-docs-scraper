## Description

Called by the system to notify clients of changes to APO endpoints or system effects.

## Parameters

### `apoNotification`

An [APO_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-apo_notification) representing the APO change associated with the notification.

## Remarks

 Specify the set of APO changes for which this method is called by implementing [IAudioProcessingObjectNotifications::GetApoNotificationRegistrationInfo](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectnotifications-getaponotificationregistrationinfo).

This method will be called after [LockForProcess](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobjectconfiguration-lockforprocess) is called and will stop being called before [UnlockForProcess](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobjectconfiguration-unlockforprocess). If there are any notifications in flight, they might get executed during or after **UnlockForProcess**. The APO must handle synchronization in this case.

> [!NOTE]
> APOs must query each property once to get its initial value because **HandleNotification** method is only invoked when any of the properties have changed. The exceptions to this are the initial audio endpoint volume when the APO registers for APO_NOTIFICATION_TYPE_ENDPOINT_VOLUME and the value of PKEY_AudioEndpoint_Disable_SysFx if the APO registers for APO_NOTIFICATION_TYPE_ENDPOINT_PROPERTY_CHANGE

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also