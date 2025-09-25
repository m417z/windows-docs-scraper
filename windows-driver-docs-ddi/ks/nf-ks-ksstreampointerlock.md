# KsStreamPointerLock function

## Description

The **KsStreamPointerLock** function attempts to lock the specified stream pointer.

## Parameters

### `StreamPointer` [in]

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the stream pointer to attempt to lock.

## Return value

**KsStreamPointerLock** returns either STATUS_SUCCESS, indicating that the stream pointer has been locked, or an appropriate error code. STATUS_DEVICE_NOT_READY is the usual error code indicating that the frame could not be locked. This error code frequently means that the frame to which *StreamPointer* was pointing was canceled.

## Remarks

A locked stream pointer guarantees that there is a data frame associated with the stream pointer and that this frame is not canceled as long as the lock is maintained. The minidriver should lock a stream pointer before attempting to access the data to which the stream pointer points.

If the pin that the stream pointer references specifies that DMA scatter/gather mappings should be generated using KSPIN_FLAG_GENERATE_MAPPINGS, AVStream generates the mappings when the stream pointer is locked.

Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock)