## Description

This routine returns the exit status for a given thread.

## Parameters

### `Thread` [in]

A pointer to an executive thread object structure (ETHREAD).

## Return value

If the thread is being or has been deleted, this routine returns the exit status of the thread. This can be any valid NTSTATUS code depending on how the thread was terminated, including STATUS_SUCCESS if the call is successful or an appropriate error status code if the thread was terminated due to an error.

If the thread is still active and not being deleted, this routine returns STATUS_PENDING.

## Remarks

## See also