# _KSSTREAM_POINTER structure

## Description

The KSSTREAM_POINTER structure is the basic AVStream pointer into a stream.

## Members

### `Context`

A pointer to client-requested context information. The leading edge and trailing edge stream pointers have this member set to **NULL**. Cloned stream pointers can specify that they wish to have context information via the mechanism described in [KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone).

### `Pin`

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure to which this stream pointer belongs.

### `StreamHeader`

A pointer to the stream header object for the data frame that this stream pointer currently points to. See [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) for more information.

### `Offset`

A pointer to a structure of type [KSSTREAM_POINTER_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer_offset). Points to either **OffsetIn** or **OffsetOut** depending on whether the pin to which this stream pointer belongs is an input pin or output pin.

### `OffsetIn`

This member specifies a structure of type [KSSTREAM_POINTER_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer_offset) describing the data currently pointed to by the stream pointer.

### `OffsetOut`

This member specifies a structure of type [KSSTREAM_POINTER_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer_offset). Use this member to output data on an output pin.

## Remarks

A queue object for a stream has at minimum one hard-defined stream pointer: the leading-edge stream pointer. For more information, see [Leading and Trailing Edge Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/leading-and-trailing-edge-stream-pointers).

For general information about stream pointers, see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header)

[KSSTREAM_POINTER_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer_offset)

[KsStreamPointerAdvance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvance)

[KsStreamPointerAdvanceOffsets](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsets)

[KsStreamPointerAdvanceOffsetsAndUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointeradvanceoffsetsandunlock)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)

[KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete)

[KsStreamPointerLock](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerlock)

[KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock)