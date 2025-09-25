# IAudioSessionControl2::GetSessionInstanceIdentifier

## Description

The **GetSessionInstanceIdentifier** method retrieves the identifier of the audio session instance.

## Parameters

### `pRetVal` [out]

Pointer to the address of a null-terminated, wide-character string that receives the identifier of a particular instance of the audio session. The string is allocated by this method and must be released by the caller by calling **CoTaskMemFree**. For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK.
If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return value | Description |
| --- | --- |
| E_POINTER | *pRetVal* is **NULL**. |
| AUDCLNT_E_DEVICE_INVALIDATED | The audio session is disconnected on the default audio device. |

## Remarks

 Each audio session instance is identified by a unique string. This string represents a particular instance of the audio session and, unlike the session identifier, is unique across all instances. If there are two
instances of the application playing, they will have different session instance identifiers. The identifier retrieved by **GetSessionInstanceIdentifier** is different from the session identifier, which is shared by all session instances. To get the session identifier, call [IAudioSessionControl2::GetSessionIdentifier](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol2-getsessionidentifier).

**GetSessionInstanceIdentifier** checks whether the session has been disconnected on the default device. It retrieves the identifier string that is cached by the audio client for the device. If the session instance identifier is not found, this method retrieves it from the audio engine. For example code about getting a session instance identifier, see [Getting Ducking Events from a Communication Device](https://learn.microsoft.com/windows/desktop/CoreAudio/getting-ducking-events-from-a-communication-device).

## See also

[IAudioSessionControl2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol2)

[Using a Communication Device](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-communication-device)