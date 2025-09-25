# InitOnceExecuteOnce function

## Description

When multiple threads call InitOnceExecuteOnce passing the same one-time initialization block, only one thread will execute the callback function specified by *InitFn*. The remaining threads will block until the callback function completes. If the callback function returns **TRUE** to indicate success, InitOnceExecuteOnce will return **TRUE** back to all callers at once. If, however, the callback returns **FALSE** to indicate failure, InitOnceExecuteOnce will return **FALSE** to only the single thread which executed the callback function. At this same time one of the remaining blocked threads will unblock and execute *InitFn* once again. Thus, in a scenario where *InitFn* can fail intermittently and retries are desired, all threads should continue calling InitOnceExecuteOnce until **TRUE** is returned.

## Parameters

### `InitOnce` [in, out]

A pointer to the one-time initialization structure.

### `InitFn` [in]

A pointer to an application-defined [InitOnceCallback](https://learn.microsoft.com/windows/desktop/api/synchapi/nc-synchapi-pinit_once_fn) function.

### `Parameter` [in, optional]

A parameter to be passed to the callback function.

### `Context` [in, out, optional]

A parameter that receives data stored with the one-time initialization structure upon success. The low-order **INIT_ONCE_CTX_RESERVED_BITS** bits of the data are always zero. If *Context* points to a data structure, the data structure must be **DWORD**-aligned. *Context* must not be a code pointer on Arm32, because Arm32 code pointers always have the least significant bit set, see the [Arm32 ABI](https://learn.microsoft.com/cpp/build/overview-of-arm-abi-conventions?view=msvc-170#instruction-set) for details.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is used for synchronous one-time initialization. For asynchronous one-time initialization, use the [InitOnceBeginInitialize](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initoncebegininitialize) function with the **INIT_ONCE_ASYNC** flag.

Only one thread at a time can execute the callback function specified by *InitFn*. Other threads that specify the same one-time initialization structure block until the callback finishes.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example that uses
this function, see
[Using One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/using-one-time-initialization).

## See also

[InitOnceCallback](https://learn.microsoft.com/windows/desktop/api/synchapi/nc-synchapi-pinit_once_fn)

[InitOnceInitialize](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initonceinitialize)

[One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/one-time-initialization)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)