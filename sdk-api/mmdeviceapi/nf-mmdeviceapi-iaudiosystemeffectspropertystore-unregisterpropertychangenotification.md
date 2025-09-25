## Description

Unregisters an [IAudioSystemEffectsPropertyChangeNotificationClient](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-iaudiosystemeffectspropertychangenotificationclient) callback interface previously registered to receive notifications when audio system effect properties change.

## Parameters

### `callback`

A pointer to the **IAudioSystemEffectsPropertyChangeNotificationClient** callback interface to unregister.

## Return value

Returns S_OK on success.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also