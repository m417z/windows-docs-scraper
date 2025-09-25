# IAudioSessionControl2::SetDuckingPreference

## Description

The **SetDuckingPreference** method enables or disables the default stream attenuation experience (auto-ducking) provided by the system.

## Parameters

### `optOut` [in]

A **BOOL** variable that enables or disables system auto-ducking.

## Return value

If the method succeeds, it returns S_OK.
If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return value | Description |
| --- | --- |
| AUDCLNT_E_DEVICE_INVALIDATED | The audio session is disconnected on the default audio device. |

## Remarks

 By default, the system adjusts the volume for all currently playing sounds when the system starts a communication session and receives a new communication stream on the default communication device. For more information about this feature, see [Using a Communication Device](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-communication-device).

If the application passes **TRUE** in *optOut*, the system disables the [Default Ducking Experience](https://learn.microsoft.com/windows/desktop/CoreAudio/stream-attenuation). For more information, see [Disabling the Default Ducking Experience](https://learn.microsoft.com/windows/desktop/CoreAudio/disabling-the-ducking-experience).

To provide a custom implementation, the application needs to get notifications from the system when it opens or closes the communication stream. To receive the notifications, the application must call this method before registering itself by calling **IAudioSessionManager2::RegisterForDuckNotification**. For more information and example code, see [Getting Ducking Events](https://learn.microsoft.com/windows/desktop/CoreAudio/getting-ducking-events-from-a-communication-device).

If the application passes **FALSE** in *optOut*, the application provides the default stream attenuation experience provided by the system.

We recommend that the application call **SetDuckingPreference** during stream creation. However, this method can be called dynamically during the session to change the initial preference.

## See also

[IAudioSessionControl2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol2)