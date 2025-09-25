## Description

Unregisters an [IAudioEffectsChangedNotificationClient](https://learn.microsoft.com/windows/win32/api/audioclient/nn-audioclient-iaudioeffectschangednotificationclient) interface.

## Parameters

### `client`

The **IAudioEffectsChangedNotificationClient** interface to unregister.

## Return value

| Value | Description |
|-------|-------------|
| S_OK | Success |
| AUDCLNT_E_DEVICE_INVALIDATED | The associated audio stream has been destroyed. |

## Remarks

Register the callback interface by calling [RegisterAudioEffectsChangedNotificationCallback](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-registeraudioeffectschangednotificationcallback).

## See also