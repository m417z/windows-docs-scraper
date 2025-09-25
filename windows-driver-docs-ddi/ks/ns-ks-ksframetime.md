# KSFRAMETIME structure

## Description

The KSFRAMETIME structure is supported by rendering pins, and is used to return the duration of the next frame of data, and flags associated with that frame.

## Members

### `Duration`

Specifies the duration in presentation time units.

### `FrameFlags`

Specifies the flags specific to the next frame, or to all frames. Flags are described on the reference page for [KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing).

### `Reserved`

Set to zero.

## Remarks

Note that this is an optional property, which need only be implemented if the pin instance understands the specifics of the media type it is transporting.