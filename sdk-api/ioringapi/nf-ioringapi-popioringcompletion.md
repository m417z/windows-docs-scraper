## Description

Pops a single entry from the completion queue, if one is available.

## Parameters

### `ioRing`

An **HIORING** representing a handle to the I/O ring from which an entry from the completion queue is popped.

### `cqe`

Pointer to an [IORING_CQE](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_cqe) structure that will recieve the data for the completed queue entry.

## Return value

Returns an HRESULT including, but not limitted to the following:

| Value | Description |
|-------|-------------|
| S_OK | The entry was popped from the queue and the **IORING_CQE** pointed to by *cqe* contains the values from the entry. |
| S_FALSE | The completion queue is empty, and the data pointed to by the *cqe* parameter is unmodified. |

## Remarks

## See also