# KSAUDIO_POSITION structure

## Description

The KSAUDIO_POSITION structure specifies the current positions of the play and write cursors in the sound buffer for an audio stream.

## Members

### `PlayOffset`

Specifies the current play position as a byte offset.

### `WriteOffset`

Specifies the current write position as a byte offset.

## Remarks

This structure is used to get and set the data value for the [KSPROPERTY_AUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-position) property.

For a looped client buffer (with stream type [KSINTERFACE_STANDARD_LOOPED_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/ksinterface-standard-looped-streaming)), **PlayOffset** and **WriteOffset** are byte offsets into the client buffer. When either offset reaches the end of the buffer, it wraps around to the start of the buffer. Hence, neither offset ever exceeds the buffer size.

For a nonlooped client buffer (with stream type [KSINTERFACE_STANDARD_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/ksinterface-standard-streaming)), **PlayOffset** and **WriteOffset** are not offsets into any one physical buffer that either your driver has allocated or a client has allocated. Instead, these offsets are stream-relative and can be thought of as offsets into an idealized buffer that contains the entire stream and is contiguous from beginning to end. Any internal offsets that point into the actual physical buffers that contain the data need to be maintained separately.

During playback, the **PlayOffset** and **WriteOffset** values are interpreted as follows:

* **PlayOffset** is the offset of the last byte in the buffer that has played. **PlayOffset** + 1 is the offset of the next byte that will play.
* **WriteOffset** is the offset of the last byte in the playback buffer.

When a client submits another buffer to the device for playback, **WriteOffset** will increment upon receipt of that buffer to indicate the new **WriteOffset** value, but **PlayOffset** does not change until after that buffer has actually been played by the device.

During recording, the **PlayOffset** and **WriteOffset** values are interpreted as follows:

* **PlayOffset** is the offset of the last byte in the buffer that has been captured. **PlayOffset** + 1 is the offset of the next byte that will be captured.
* **WriteOffset** is the offset of the last byte in the capture buffer.

When an application submits another buffer to the device for capturing, the **WriteOffset** value will increment upon receipt of that buffer. The **PlayOffset** value will not change until data has actually been captured into the buffer.

The space between **PlayOffset** and **WriteOffset** is considered off-limits to the client because it represents the portion of the client buffer that has already been sent to the driver and might still be in use by the driver.

For more information, see [Audio Position Property](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-position-property).

## See also

[KSINTERFACE_STANDARD_LOOPED_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/ksinterface-standard-looped-streaming)

[KSINTERFACE_STANDARD_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/ksinterface-standard-streaming)

[KSPROPERTY_AUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-position)