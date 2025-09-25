# IAudioSessionControl2::GetProcessId

## Description

The **GetProcessId** method retrieves the process identifier of the audio session.

## Parameters

### `pRetVal` [out]

Pointer to a **DWORD** variable that receives the process identifier of the audio session.

## Return value

If the method succeeds, it returns S_OK.
If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return value | Description |
| --- | --- |
| E_POINTER | *pRetVal* is **NULL**. |
| AUDCLNT_S_NO_SINGLE_PROCESS | The session spans more than one process. In this case, *pRetVal* receives the initial identifier of the process that created the session. To use this value , include the following definition:<br><br>`#define AUDCLNT_S_NO_SINGLE_PROCESS AUDCLNT_SUCCESS (0x00d)` |
| AUDCLNT_E_DEVICE_INVALIDATED | The audio session is disconnected on the default audio device. |

## Remarks

This method overwrites the value that was passed by the application in *pRetVal*.

**GetProcessId** checks whether the audio session has been disconnected on the default device or if the session has switched to another stream. In the case of stream
switching, this method transfers state information for the new stream to the session. State information includes volume controls, metadata information (display name, icon path), and the session's property store.

## See also

[IAudioSessionControl2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol2)