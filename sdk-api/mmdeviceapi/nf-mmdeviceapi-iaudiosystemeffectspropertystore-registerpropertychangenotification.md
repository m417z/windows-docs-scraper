## Description

Registers an [IAudioSystemEffectsPropertyChangeNotificationClient](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-iaudiosystemeffectspropertychangenotificationclient) callback interface to receive notifications when audio system effect properties change.

## Parameters

### `callback`

A pointer to the **IAudioSystemEffectsPropertyChangeNotificationClient** callback interface to register.

## Return value

Returns S_OK on success.

## Remarks

This method should not be used by APOs and should only be used by hardware support apps to register for notifications.

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also