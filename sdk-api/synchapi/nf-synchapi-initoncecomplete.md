# InitOnceComplete function

## Description

Completes one-time initialization started with the [InitOnceBeginInitialize](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initoncebegininitialize) function.

## Parameters

### `lpInitOnce` [in, out]

A pointer to the one-time initialization structure.

### `dwFlags` [in]

This parameter can be one of the following flags.

| Value | Meaning |
| --- | --- |
| **INIT_ONCE_ASYNC**<br><br>0x00000002UL | Operate in asynchronous mode. This enables multiple completion attempts to execute in parallel. This flag must match the flag passed in the corresponding call to the [InitOnceBeginInitialize](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initoncebegininitialize) function. This flag may not be combined with **INIT_ONCE_INIT_FAILED**. |
| **INIT_ONCE_INIT_FAILED**<br><br>0x00000004UL | The initialization attempt failed. This flag may not be combined with **INIT_ONCE_ASYNC**. To fail an asynchronous initialization, merely abandon it (that is, do not call the **InitOnceComplete** function). |

### `lpContext` [in, optional]

A pointer to the data to be stored with the one-time initialization structure. This data is returned in the *lpContext* parameter passed to subsequent calls to the [InitOnceBeginInitialize](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initoncebegininitialize) function. If *lpContext* points to a value, the low-order **INIT_ONCE_CTX_RESERVED_BITS** of the value must be zero. If *lpContext* points to a data structure, the data structure must be **DWORD**-aligned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example that uses
this function, see
[Using One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/using-one-time-initialization).

## See also

[InitOnceBeginInitialize](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initoncebegininitialize)

[One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/one-time-initialization)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)