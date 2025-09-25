# XAPO_BUFFER_FLAGS enumeration

## Description

Describes the contents of a stream buffer.

## Constants

### `XAPO_BUFFER_SILENT`

Stream buffer contains only silent samples.

### `XAPO_BUFFER_VALID`

Stream buffer contains audio data to be processed.

## Remarks

This metadata can be used to implement optimizations that require knowledge of a stream buffer's contents. For example, XAPOs that always produce silent output from silent input can check the flag on the input stream buffer to determine if any signal processing is necessary. If silent, the XAPO can simply set the flag on the output stream buffer to silent and return, thus averting the work of processing silent data.

Likewise, XAPOs that receive valid input data, but generate silence (for any reason), may set the output stream buffer's flag accordingly, rather than writing silent samples to the buffer.

These flags represent what should be assumed is in the respective buffer. The flags may not reflect what is actually stored in memory. For example, the XAPO_BUFFER_SILENT indicates that silent data should be assumed, however the respective memory may be uninitialized

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Enumerations](https://learn.microsoft.com/windows/desktop/xaudio2/enumerations)