## Description

Creates a new instance of an I/O ring submission/completion queue pair and returns a handle for referencing the IORING.

## Parameters

### `ioringVersion`

A UNIT32 representing the version of the I/O ring API the ring is created for. This value must be less than or equal to the value retrieved from a call to [QueryIoRingCapabilities](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-queryioringcapabilities)

### `flags`

A value from the [IORING_CREATE_FLAGS](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_create_flags) enumeration specifying creation flags.

### `submissionQueueSize`

The requested minimum submission queue size. The system may round up the size as needed to ensure the actual size is a power of 2. You can get the actual allocated queue size by calling [GetIoRingInfo](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-getioringinfo). You can get the maximum submission queue size on the current system by calling [QueryIoRingCapabilities](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-queryioringcapabilities).

### `completionQueueSize`

The requested minimum size of the completion queue. The system will round this size up to a power of two that is no less than two times the actual submission queue size to allow for submissions while some operations are still in progress. You can get the actual allocated queue size by calling [GetIoRingInfo](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-getioringinfo).

### `h`

Receives the resulting **HIORING** handle, if creation was successful. The returned **HIORING** ring must be closed by calling [CloseIoRing](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-closeioring), not [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle), to release the underlying resources for the IORING.

## Return value

An HRESULT, including but not limited to the following:

| Value | Description |
|-------|-------------|
| S_OK | Success. |
| IORING_E_UNKNOWN_VERSION | The version specified in *ioringVersion* is unknown. |

## Remarks

## See also