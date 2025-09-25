# IMiniportWavePciStream::NormalizePhysicalPosition

## Description

The `NormalizePhysicalPosition` method converts a physical buffer position to a time-based value.

## Parameters

### `PhysicalPosition` [in, out]

Pointer to a caller-allocated buffer that contains either the physical position or time-based value. On entry, this buffer contains the physical-position value that is to be converted. On return, the buffer contains the converted value, which is time-based.

## Return value

`NormalizePhysicalPosition` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

Given a physical position based on the actual number of bytes transferred, the `NormalizePhysicalPosition` method converts the position to a time-based value that is expressed in 100-nanosecond units.