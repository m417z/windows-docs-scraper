# InitOnceBeginInitialize function

## Description

Begins one-time initialization.

## Parameters

### `lpInitOnce` [in, out]

A pointer to the one-time initialization structure.

### `dwFlags` [in]

This parameter can have a value of 0, or one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **INIT_ONCE_ASYNC**<br><br>0x00000002UL | Enables multiple initialization attempts to execute in parallel. If this flag is used, subsequent calls to this function will fail unless this flag is also specified. |
| **INIT_ONCE_CHECK_ONLY**<br><br>0x00000001UL | This function call does not begin initialization. The return value indicates whether initialization has already completed. If the function returns **TRUE**, the *lpContext* parameter receives the data. |

### `fPending` [out]

If the function succeeds, this parameter indicates the current initialization status.

If this parameter is **TRUE** and *dwFlags* contains **INIT_ONCE_CHECK_ONLY**, the initialization is pending and the context data is invalid.

If this parameter is **FALSE**, initialization has already completed and the caller can retrieve the context data from the *lpContext* parameter.

If this parameter is **TRUE** and *dwFlags* does not contain **INIT_ONCE_CHECK_ONLY**, initialization has been started and the caller can perform the initialization tasks.

### `lpContext` [out, optional]

An optional parameter that receives the data stored with the one-time initialization structure upon success. The low-order **INIT_ONCE_CTX_RESERVED_BITS** bits of the data are always zero.

## Return value

If **INIT_ONCE_CHECK_ONLY** is not specified and the function succeeds, the return value is **TRUE**.

If **INIT_ONCE_CHECK_ONLY** is specified and initialization has completed, the return value is **TRUE**.

Otherwise, the return value is **FALSE**.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function can be used for either synchronous or asynchronous one-time initialization. For asynchronous one-time initialization, use the **INIT_ONCE_ASYNC** flag. To specify a callback function to execute during synchronous one-time initialization, see the [InitOnceExecuteOnce](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initonceexecuteonce) function.

If this function succeeds, the thread can create a synchronization object and specify in the *lpContext* parameter of the [InitOnceComplete](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initoncecomplete) function.

To compile an application that uses this function, define **\_WIN32_WINNT** as 0x0600 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

A one-time initialization object cannot be moved or copied. The process must not modify the initialization object, and must instead treat it as logically opaque. Only use the one-time initialization functions to manage one-time initialization objects.

#### Examples

For an example that uses this function, see [Using One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/using-one-time-initialization)

## See also

[InitOnceComplete](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initoncecomplete)

[InitOnceExecuteOnce](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initonceexecuteonce)

[One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/one-time-initialization)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)