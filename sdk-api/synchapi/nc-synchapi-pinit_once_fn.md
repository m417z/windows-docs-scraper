# PINIT_ONCE_FN callback function

## Description

An application-defined callback function. Specify a pointer to this function when calling the
[InitOnceExecuteOnce](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initonceexecuteonce) function. The **PINIT_ONCE_FN** type defines a pointer to this callback function.
**InitOnceCallback** is a placeholder for the application-defined function name.

## Parameters

### `InitOnce` [in, out]

A pointer to the one-time initialization structure.

### `Parameter` [in, out, optional]

An optional parameter that was passed to the callback function.

### `Context` [out, optional]

The data to be stored with the one-time initialization structure. If *Context* references a value, the low-order **INIT_ONCE_CTX_RESERVED_BITS** of the value must be zero. If *Context* points to a data structure, the data structure must be **DWORD**-aligned. *Context* must not be a code pointer on Arm32, because Arm32 code pointers always have the least significant bit set, see the [Arm32 ABI](https://learn.microsoft.com/cpp/build/overview-of-arm-abi-conventions?view=msvc-170#instruction-set) for details.

## Return value

If the function returns **TRUE**, the block is marked as initialized.

If the function returns **FALSE**, the block is not marked as initialized and the call to [InitOnceExecuteOnce](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initonceexecuteonce) fails. To communicate additional error information, call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

## Remarks

This function can create a synchronization object and return it in the *lpContext* parameter.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example that uses
this function, see
[Using One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/using-one-time-initialization).

## See also

[InitOnceExecuteOnce](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initonceexecuteonce)

[InitOnceInitialize](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initonceinitialize)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)