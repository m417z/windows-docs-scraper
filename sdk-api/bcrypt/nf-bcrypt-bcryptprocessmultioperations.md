# BCryptProcessMultiOperations function

## Description

The **BCryptProcessMultiOperations** function processes a sequence of operations on a multi-object state.

## Parameters

### `hObject`

*BCRYPT_HANDLE* `[in, out]`

A handle to a multi-object state, such as one created by the [BCryptCreateMultiHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatemultihash) function.

### `operationType`

*BCRYPT_MULTI_OPERATION_TYPE* `[in]`

One of the **BCRYPT_OPERATION_TYPE_**\* values. Currently the only defined value is **BCRYPT_OPERATION_TYPE_HASH**. This value identifies the *hObject* parameter as a multi-hash object and the *pOperations* pointer as pointing to an array of [BCRYPT_MULTI_HASH_OPERATION](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_multi_hash_operation) elements.

### `pOperations`

*PVOID* `[in]`

A pointer to an array of operation command structures. For hashing, it is a pointer to an array of [BCRYPT_MULTI_HASH_OPERATION](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_multi_hash_operation) structures.

### `cbOperations`

*ULONG* `[in]`

The size, in bytes, of the *pOperations* array.

### `dwFlags`

*ULONG* `[in]`

Specify a value of zero (`0`).

## Return value

Returns a status code that indicates the success or failure of the function. If the method succeeds, it will return `STATUS_SUCCESS`. For other **NTSTATUS** values, see [NTSTATUS Values](https://learn.microsoft.com/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55).

## Remarks

Each element of the *pOperations* array contains instructions for a particular computation to be performed on a single element of the multi-object state. The functional behavior of **BCryptProcessMultiOperations** is equivalent to performing, for each element in the multi-object state, the computations specified in the operations array for that element, one at a time, in order.

The relative order of two operations that operate on different elements of the array is not guaranteed. If an output buffer overlaps an input or output buffer the result is not deterministic.

## See also

[BCRYPT_MULTI_HASH_OPERATION](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_multi_hash_operation)

[BCryptCreateMultiHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatemultihash)