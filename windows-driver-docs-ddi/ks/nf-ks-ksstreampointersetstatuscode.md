# KsStreamPointerSetStatusCode function

## Description

The **KsStreamPointerSetStatusCode** function allows specification of a successful or unsuccessful error code with which to complete the given IRP.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure. This pointer points to the frame contained in the IRP.

### `Status` [in]

The error code with which to complete the IRP.

## Return value

**KsStreamPointerSetStatusCode** returns STATUS_SUCCESS if the IRP is completed with the requested status code. Otherwise, it returns an appropriate error code.

## Remarks

Note that the IRP contains the frame to which *StreamPointer* points.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)