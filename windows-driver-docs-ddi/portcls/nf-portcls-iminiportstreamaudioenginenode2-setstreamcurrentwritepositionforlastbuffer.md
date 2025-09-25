# IMiniportStreamAudioEngineNode2::SetStreamCurrentWritePositionForLastBuffer

## Description

Sets the current cursor position in the last audio data stream that was written to the audio buffer.

## Parameters

### `_ulWritePosition` [in]

The current cursor position in the last audio data stream.

## Return value

**SetStreamCurrentWritePositionForLastBuffer** returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

When a client app performs the very last write operation to the audio buffer to be processed by the audio driver of an offloaded stream, the audio driver calls **SetStreamCurrentWritePositionForLastBuffer**. The **SetStreamCurrentWritePositionForLastBuffer** method indicates the “write position” of the very last buffer in a stream. Note that this last buffer could be only partially filled.

If the buffer is only partially filled, then the audio driver needs to notify the audio engine when the last valid byte in the buffer has been *rendered*. This differs from the normal functionality where the audio driver notified the audio engine when the driver *fetched* the last byte in the buffer.

## See also

[IMiniportStreamAudioEngineNode2](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode2)

[KSPROPERTY_AUDIO_WAVERT_CURRENT_WRITE_LASTBUFFER_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-wavert-current-write-lastbuffer-position)