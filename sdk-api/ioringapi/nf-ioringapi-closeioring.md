## Description

Closes an **HIORING** handle that was previously opened with a call to [CreateIoRing](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-createioring).

## Parameters

### `ioRing`

The **HIORING** handle to close.

## Return value

Returns S_OK on success.

## Remarks

Calling this function ensures that resources allocated for the I/O ring are released. The closed handle is no longer valid after the function returns. It is important to note that closing the handle abandons the operations that are queued but not submitted. However, the operations that are in flight are **not** cancelled.

It is possible that reads from or writes to memory buffers may still occur after **CloseIoRing** returns. If you want to ensure that no pending reads or writes occur, you must wait for the completions to appear in the completion queue for all the operations that are submitted. You may choose to cancel the previously submitted operations before waiting on their completions. As an alternative to submitting multiple cancel requests, you can call [CancelIoEx](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-cancelioex) with the file handle and NULL for the overlapped pointer to effectively cancel all pending operations on the handle.

## See also