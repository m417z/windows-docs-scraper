# _AVCSTRM_BUFFER_STRUCT structure

## Description

The AVCSTRM_BUFFER_STRUCT structure describes a buffer to be submitted to *avcstrm.sys* for read or write operations.

## Members

### `ClockProvider`

Indicates whether the subunit driver itself serves as a clock provider. This is **TRUE** if this stream also serves as a clock provider, Otherwise, this is **FALSE**.

### `ClockHandle`

Specifies a handle to a clock provider other than the subunit driver itself.

### `StreamHeader`

Pointer to a kernel streaming header that describes a packet of data to be read from or written to a streaming driver pin.

### `FrameBuffer`

Pointer to a nonpaged system-space virtual address for the buffer described by the MDL.

### `Context`

Pointer to a client context value.

## See also

[KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header)