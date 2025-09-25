# IAudioSessionControl2::GetSessionIdentifier

## Description

The **GetSessionIdentifier** method retrieves the audio session identifier.

## Parameters

### `pRetVal` [out]

Pointer to the address of a null-terminated, wide-character string that receives the audio session identifier. The string is allocated by this method and must be released by the caller by calling **CoTaskMemFree**. For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK.
If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return value | Description |
| --- | --- |
| E_POINTER | *pRetVal* is **NULL**. |
| AUDCLNT_E_DEVICE_INVALIDATED | The audio session is disconnected on the default audio device. |

## Remarks

 Each audio session is identified by an identifier string. This session identifier string is not unique across all instances. If there are two
instances of the application playing, both instances will have the same session identifier. The identifier retrieved by **GetSessionIdentifier** is different from the session instance identifier, which is unique across all sessions. To get the session instance identifier, call [IAudioSessionControl2::GetSessionInstanceIdentifier](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol2-getsessioninstanceidentifier).

**GetSessionIdentifier** checks whether the session has been disconnected on the default device. It retrieves the identifier string that is cached by the audio client for the device. If the session identifier is not found, this method retrieves it from the audio engine.

## See also

[IAudioSessionControl2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol2)