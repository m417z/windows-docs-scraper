# IMiniportWaveCyclicStream::NormalizePhysicalPosition

## Description

The `NormalizePhysicalPosition` method converts a physical buffer position to a time-based value.

## Parameters

### `PhysicalPosition` [in, out]

Pointer to a caller-allocated variable that contains either the physical position or the time-based value. On entry, this buffer contains the physical-position value to convert. On return, the buffer contains the converted value, which is time-based.

## Return value

`NormalizePhysicalPosition` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

*PhysicalPosition* is both an input and an output parameter. Given a physical position based on the actual number of bytes transferred, `NormalizePhysicalPosition` converts the position to a time-based value of 100-nanosecond units.