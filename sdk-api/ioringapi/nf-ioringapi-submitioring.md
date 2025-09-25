## Description

Submits all constructed but not yet submitted entries to the kernel’s queue and optionally waits for a set of operations to complete.

## Parameters

### `ioRing`

An **HIORING** representing a handle to the I/O ring for which entries will be submitted.

### `waitOperations`

The number of completion queue entries to wait for. Specifying 0 indicates that the call should not wait. This value must be less than the sum of the number of entries in the submission queue and the number of operations currently in progress.

### `milliseconds`

The number of milliseconds to wait for the operations to complete. Specify **INFINITE** to wait indefinitely. This value is ignored if 0 is specified for *waitOperations*.

### `submittedEntries`

Optional. Receives a pointer to an array of **UINT_32** values representing the number of entries submitted.

## Return value

Returns an HRESULT including, but not limited to, one of the following:

| Value | Description |
|-------|-------------|
| S_OK | All entries in the queue were submitted without error. |
| IORING_E_WAIT_TIMEOUT | All operations were submitted without error and the subsequent wait timed out. |
| Any other error value | Failure to process the submission queue in its entirety. |

## Remarks

If this function returns an error other than IORING_E_WAIT_TIMEOUT, then all entries remain in the submission queue. Any errors processing a single submission queue entry results in a synchronous completion of that entry posted to the completion queue with an error status code for that operation.

## See also