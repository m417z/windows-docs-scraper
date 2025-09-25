## Description

Represents the shape and version information for the specified I/O ring.

## Members

### `IoRingVersion`

A [IORING_VERSION](https://learn.microsoft.com/windows/win32/api/ntioring_x/ne-ntioring_x-ioring_version) structure representing the API version of the associated I/O ring.

### `Flags`

A [IORING_CREATE_FLAGS](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_create_flags) structure containing the creation flags with which the associated I/O ring.

### `SubmissionQueueSize`

The actual minimum submission queue size. The system may round up the value requested in the call to [CreateIoRing](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-createioring) as needed to ensure the actual size is a power of 2.

### `CompletionQueueSize`

The actual minimum size of the completion queue. The system will round up the value requested in the call to **CreateIoRing** to a power of two that is no less than two times the actual submission queue size to allow for submissions while some operations are still in progress.

## Remarks

## See also