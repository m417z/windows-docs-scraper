# IMiniportWavePciStream::GetPosition

## Description

The `GetPosition` method gets the current position of the stream.

## Parameters

### `Position` [out]

Output pointer for the position value. This parameter points to a caller-allocated ULONGLONG variable into which the method writes the current byte position of the stream.

## Return value

`GetPosition` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The position indicated by the `GetPosition` method is expressed as a byte offset from the beginning of the stream. It represents the miniport driver's best estimate of the byte position of the data currently in the DAC or ADC. The miniport object is required to maintain stream position based on the mappings it acquires, regardless of whether mappings are released or revoked.

The position is zero immediately following initialization of the stream. A transition to the KSSTATE_STOP state (see [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)) resets the position to zero. When the stream is halted by a transition from KSSTATE_RUN to KSSTATE_PAUSE or KSSTATE_ACQUIRE, the position freezes. It unfreezes when the stream transitions from KSSTATE_PAUSE or KSSTATE_ACQUIRE back to KSSTATE_RUN.

The position reported by `GetPosition` is not an offset into any one physical buffer that either your driver has allocated or a client has allocated. Instead, the offset is stream-relative and can be thought of as an offset into an idealized buffer that contains the entire stream and is contiguous from beginning to end. Any internal offsets that point into the actual physical buffers that contain the data need to be maintained separately.

Note that the offset value retrieved by a `GetPosition` call is one of the following:

* For a render stream, the `GetPosition` method retrieves the *play position*, which is the byte offset of the sample that is currently being played through the DAC and transmitted through the speaker jack.
* For a capture stream, the `GetPosition` method retrieves the *record position*, which is the byte offset of the latest sample to be received through the microphone jack and captured by the ADC.

It is not the offset of the sample that the DMA engine in the audio device is currently reading from or writing to the audio buffer.

Some audio hardware contains a position register to keep track of the byte offset of the sample currently in each DAC or ADC, in which case the `GetPosition` method simply retrieves the contents of the position register for the appropriate stream. Other audio hardware can only supply the driver with DMA pointers into the audio buffers, in which case the `GetPosition` method must provide a best estimate of the byte offset in the DAC or ADC based on the current DMA position and the buffering delays internal to the device.

Audio hardware that internally buffers a portion of a playback or capture stream might make a precise position reading more difficult to obtain. In this case, the driver should estimate the current position as accurately as possible. For example, if an audio device prefetches the playback stream into an internal buffer, the driver might need to take both the buffer size and timing information into account in order to properly estimate the play position.

The WavePci port driver implements a property handler for [KSPROPERTY_AUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-position). This property handler calls the `GetPosition` method to obtain the current play or record position from the miniport driver. For more information, see [Audio Position Property](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-position-property).

## See also

[IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)

[KSPROPERTY_AUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-position)

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)