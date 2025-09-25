# CoWaitForMultipleHandles function

## Description

Waits for specified handles to be signaled or for a specified timeout period to elapse.

## Parameters

### `dwFlags` [in]

The wait options. Possible values are taken from the [COWAIT_FLAGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-cowait_flags) enumeration.

### `dwTimeout` [in]

The timeout period, in milliseconds.

### `cHandles` [in]

The number of elements in the *pHandles* array.

### `pHandles` [in]

An array of handles.

### `lpdwindex` [out]

A pointer to a variable that, when the returned status is S_OK, receives a value indicating the event that caused the function to return. This value is usually the index into *pHandles* for the handle that was signaled.

If *pHandles* includes one or more handles to mutex objects, a value between WAIT_ABANDONED_0 and (WAIT_ABANDONED_0 + nCount - 1) indicates the index into *pHandles* for the mutex that was abandoned.

If the [COWAIT_ALERTABLE](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-cowait_flags) flag is set in *dwFlags*, a value of WAIT_IO_COMPLETION indicates the wait was ended by one or more user-mode asynchronous procedure calls (APC) queued to the thread.

See [WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex) for more information.

## Return value

This function can return the following values.

**Note** The return value of **CoWaitForMultipleHandles** can be nondeterministic if the [COWAIT_ALERTABLE](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-cowait_flags) flag is set in *dwFlags*, or if *pHandles* includes one or more handles to mutex objects. The recommended workaround is to call [SetLastError(ERROR_SUCCESS)](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) before **CoWaitForMultipleHandles**.

| Return code | Description |
| --- | --- |
| **S_OK** | The required handle or handles were signaled. |
| **E_INVALIDARG** | *pHandles* was **NULL**, *lpdwindex* was **NULL**, or *dwFlags* was not a value from the [COWAIT_FLAGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-cowait_flags) enumeration. |
| **RPC_E_NO_SYNC** | The value of *pHandles* was 0. |
| **RPC_S_CALLPENDING** | The timeout period elapsed before the required handle or handles were signaled. |

## Remarks

Depending on which flags are set in the dwFlags parameter, **CoWaitForMultipleHandles** blocks the calling thread until one of the following events occurs:

* One or all of the handles is signaled. In the case of mutex objects, this condition is also satisfied by a mutex being abandoned.
* An asynchronous procedure call (APC) has been queued to the calling thread with a call to the [QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc) function.
* The timeout period expires.

If the caller resides in a single-thread apartment, **CoWaitForMultipleHandles** enters the COM modal loop, and the thread's message loop will continue to dispatch messages using the thread's message filter. If no message filter is registered for the thread, the default COM message processing is used.

If the calling thread resides in a multithread apartment (MTA), **CoWaitForMultipleHandles** calls the [WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex) function.

## See also

[COWAIT_FLAGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-cowait_flags)