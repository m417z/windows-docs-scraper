## Description

Queries the OS for the supported capabilities for I/O rings.

## Parameters

### `capabilities`

Receives a pointer to an [IORING_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_capabilities) representing the I/O ring API capabilities.

## Return value

S_OK on success.

## Remarks

The results of this call are internally cached per-process, so this is efficient to call multiple times as only the first will transition to the kernel to retrieve the data.Note that the results are not guaranteed to contain the same values between runs of the same process or even between processes on the same system. So applications should not store this information beyond the lifetime of the process and should not assume that other processes have the same support.

## See also