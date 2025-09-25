# IXAudio2SourceVoice::Discontinuity

## Description

Notifies an XAudio2 voice that no more buffers are coming after the last one that is currently in its queue.

## Return value

Returns S_OK if successful, an error code otherwise.

## Remarks

**Discontinuity** suppresses the warnings that normally occur in the debug build of XAudio2 when a voice runs out of audio buffers to play. It is preferable to mark the final buffer of a stream by tagging it with the XAUDIO2_END_OF_STREAM flag, but in some cases the client may not know that a buffer is the end of a stream until after the buffer has been submitted.

Because calling **Discontinuity** is equivalent to applying the XAUDIO2_END_OF_STREAM flag retroactively to the last buffer submitted, an [OnStreamEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onstreamend) callback will be made when this buffer completes.

**Note** XAudio2 may consume its entire buffer queue and emit a warning before the **Discontinuity** call takes effect, so **Discontinuity** is not guaranteed to suppress the warnings.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)