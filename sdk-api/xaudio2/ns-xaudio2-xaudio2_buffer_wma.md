# XAUDIO2_BUFFER_WMA structure

## Description

Used with [IXAudio2SourceVoice::SubmitSourceBuffer](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-submitsourcebuffer) when submitting xWMA data.

## Members

### `pDecodedPacketCumulativeBytes`

Decoded packet cumulative data size array, each element is the number of bytes accumulated after the corresponding xWMA packet is decoded in order, must have **PacketCount** elements.

### `PacketCount`

Number of xWMA packets submitted, must be >= 1 and divide evenly into the respective [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer).**AudioBytes** value passed to [IXAudio2SourceVoice::SubmitSourceBuffer](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-submitsourcebuffer).

## Remarks

When streaming an xWMA file a few packets at a time, XAUDIO2_END_OF_STREAM should be specified on the last packet. Alternatively, the application may call [IXAudio2SourceVoice::Discontinuity](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-discontinuity) after submitting the last packet.

In addition, when streaming an xWMA file a few packets at a time, the application should subtract **pDecodedPacketCumulativeBytes**[**PacketCount**-1] of the previous packet from all the entries of the currently submitted packet.

The members of **XAUDIO2_BUFFER_WMA** correspond to values contained in the 'dpds' RIFF chunk of the xWMA file being played. **PacketCount** will correspond to the size in UINT32s of the chunk. **pDecodedPacketCumulativeBytes** will correspond to a UINT32 buffer containing the contents of the chunk. The contents of the buffer will need to be byte swapped when loading the buffer on Xbox 360.

Memory allocated to hold a [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) or **XAUDIO2_BUFFER_WMA** structure can be freed as soon as the [IXAudio2SourceVoice::SubmitSourceBuffer](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-submitsourcebuffer) call it is passed to returns. The data the structure points to (**pAudioData** and **pDecodedPacketCumulativeBytes**, respectively) can't be freed until the buffer completes (as signaled by the [IXAudio2VoiceCallback::OnBufferEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onbufferend) callback) or the voice is stopped and destroyed.

XAUDIO 2.8 in Windows 8.x does not support xWMA decoding. Use Windows Media Foundation APIs to perform the decoding from WMA to PCM instead. This functionality is available in the DirectX SDK versions of XAUDIO and in XAUDIO 2.9 in Windows 10.

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)