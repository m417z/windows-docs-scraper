# IMiniportWaveCyclicStream::Silence

## Description

The `Silence` method is used to copy silence samples to a specified buffer.

## Parameters

### `Buffer` [in,out]

Pointer in kernel virtual-address space to the start of the buffer to which the silence samples are to be written. The buffer must be large enough to contain at least the number of bytes specified in *ByteCount*.

### `ByteCount` [in]

Specifies the number of bytes of silence to be written to the buffer.

## Remarks

Windows treats 8-bit PCM values as unsigned, and it treats 16-bit and larger PCM values as signed. When filling a portion of an 8-bit PCM buffer with silence, the `Silence` method sets each byte to the value 0x80. When writing silence to a buffer containing 16-bit or larger PCM values, the method fills the specified portion of the buffer with zeros.