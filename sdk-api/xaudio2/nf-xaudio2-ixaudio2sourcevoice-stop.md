# IXAudio2SourceVoice::Stop

## Description

Stops consumption of audio by the current voice.

## Parameters

### `X2DEFAULT`

TBD

### `Flags` [in]

Flags that control how the voice is stopped. Can be 0 or the following:

| Value | Description |
| --- | --- |
| XAUDIO2_PLAY_TAILS | Continue emitting effect output after the voice is stopped. |

### `OperationSet` [in]

Identifies this call as part of a deferred batch. See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview for more information.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

All source buffers that are queued on the voice and the current cursor position are preserved. This allows the voice to continue from where it left off, when it is restarted. The [IXAudio2SourceVoice::FlushSourceBuffers](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-flushsourcebuffers) method can be used to flush queued source buffers.

By default, any pending output from voice effects—for example, reverb tails—is not played. Instead, the voice is immediately rendered silent. The XAUDIO2_PLAY_TAILS flag can be used to continue emitting effect output after the voice stops running.

A voice stopped with the XAUDIO2_PLAY_TAILS flag stops consuming source buffers, but continues to process its effects and send audio to its destination voices. A voice in this state can later be stopped completely by calling **Stop** again with the Flags argument set to 0. This enables stopping a voice with XAUDIO2_PLAY_TAILS, waiting sufficient time for any audio being produced by its effects to finish, and then fully stopping the voice by calling **Stop** again without XAUDIO2_PLAY_TAILS. This technique allows voices with effects to be stopped gracefully while ensuring idle voices will not continue to be processed after they have finished producing audio.

**Stop** is always asynchronous, even if called within a callback.

**Note** XAudio2 never calls any voice callbacks for a voice if the voice is stopped (even if it was stopped with XAUDIO2_PLAY_TAILS).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)