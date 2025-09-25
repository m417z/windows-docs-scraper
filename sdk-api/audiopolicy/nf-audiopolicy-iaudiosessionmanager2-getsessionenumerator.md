# IAudioSessionManager2::GetSessionEnumerator

## Description

The **GetSessionEnumerator** method gets a pointer to the audio session enumerator object.

## Parameters

### `SessionEnum` [out]

Receives a pointer to the [IAudioSessionEnumerator](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionenumerator) interface of the session enumerator object that the client can use to enumerate audio sessions on the audio device. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method.

## Return value

If the method succeeds, it returns S_OK.

## Remarks

The session manager maintains a collection of audio sessions that are active on the audio device by querying the audio engine. **GetSessionEnumerator** creates a session control for each session in the collection. To get a reference to the [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol) interface of the session in the enumerated collection, the application must call [IAudioSessionEnumerator::GetSession](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol2-getsessionidentifier). For a code example, see [IAudioSessionEnumerator Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionenumerator).

The session enumerator might not be aware of the new sessions that are reported through [IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification). So if an application exclusively relies on the session enumerator for getting all the sessions for an audio endpoint, the results might not be accurate. To work around this, the application should manually maintain a list. For more information, see [IAudioSessionEnumerator](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionenumerator).

## See also

[IAudioSessionManager2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager2)