## Description

The **PeerDistGetOverlappedResult** function retrieves the results of asynchronous operations. This function replaces the [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function for Peer Distribution asynchronous operations.

## Parameters

### `lpOverlapped` [in]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that was specified when the overlapped operation was started.

### `lpNumberOfBytesTransferred` [out]

A pointer to a variable that receives the number of bytes that were actually transferred by a read or write operation.

### `bWait` [in]

If this parameter is `true`, the function does not return until the operation has been completed. If this parameter is `false` and the operation is still pending, the function returns `false`.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`true` if the operation has completed. `false` if the *bWait* argument is `false` and the operation is still pending.