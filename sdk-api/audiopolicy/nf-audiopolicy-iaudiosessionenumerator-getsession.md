# IAudioSessionEnumerator::GetSession

## Description

The **GetSession** method gets the audio session specified by an audio session number.

## Parameters

### `SessionCount` [in]

The session number. If there are *n* sessions, the sessions are numbered from 0 to *n* – 1. To get the number of sessions, call the [IAudioSessionEnumerator::GetCount](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionenumerator-getcount) method.

### `Session` [out]

Receives a pointer to the [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol) interface of the session object in the collection that is maintained by the session enumerator. The caller must release the interface pointer.

## Return value

If the method succeeds, it returns S_OK.

## See also

[IAudioSessionEnumerator](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionenumerator)