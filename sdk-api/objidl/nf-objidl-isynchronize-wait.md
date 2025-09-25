# ISynchronize::Wait

## Description

Waits for the synchronization object to be signaled or for a specified timeout period to elapse, whichever comes first.

## Parameters

### `dwFlags` [in]

The wait options. Possible values are taken from the [COWAIT_FLAGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-cowait_flags) enumeration.

### `dwMilliseconds` [in]

The time this call will wait before returning, in milliseconds. If this parameter is INFINITE, the caller will wait until the synchronization object is signaled, no matter how long it takes. If this parameter is 0, the method returns immediately.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The synchronization object was signaled. |
| **RPC_S_CALLPENDING** | The time-out period elapsed before the synchronization object was signaled. |
| **RPC_E_NO_SYNC** | There is no synchronization object to wait on. |

## Remarks

If the caller is waiting in a single-thread apartment, **Wait** enters the COM modal loop. If the caller is waiting in a multithread apartment, the caller is blocked until **Wait** returns.

## See also

[CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles)

[ISynchronize](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isynchronize)