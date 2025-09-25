# XAPO_PROCESS_BUFFER_PARAMETERS structure

## Description

Defines stream buffer parameters that may change from one call to the next. Used with the [Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) method.

## Members

### `pBuffer`

Pointer to a stream buffer that contains audio data. The buffer must be 16-byte aligned, non-NULL, and must be at least [XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS](https://learn.microsoft.com/windows/win32/api/xapo/ns-xapo-xapo_lockforprocess_parameters).MaxFrameCount frames in size.

### `BufferFlags`

An [XAPO_BUFFER_FLAGS](https://learn.microsoft.com/windows/desktop/api/xapo/ne-xapo-xapo_buffer_flags) enumeration describing the contents of the stream buffer.

### `ValidFrameCount`

Number of frames to process; this value must be within the range 0 to [XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS](https://learn.microsoft.com/windows/win32/api/xapo/ns-xapo-xapo_lockforprocess_parameters).MaxFrameCount.

## Remarks

Although the format and maximum size values of a particular stream buffer are constant, as defined by the [XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS](https://learn.microsoft.com/windows/win32/api/xapo/ns-xapo-xapo_lockforprocess_parameters) structure, the actual memory address of the stream buffer is permitted to change. For constant-bit-rate (CBR) XAPOs, ValidFrameCount is constant and is always equal to the corresponding **XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS**.MaxFrameCount for this buffer.

**Note** Only constant-bit-rate XAPOs are currently supported.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)